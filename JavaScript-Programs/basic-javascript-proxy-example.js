const api_methods = ["toString"];
const noop = () => {};

/**
 * Creates simple url builder
 * @param {string} base base url
 * @returns {noop}
 * https://github.com/itsnporg/Hacktoberfest-2021
 * @example const builder = create("https://github.com");
 * console.log(`Final: ${builder.itsnporg("Hacktoberfest-2021").toString()}`);
 * // Expected output:
 * // https://github.com/itsnporg/Hacktoberfest-2021
 */
function create(base) {
  const params = [];
  const handler = {
    // handle property values
    get(_a, b, _c) {
      if (api_methods.includes(b)) {
        // data sample: { query: { name: "hacktoberfest" } }
        // transforms into ?name=hacktoberfest and so on
        return (data) => {
          const queryParams = data?.query
            ? Object.entries(data.query)
                .map(([m, n]) => `${m}=${n}`)
                .join("&")
            : null;
          return `${base ?? ""}/${params.join("/")}${
            queryParams ? "?" + queryParams : ""
          }`;
        };
      }

      params.push(b);
      return new Proxy(noop, handler);
    },
    // handle methods
    apply(_a, _b, c) {
      // transforms .something("a", "b", "c")
      // into /something/a/b/c
      params.push(c.join("/"));
      return new Proxy(noop, handler);
    },
  };

  return new Proxy(noop, handler);
}

// example
const builder = create("https://github.com");

// we can chain as much as we want here
console.log(`Final: ${builder.itsnporg("Hacktoberfest-2021").toString()}`);
// -> https://github.com/itsnporg/Hacktoberfest-2021

console.log(
  `Final: ${builder.itsnporg("Hacktoberfest-2021").toString({
    query: {
      october: true,
      from: "itsnporg",
    },
  })}`
);
// -> https://github.com/itsnporg/Hacktoberfest-2021?october=true&from=itsnporg
