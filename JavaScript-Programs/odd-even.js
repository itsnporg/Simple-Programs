function totalNumbers() {
  for (let numbers = 0; numbers <= 100; numbers++) {
    let evenCheck = Number.isInteger(numbers / 2) ? "✅" : "❌";
    console.log(`${numbers}: Even ${evenCheck}`);
  }
}

totalNumbers();
