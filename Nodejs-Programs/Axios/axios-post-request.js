const axios = require("axios");

(async () => {
  const { data } = await axios.post(
    "https://jsonplaceholder.typicode.com/posts",
    {
      title: "This is title.",
      body: "This is body",
      userId: "101",
    }
  );
  console.log(data);
})();
