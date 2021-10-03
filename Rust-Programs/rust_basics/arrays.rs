// Arrays - fixed list where elemtns are the same data types


use std::mem;


pub fn run() {
    println!("Arrays.rs start");
    let mut numbers: [i32; 5] = [1, 2, 3, 4, 5]; // can make mutable with mut

    // re assigning
    numbers[2] = 20;
    println!("{:?}", numbers); // gets all values
    println!("Single value: {}", numbers[0]); //gets single value

    // get array length
    println!("Array length: {}", numbers.len());

    // Arrays are stack allocated
    println!("Array occupies {} bytes", mem::size_of_val(&numbers));


    // Get slice
    let slice: &[i32] = &numbers[0..2]; // first 2 from array
    println!("Slice: {:?}", slice); //must use :? debugtrait
}