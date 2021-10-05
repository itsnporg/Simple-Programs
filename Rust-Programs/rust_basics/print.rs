pub fn run() {
    // Console print
    println!("Hello, world! from print.rs");

    // Basic Formatting
    println!("Number: {}, {}", 1, "from print.rs file");

    // Positional Arguments
    println!("{0} is from {1} and {0} likes to {2}", "Zoika", "SP", "code");

    // Named arguments
    println!("{name} likes to play {action}", name = "Zoika", action = "games");

    // Placeholder traits
    println!("Binary: {:b} Hex: {:x} Octal: {:o}", 10, 10, 10);

    //Placeholder for debug trait
    println!("{:?}",(12, true, "hello"));

    //Math
    println!("10 + 10 = {}", 10 + 10);
}