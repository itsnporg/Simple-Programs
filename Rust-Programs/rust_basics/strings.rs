// Primitive str = immutable fixed length
// String = growable, heap allocated data structure

pub fn run() {
    let hello = "Hello again, friend"; // first type

    let mut hello_two = String::from("Hello, again ");

    println!("{} or {}", hello, hello_two);

    //Get length
    println!("Length: {}", hello.len()); // 5 letters

    hello_two.push('W'); // single
    hello_two.push_str("orld!"); // string

    println!("{}", hello_two);
    // Capacity in bytes
    println!("Capacity: {}", hello_two.capacity());

    // CHeck if empty
    println!("Is empty: {}", hello.is_empty());
    

    // Contains
    println!("Contains 'World' {} going to be false, or true now {}", hello.contains("World!"), hello_two.contains("World"));

    // Replace
    println!("Replace: {}", hello.replace("World", "There"));

    // Loop through string by whitespace
    for word in hello.split_whitespace() {
        println!("{}", word);
    }

    // Create string with capacity
    let mut s = String::with_capacity(10); // capacity
    s.push('a');
    s.push('b');

    // Assertion testing
    assert_eq!(2, s.len()); // only shows error if wrong
    // assert_eq!(3, s.len());
    // assert_eq!(11, s.capacity()); // 10 is the capacity, so gives error
    
    println!("{}", s);
    println!("End of strings.rs")
}