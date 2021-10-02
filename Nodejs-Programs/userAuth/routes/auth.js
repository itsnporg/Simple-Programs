const router = require("express").Router();
const User = require("../models/User");
const ROLE = require("../models/ROLE")
const {authUser,authRole}=require('../routes/verifyToken')
const bcrypt = require("bcryptjs");
const jwt = require('jsonwebtoken');
const { registerValidation, loginValidation } = require("../validation");

//User Register Route

router.post("/register", async (req, res) => {
  //Validate data must be a save
  const { error } = registerValidation(req.body);
  if (error) return res.status(400).send(error.details[0].message);

  //If the user already in the DB
  const emailExists = await User.findOne({ email: req.body.email });
  if (emailExists) return res.status(400).send("Email Already Exist!");

  //Hash password
  const salt = await bcrypt.genSalt(10);
  const hashedPassword = await bcrypt.hash(req.body.password, salt);

  //Register New User
  const user = new User({
    fName: req.body.fName,
    lName: req.body.lName,
    email: req.body.email,
    password: hashedPassword,
    mobileNumber: req.body.mobileNumber,
    homeNumber: req.body.homeNumber,
  });

  try {
    const savedUser = await user.save();
    console.log(savedUser);
    res.json(savedUser);
  } catch (err) {
    res.status(400).send(err);
  }
});

//Login
router.post("/login",async (req, res) => {
  //Validate data must be a save
  const { error } = loginValidation(req.body);
  if (error) return res.status(400).send(error.details[0].message);

   //If the user already in the DB
   const user = await User.findOne({ email: req.body.email });
   if (!user) return res.status(400).send("Email is not found!");

   //Check password is correct
   const validPass = await bcrypt.compare(req.body.password,user.password)
   if(!validPass) return res.status(400).send("Invalid Password!")

   //Create and assign a token
   const token = jwt.sign({_id:user._id},process.env.TOKEN_SECRET)
   res.header('auth-token',token).send(token)

//    res.send("Logged in Success!")


});

module.exports = router;
