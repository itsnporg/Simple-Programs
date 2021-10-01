// program to create a countdown timer

// time to countdown from (in milliseconds)
let countDownDate = new Date().getTime() + 24 * 60 * 60 * 1000;

// countdown timer
let x = setInterval(function () {
  // get today's date and time in milliseconds
  let now = new Date().getTime();

  // find the interval between now and the countdown time
  let timeLeft = countDownDate - now;

  // time calculations for days, hours, minutes and seconds
  const days = Math.floor(timeLeft / (1000 * 60 * 60 * 24));
  const hours = Math.floor((timeLeft / (1000 * 60 * 60)) % 24);
  const minutes = Math.floor((timeLeft / 1000 / 60) % 60);
  const seconds = Math.floor((timeLeft / 1000) % 60);

  // display the result in the element with id="demo"
  console.log(days + "d " + hours + "h " + minutes + "m " + seconds + "s ");

  // clearing countdown when complete
  if (timeLeft < 0) {
    clearInterval(x);
    console.log("CountDown Finished");
  }
}, 2000);
