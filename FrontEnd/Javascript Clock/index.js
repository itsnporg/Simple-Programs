//referencing the DOM elements.
const hours = document.querySelector("#hours");
const minutes = document.querySelector("#minutes");
const seconds = document.querySelector("#seconds");
const ampm = document.querySelector("#ampm");
const change_format = document.querySelector("#change-format");

//some variable declaration.
let format = "12",
  date;

//Adding a eventlistener to the change format button.
change_format.addEventListener("click", () => {
  if (format == 12) {
    format = 24;
  } else if (format == 24) {
    format = 12;
  }
});
startClock();

function startClock() {
  runApp(format);
  setInterval(() => {
    runApp(format);
  }, 1000);
}

function runApp(current_format) {
  date = new Date();
  if (current_format == "12") {
    hours.innerHTML = convertFormatto12(date.getHours());
    minutes.innerHTML = readyMinutes(date.getMinutes());
    seconds.innerHTML = readySeconds(date.getSeconds());
    ampm.innerHTML = readyAMPM(date.getHours());
  } else if (current_format == "24") {
    hours.innerHTML = readyHours(date.getHours());
    minutes.innerHTML = readyMinutes(date.getMinutes());
    seconds.innerHTML = readySeconds(date.getSeconds());
    ampm.innerHTML = "";
  }
}
//converting default 24 hrs format to 12 hrs.
function convertFormatto12(hours) {
  if (hours > 12) {
    hours = hours - 12;
  }
  return readyHours(hours);
}
// Appending 0 infornt to make it double digit
function readyHours(hours) {
  if (hours >= 0 && hours < 10) {
    return "0" + hours;
  }
  return hours;
}
// Appending 0 infornt to make it double digit
function readyMinutes(minutes) {
  if (minutes >= 0 && minutes < 10) {
    return "0" + minutes;
  }
  return minutes;
}
// Appending 0 infornt to make it double digit
function readySeconds(seconds) {
  if (seconds >= 0 && seconds < 10) {
    return "0" + seconds;
  }
  return seconds;
}

// Generating AM / PM on the basis of current hours.
function readyAMPM(hours) {
  if (hours > 12) {
    return "PM";
  } else {
    return "AM";
  }
}
