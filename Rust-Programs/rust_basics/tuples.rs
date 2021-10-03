// Typles group together values of different types
// Max 12 elements

pub fn run() {
    println!("Start of tuples.rs");

    let person: (&str, &str, i8) = ("Zoika", "SP", 19);

    println!("{} is from {} and is {}", person.0, person.1, person.2);

    println!("End of tuples.rs");
}