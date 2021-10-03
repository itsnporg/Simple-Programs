use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("Secret Number: {}", secret_number);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        //converting string which we get from user input into a real number type and also handling invalid input, so that the game igonores  non number type
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,

            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        //Comparing guess and random num and here we use match expression to decide what to do next as we get the  variant of Ordering enum returned from cmp function

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("too less!"),

            Ordering::Greater => println!("too high!"),

            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
