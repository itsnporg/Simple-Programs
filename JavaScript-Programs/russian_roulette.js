function russian_roulette() {
	const randomint = Math.round(Math.random() * 10);
  if (randomint % 5 === 0) {
    while (true) {
      window.alert("Sorry, but you got shot!")
    }
  }
}
russian_roulette();