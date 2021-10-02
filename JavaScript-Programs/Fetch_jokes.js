const getJoke = async () => {
  const response = await fetch("https://api.chucknorris.io/jokes/random");
  const data = await response.json();

  return data;
};

getJoke()
  .then((data) => {
    console.log(data.value);
  })
  .catch((err) => console.log(err));
