// Vectors are resizeble arrays

use std::mem;

pub fn run () {
    println!("Vectors.rs start");
    let mut numbers: Vec<i32> = vec![1, 2, 3, 4, 5]; // can make mutable with mut

    // re assigning
    numbers[2] = 20;

    // add on to vector
    numbers.push(6);
    numbers.push(7);

    // Pop off last value
    numbers.pop(); // removes last value (7)

    // Loop through vector values
    for x in numbers.iter() {
        println!("Number: {}", x);
    }

    // Loop & mutate values
    for x in numbers.iter_mut() {
        *x *= 2; // each value multiplied by 2
    }

    println!("Numbers vec: {:?}", numbers);



    println!("{:?}", numbers); // gets all values
    println!("Single value: {}", numbers[0]); //gets single value

    // get vector length
    println!("Vector length: {}", numbers.len());

    // Vectors are stack allocated
    println!("Vector occupies {} bytes", mem::size_of_val(&numbers));


    // Get slice
    let slice: &[i32] = &numbers[0..2]; // first 2 from array
    println!("Slice: {:?}", slice); //must use :? debugtrait
}