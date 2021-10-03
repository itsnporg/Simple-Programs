# Weather app (nodejs)

Hi! This is one of my first nodejs projects. It gives the weather (Fahrenheit) of the location you specify. This is made using nodejs and request module. I have named it as **Weather app**. I am thinking to improve this project as I learn more about nodejs and its modules.

# How to run it?

Install weather app

```
git clone https://github.com/TheCoolGDev/Weather-app-nodejs.git
cd Weather-app-nodejs/
npm install request --save
npm install yargs --save
npm install
```

After this, you need to go [HERE](https://openweathermap.org/price). Sign in and subscribe to the free api package at first..

![Click at the GET API KEY button on the free package](https://i.imgur.com/R2ZlkeD.png)

After you did that, you need to create one api key now. For that, you need to go [HERE](https://home.openweathermap.org/api_keys) and you can give any name there and press generate. After that you need to copy the generated key for our next step.

![Write any name and press enter..](https://i.imgur.com/RwnWmkX.png)

**REMEMBER: DONOT SHARE YOUR API KEY WITH ANYONE.. it can cause problems with the program**

After this you need to go to our program files and you create a `.env` file and write:

```
apiKey = **YOUR KEY**
```

The value `YOUR KEY` is the key/code that you got in the last step..

You should do it like shown in the pic:

![Make .env file and write apiKey = yourkey](https://i.imgur.com/QXakVRo.png)

### Congratulations! You made the program... Now to run it you need to type:

```
node app.js -c **YOUR PLACE's NAME**
```

For example:

![Example of the program](https://i.imgur.com/sMrFndH.png)

## Ending Note

Thank you for following the steps and using my _first_ node.js program. This is just a simple program and I am thinking to improve it as I learn more about node.js and its modules. For that, I need your feedback and suggestions to improve this.

**Bye** and **Be Cool**!
