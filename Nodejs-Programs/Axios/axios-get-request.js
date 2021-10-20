const axios = require("axios");

(async () => {
  const res = await axios({ method: "GET", url: "https://example.com" });
  console.log(res);
})();
