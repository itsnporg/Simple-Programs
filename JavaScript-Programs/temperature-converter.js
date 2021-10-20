function celcToFare(celsius) {
  const cTemp = celsius;
  const cToFahr = (cTemp * 9) / 5 + 32;
  const message = cTemp + "\xB0C is " + cToFahr + " \xB0F.";
  console.log(message);
}

function farenToCelc(fahrenheit) {
  const fTemp = fahrenheit;
  const fToCel = ((fTemp - 32) * 5) / 9;
  const message = fTemp + "\xB0F is " + fToCel + "\xB0C.";
  console.log(message);
}
cToF(60);
fToC(45);
