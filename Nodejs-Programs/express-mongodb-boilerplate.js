//IMPORTS
import express from "express";
import mongoose from "mongoose";

const app = express();

//MIDDLEWARES
app.use("/");

//MIDDLEWARE TO TRANSFER DATA
app.use(express.urlencoded({ extended: true }));
app.use(express.json({ limit: "30mb", extended: true }));

//CONSTANTS
const CONNECTION_PORT = "YOUR_MONGODB_CONNECTION_LINK_HERE";
const PORT = process.env.PORT || 5000;

//CONNECTION WITH MONGOOSE DB AND LISTENING TO PORT
mongoose
  .connect(CONNECTION_PORT, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(() => {
    app.listen(PORT, () => {
      console.log(`Server Running on port ${PORT}`);
    });
  })
  .catch((err) => {
    console.log(err);
  });
