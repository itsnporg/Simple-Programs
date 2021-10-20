const numSquares = 9;
const colors = generateRandomColors(numSquares);
const squares = document.querySelectorAll(".square");
const pickedColor = pickColor();
const colorDisplay = document.getElementById("colorDisplay");
const messageDisplay = document.querySelector("#message");
const h1 = document.querySelector("h1");
const resetButton = document.querySelector("#reset");
const easyBtn = document.querySelector("#easyBtn");
const hardBtn = document.querySelector("#hardBtn");

easyBtn.addEventListener("click", function () {
  hardBtn.classList.remove("selected");
  easyBtn.classList.add("selected");
  numSquares = 6;
  colors = generateRandomColors(numSquares);
  pickedColor = pickColor();
  messageDisplay.textContent = "";
  colorDisplay.textContent = pickedColor;
  for (var i = 0; i < squares.length; i++) {
    if (colors[i]) {
      squares[i].style.background = colors[i];
    } else {
      squares[i].style.display = "none";
    }
  }
});

hardBtn.addEventListener("click", function () {
  hardBtn.classList.add("selected");
  easyBtn.classList.remove("selected");
  numSquares = 9;
  colors = generateRandomColors(numSquares);
  pickedColor = pickColor();
  messageDisplay.textContent = "";
  colorDisplay.textContent = pickedColor;
  for (var i = 0; i < squares.length; i++) {
    squares[i].style.background = colors[i];
    squares[i].style.display = "block";
  }
});

resetButton.addEventListener("click", function () {
  //generate all new colors
  colors = generateRandomColors(numSquares);
  //pick a color from array
  pickedColor = pickColor();
  //change color display
  colorDisplay.textContent = pickedColor;
  this.textContent = "New Colors";
  messageDisplay.textContent = "";
  //change color of sqaures
  for (var i = 0; i < squares.length; i++) {
    squares[i].style.background = colors[i];
  }
  h1.style.background = "steelblue";
});

colorDisplay.textContent = pickedColor;

for (var i = 0; i < squares.length; i++) {
  //add colors
  squares[i].style.background = colors[i];

  //add click listeners
  squares[i].addEventListener("click", function () {
    //grab the clicked color
    var clickedColor = this.style.background;
    //compare color to pickedColor
    if (clickedColor === pickedColor) {
      messageDisplay.textContent = "You Are Correct!!";
      resetButton.textContent = "Play Again??";
      changeColors(clickedColor);
      h1.style.background = clickedColor;
    } else {
      this.style.background = "#232323";
      messageDisplay.textContent = "Please Try Again";
    }
  });
}

const changeColors = (color) => {
  //loop through all squares
  for (var i = 0; i < squares.length; i++) {
    //add colors
    squares[i].style.background = color;
  }
};

const pickColor = () => {
  const random = Math.floor(Math.random() * colors.length);
  return colors[random];
};

const generateRandomColors = (num) => {
  //make an array
  const arr = [];
  //repeat num times
  for (var i = 0; i < num; i++) {
    //get random color and push to arr
    arr.push(randomColor());
  }
  //return that array
  return arr;
};

const randomColor = () => {
  //pick red
  const r = Math.floor(Math.random() * 256);
  //pick green
  const g = Math.floor(Math.random() * 256);
  //pick blue
  const b = Math.floor(Math.random() * 256);
  return "rgb(" + r + ", " + g + ", " + b + ")";
};
