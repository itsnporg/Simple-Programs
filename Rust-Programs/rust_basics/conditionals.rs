pub fn run() {
    let age: u8 = 18;
    let check_id: bool = true;
    let knows_person_of_age = true;

    // If/else
    if age >= 21  && check_id || knows_person_of_age {
        println!("Bartender: What would you like to drink?");
    } else if age <21 && check_id {
        println!("Bartender: Sorry, you have to leave.");
    } else {
        println!("Bartender: I need to see your ID");
    }


    // shorthand if
    let is_of_age = if age >= 21 { true } else { false };
    println!(" Is of age: {}", is_of_age); // listens to let age u8
}