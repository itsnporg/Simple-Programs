$(document).ready(function () {
  //You can add other quotes too in same formatting :)
  var quoteList = [
    //Naruto
    ["Uzumaki Naruto", "Dattebayo"],
    [
      "Uzumaki Naruto",
      "I won't run away anymore... I won't go back on my word... that is my ninja way!",
    ],
    ["Uzumaki Naruto", "To become Hokage is my dream!"],
    ["Uzumaki Naruto", "A hero always arrives late."],
    //Sasuke
    [
      "Uchiha Sasuke",
      "I know the four of us have worked together, and for a while, I thought I could choose that road instead... but in the end... I've decided on revenge. That's always been my reason for living.",
    ],
    //Itachi
    ["Uchiha Itachi", "Foolish little brother. Despise me, hate me!"],
    //Kakashi
    [
      "Hatake Kakashi",
      "Those who break the rules are scum, that's true, but those who abandon their friends are worse than scum.",
    ],
    [
      "Hatake Kakashi",
      "(To Team 7) Hmm, how can I put this? My first impression of this group... You're a bunch of idiots.",
    ],
    //Jiraiya
    ["Jiraiya", "Oh, I'm not a little pervert... I'm a big one!"],
    [
      "Jiraiya",
      "A Shinobi's life is not measured by how they lived but rather what they managed to accomplish before their death.",
    ],
    //Rock Lee
    [
      "Rock Lee",
      "Guy-sensei is just the coolest person ever! I mean, he is so cool, he practically glows with cool!",
    ],
    ["Rock Lee", "I am the valiant green beast of the Hidden Leaf Village"],
    [
      "Rock Lee",
      "A genius, huh? What does that mean? Genius? So I was not born with awhole lot of natural talent, not gifted like Neji... but I work hard and I never give up! That is my gift... that is my ninja way",
    ],
    //Sakura
    ["Haruno Sakura", "SHANNARO!"],
    ["Haruno Sakura", "Sasuke-kuuuuuuun!"],
    [
      "Haruno Sakura",
      "I always considered myself... to be a true ninja. I said I loved Sasuke... and I always lectured Naruto, like I was better than him. But it's all empty words. So, this time, everyone... it's your turn to watch my back!",
    ],
    //Shikamaru
    ["Nara Shikamaru", "What a drag..."],
  ];

  $("button").click(changeQuote);

  //Is called on button click. Adds the quote to the page
  function changeQuote() {
    var ninja = quoteList[Math.floor(Math.random() * quoteList.length)];
    $("#quote").html('"' + ninja[1] + '"');
    $("#shinobi").html("- " + ninja[0]);
  }
});
