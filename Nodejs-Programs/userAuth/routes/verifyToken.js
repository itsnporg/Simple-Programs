const jwt = require("jsonwebtoken");

function authUser(req, res, next) {
  const token = req.header("auth-token");
  if (!token) return res.status(401).send("Access Denied!");

  try {
    const verified = jwt.verify(token, process.env.TOKEN_SECRET);
    req.user = verified;
    next();
  } catch (err) {
    res.status(400).send("Invalid Token");
  }
};

function authRole(role) {
  return(req,res,next)=>{
    if(req.user.role !== role){
      res.status(401).send('Acceess Denied!')
    }

    next()
  }
}

module.exports = {
  authUser,
  authRole
} 
