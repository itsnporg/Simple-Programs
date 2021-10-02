//Simple glitch effect

document.addEventListener('DOMContentLoaded', glitchy, false);
function rand(min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min);
}
String.prototype.replaceAt = function(index, character) {
    return this.substr(0, index) + character + this.substr(index + character.length);
}

function glitchy() {
  
    //Styling the glitch effect 
  
    var sheet = document.createElement('style')
    sheet.innerHTML = ".glitchy {font-family:monospace; }";
    document.body.appendChild(sheet);

    let textsToGlitch = document.getElementsByClassName("glitchy");
    for (var i = 0; i < textsToGlitch.length; i++) {
        partitionWords(textsToGlitch[i], i);
    }
}

function partitionWords(obj, id) {
    let words = obj.innerHTML.split(" ");
    let endHTML = "";
    let i = 0;
    words.forEach((w) => {
        endHTML += `<span id="glitchword-${id}-${i}">${w} </span>`;
        i++;
    });
    //console.log(endHTML);
    obj.innerHTML = endHTML;
    startGlitch(id, i);
}

function startGlitch(id, length) {
    let time = rand(200, 1000);
    setTimeout(() => {
        let firstWord = document.querySelector(`#glitchword-${id}-${rand(0, length - 1)}`);
        let secondWord = document.querySelector(`#glitchword-${id}-${rand(0, length - 1)}`);
        let firstDefaultText = firstWord.innerHTML;
        let firstNewText = firstWord.innerHTML;
        let secondDefaultText = secondWord.innerHTML;
        let secondNewText = secondWord.innerHTML;
        //console.log(firstWord.innerHTML, secondWord.innerHTML);
        let randForFirst = rand(0, firstWord.innerHTML.length - 2); //2 for the last white space.
        let randForSecond = rand(0, secondWord.innerHTML.length - 2); //2 for the last white space.
        firstNewText = firstNewText.replaceAt(randForFirst, secondWord.innerHTML[randForSecond]);
        secondNewText = secondNewText.replaceAt(randForSecond, firstWord.innerHTML[randForFirst]);
        //console.log(firstNewText, secondNewText);
        firstWord.innerHTML = firstNewText;
        secondWord.innerHTML = secondNewText;
        let timeoutTime = rand(100, 200);
        setTimeout(() => {
            // Set to default
            firstWord.innerHTML = firstDefaultText;
            secondWord.innerHTML = secondDefaultText;
            startGlitch(id, length);
            // recurse the glitching
        }, timeoutTime);
    }, time);
}

