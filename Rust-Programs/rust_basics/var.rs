//Vars hold primitive or references to data
// Variabels are immutable by default
// Rust is a block-scoped lang

pub fn run() {
    let name = "Zoika";
    let mut age = 19; // Must use mut to make it mutable
    println!("My name is {} and I am {}", name, age);

    age = 20;
    println!("My name is {} and I am {}", name, age);

    //Define constant
    const ID: i32 = 001;
    println!("ID: {}", ID);

    // Assign multiple variables
    let ( my_name, my_age ) = ("Zoika", 19);
    println!("{} is {}", my_name, my_age);
}