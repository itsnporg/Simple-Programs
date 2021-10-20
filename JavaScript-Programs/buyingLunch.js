function whosPaying(names) {
  var length = arguments.length;
  var rand = Math.random();
  rand = rand * length;
  var round = Math.floor(rand) + 1;
  var s = arguments[round] + " is going to buy lunch today.";
  return s;
}
whosPaying("a", "below", "up", "doen", "boart");
