let i = 0;

//Add the name of picture in here
//images = ["husky0.jpeg","huskky1.jpeg", "husky2.jpeg", "husky3.jpeg","husky4.jpeg"]

const next = () => {
  if (i < images.length - 1) {
    i++;
    document.getElementById("image").src = images[i];
  } else if (i == images.length + 1) {
    document.getElementById("image").src = images[2];
  }
};

const prev = () => {
  if (i == 0) {
    document.getElementById("image").src = images[i];
  } else if (i < images.length) {
    i--;
    document.getElementById("image").src = images[i];
  }
};

const start = () => {
  document.getElementById("image").src = images[0];
};

const end = () => {
  document.getElementById("image").src = images[images.length - 1];
};
