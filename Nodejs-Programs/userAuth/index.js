const express = require('express');
const app = express();
const mongoose = require('mongoose');
const dotenv = require('dotenv');

//Import Routes
const authRoute = require('./routes/auth')
const postRoute=require('./routes/posts')

dotenv.config();

//Connected to db
mongoose.connect(process.env.DB_CONNECT,
{useNewUrlParser:true},()=>console.log('Connected to DB!'))

//Middleware
//For Post Request
app.use(express.json());

//Route middlewares
app.use('/api/user',authRoute)
// app.use('/api/posts',postRoute)

app.listen(5000, ()=>{
    console.log('Server up and running!');
})