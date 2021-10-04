// a JavaScript program for displaying typing animation on page

// select in which element you want to display the typing animation
const body = document.getElementById("text");

//
const type = (text = "This is demo text.", speed = 150) => {
  // counter variable
  let i = 0;

  const interval = setInterval(() => {
    // clear the loop interval if the counter variable is equal to text.length-1
    if (i === text.length - 1) {
      clearInterval(interval);
    }
    // append each  letter to the #body element, sequentially on each iteration
    body.innerHTML += text.charAt(i);

    // increase the counter variable by 1 at the and of every iteration
    i++;
  }, speed);
};
// supply the text and speed variable values as parameters to the type function
// default values from the function will be used if you do not supply any parameters
type("Hello world", 200);
