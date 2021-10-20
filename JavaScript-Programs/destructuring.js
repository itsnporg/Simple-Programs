// Program demonstrating Object destructuring in Javascript

const obj = {
  name: "Bibek",
  address: {
    country: "Nepal",
    city: "Birtamode",
  },
};

const greetUser = ({ name, address: { country } }) => {
  console.log(`Hello to ${name} from ${country}`);
};

greetUser(obj);
