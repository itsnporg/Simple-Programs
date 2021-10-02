const mongoose = require('mongoose');

const ROLE = require('./ROLE') 

const userSchema = new mongoose.Schema({

 

    fName:{
        type:String,
        required:true,
        min:3,
        max:255
    },
    lName:{
        type:String,
        required:true,
        min:3,
        max:255
    },
    email:{
        type:String,
        required:true,
        max:255,
        unique:true
    },
    password:{
        type:String,
        required:true,
        max:1024,
        
         
    },
    mobileNumber:{
        type:String,
        required:true,
        max:11,
        min:10
    },
    homeNumber:{
        type:String,
        required:true,
        max:11,
        min:10
    },

    regDate:{
        type:Date,
        default:Date.now,
       
    },
    role:{
        type:String,
        default:ROLE.CUSTOMER
    }
})

module.exports = mongoose.model('User',userSchema);