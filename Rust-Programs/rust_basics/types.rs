/*
Integers: u8, i8, u16, i16, u32, i32, u64, i64, u128, i128 (number of bits)
Float: f32, f64
Boolean (bool)
Characters (char) one character
Tuples
Arrays - fixed length
not required type but can be wrong
*/

pub fn run() {
    let x = 1; // default is going to be "i32"

    let y = 2.5; // default is going to be "f64"

    let z: i64 = 75134652352; //explicit type

    //Find max size
    println!("Max i32: {}", std::i32::MAX);
    println!("Max i64: {}", std::i64::MAX);
    println!("Max f32: {}", std::f32::MAX);

    //boolean
    let is_active = true; // or let is_active: bool = true;

    // Get boolean from expression
    let is_greater = 10 > 5;
    let is_false = 10 < 5;

    let a1 = 'a'; //single quotes and ONE UNICODE ONLY, cant be 'ab' for ex
    let face = '\u{1F624}'; //Emoji unicode

    println!("{:?}", (x, y, z, is_active, is_greater, is_false, a1, face));
}