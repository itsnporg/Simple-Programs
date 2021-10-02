//PART -1
//Install bcrypt.js using : npm i bcrypt


//PART-2
const bcrypt = require("bcrypt");
//This function will hash the given password and store it in hashed
const password = 'MyPassword123#';
const hashPassword = async () => {
  const hashed = await bcrypt.hash(password, 9);
  //Now you can save the hashed password to database
};


//PART-3
//Verify our password, bcrypt has a method called compare.
const isMatch = bcrypt.compare ( 
    'myPassword' , hashedPassword
);
// 'myPassword'  is the user password.
// hashedPassword is the hashed password from the database.
if (isMatch){
    console.log('Logged in');
} else {
    console.log('Incorrect Password');
}
