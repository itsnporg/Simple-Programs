const one = () => {
  let x = "This variable is still available once the function is returned";

  function two() {
    console.log(x);
  }

  return two;
};

let r = one();

console.log(r);

r();
