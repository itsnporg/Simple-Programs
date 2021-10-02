
const Joi = require('@hapi/joi')

//Register Validation
const registerValidation = (data) =>{
    const Schema = Joi.object({
        fName:Joi.string().min(3).required(),
        lName:Joi.string().min(3).required(),
        email:Joi.string().min(6).required().email(),
        password:Joi.string().min(3).required(),
        mobileNumber:Joi.string().min(10).max(11).required(),
        homeNumber: Joi.string().min(10).max(11).required()
    });

    return Schema.validate(data)
}

//Login Validation
const loginValidation = (data)=>{
    const Schema = Joi.object({
       
        email:Joi.string().min(6).required().email(),
        password:Joi.string().min(3).required(),
      
    });

    return Schema.validate(data)
}


module.exports.registerValidation=registerValidation;
module.exports.loginValidation=loginValidation;


