use std::io;

fn main() {
    println!("Enter a number:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");

    let number: u32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("Please enter a valid number.");
            return;
        }
    };

    println!("Factors of {} are:", number);
    for i in 1..=number {
        if number % i == 0 {
            println!("{}", i);
        }
    }
}
