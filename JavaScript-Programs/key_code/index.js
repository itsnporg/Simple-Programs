const title = document.querySelector(".title");
const code = document.querySelector(".code");

document.addEventListener('keyup',handleKeyUp);

function handleKeyUp(e){
    title.innerText = `KeyCode for '${e.code}'`
    code.innerText = e.keyCode;
}