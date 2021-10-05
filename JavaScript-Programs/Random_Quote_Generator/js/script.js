(function () {
    const quotes = [
        {
            quote:
              " Shallow men believe in luck. Strong men believe in cause and effect. ",
            author: "Ralph Waldo Emerson"
          },
          {
            quote:
              " I can’t give you a sure-fire formula for success, but I can give you a formula for failure: try to please everybody all the time.",
            author: "Herbert Bayard Swope"
          },
          {
            quote:
              " The ladder of success is never crowded at the top.",
            author: "Napoleon Hill "
          },
          {
            quote: " It is better to fail in originality than to succeed in imitation.",
            author: "Herman Melville"
          },
          {
            quote:
              " If you have no critics you’ll likely have no success.",
            author: "Malcolm X"
          },
          {
            quote:
              " A critic is someone who never actually goes to the battle, yet who afterwards comes out shooting the wounded.",
            author: " Tyne Daly"
          }
    ]
    
    const btn = document.getElementById('generate-btn')
    btn.addEventListener('click', function() {
        let random = Math.floor(Math.random() * quotes.length)
        document.getElementById('quote').textContent = quotes[random].quote
        document.querySelector('.author').textContent = quotes[random].author
    })
})()