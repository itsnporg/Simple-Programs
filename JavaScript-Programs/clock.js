let name1 = prompt("Enter Your Name");

setInterval(() => {
  let times = new Date();
  // For time and minute block
  ghanta = times.getHours();
  minute = times.getMinutes();
  seconds = times.getSeconds();

  if (ghanta < 12) {
    document.getElementById("greets").innerHTML = `Good Morning, ${name1}!`;
  }

  if (ghanta >= 12 && ghanta < 18) {
    document.getElementById("greets").innerHTML = `Good Afternoon, ${name1}!`;
  }

  if (ghanta > 18) {
    document.getElementById("greets").innerHTML = `Good Evening, ${name1}!`;
  }

  if (ghanta == 0) {
    ghanta = 12;
  }

  if (ghanta > 12) {
    ghanta = ghanta - 12;
  }

  if (ghanta < 10) {
    ghanta = "0" + ghanta;
  }

  if (minute < 10) {
    minute = "0" + minute;
  }

  if (seconds < 10) {
    seconds = "0" + seconds;
  }

  document.getElementById(
    "time"
  ).innerHTML = `${ghanta} : ${minute} : ${seconds}`;

  let din = times.getDay();

  let dayharu = [
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
  ];
  din = dayharu[din];
  document.getElementById("day").innerHTML = din;
}, 00);
