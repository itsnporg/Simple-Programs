// Program to check odd even
// Example we will print 0-100 all Even number if it is even then ✅ else ❌


function totalNumbers() {
    // for loop to check odd even number till 100 
    for (var numbers = 0; numbers <= 100; numbers++) {
            //if divided by 2 then its even else odd
        var EvenCheck = Number.isInteger(numbers / 2) ? "✅" : "❌";
        console.log(`${numbers}: Even ${EvenCheck}`)
    };
};

totalNumbers();