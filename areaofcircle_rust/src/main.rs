use std::io::{self, Write};
use std::f64::consts::PI;
use regex::Regex;
use terminal_size::{terminal_size, Width};

fn terminal_width() -> usize {
    if let Some((Width(w), _)) = terminal_size() {
        w as usize
    } else {
        80
    }
}

// Remove ANSI escape codes
fn visible_length(s: &str) -> usize {
    let re = Regex::new(r"\x1b\[[0-9;]*m").unwrap();
    re.replace_all(s, "").chars().count()
}

// Print a fully centered line
fn print_centered(msg: &str) {
    let width = terminal_width();
    for line in msg.lines() {
        let len = visible_length(line);
        let padding = width.saturating_sub(len) / 2;
        println!("{}{}", " ".repeat(padding), line);
    }
}

// Print a centered prompt inline (cursor after text)
fn print_centered_inline(msg: &str) {
    let width = terminal_width();
    let len = visible_length(msg);
    let padding = width.saturating_sub(len) / 2;
    print!("{}{}", " ".repeat(padding), msg);
    io::stdout().flush().unwrap();
}

fn main() {
    print!("\x1b[1;36m");
    print_centered("**************************************************");
    print_centered("*                                                *");
    print_centered("*          Welcome to the Coding World!          *");
    print_centered("*                                                *");
    print_centered("**************************************************");
    print!("\x1b[1;31m");
    print_centered("Presented by:");
    print_centered("Sadi Mahmud Sajid / Devildon");
    print_centered("(devil㉿kali)");
    print_centered("Contact: 01890731620");
    print_centered("Email: sadimahmudsajid@gmail.com");
    print!("\x1b[0m\n");
    print_centered("\x1b[1;32m>>>Rust program to calculate the area of a circle<<<\x1b[0m");

    let mut choice = String::new();
    loop {
        let r: f64 = loop {
            println!();
            print!("\x1b[1;33m");
            print_centered_inline("Enter the value of r: ");
            print!("\x1b[0m");
            io::stdout().flush().unwrap();

            let mut input = String::new();
            if io::stdin().read_line(&mut input).is_err() {
                println!(); // GAP line added
                print_centered("\x1b[1;31mError reading input.\x1b[0m");
                continue;
            }

            let trimmed = input.trim();
            match trimmed.parse::<f64>() {
                Ok(val) if val > 0.0 => break val,
                Ok(_) => {
                    println!(); // GAP line added
                    print_centered("\x1b[1;31mPlease enter 'r > 0':\x1b[0m")
                }
                Err(_) => {
                    println!(); // GAP line added
                    print_centered("\x1b[1;31mPlease enter only numbers.\x1b[0m")
                }
            }
        };

        print_centered(&format!("\x1b[1;33mThe area is {:.2}\x1b[0m", r * r * PI));

        println!();
        print!("\x1b[1;35m");
        print_centered_inline("Do you want to calculate another area? (y/n): ");
        print!("\x1b[0m");
        io::stdout().flush().unwrap();
        choice.clear();
        io::stdin().read_line(&mut choice).unwrap();
        let mut c = choice.trim().to_lowercase();
        while c != "y" && c != "n" {
            println!(); // GAP line added
            print_centered_inline("\x1b[1;31mPlease enter 'y' or 'n':\x1b[0m");
            io::stdout().flush().unwrap();
            choice.clear();
            io::stdin().read_line(&mut choice).unwrap();
            c = choice.trim().to_lowercase();
        }
        if c == "n" {
            break;
        }
    }
    print!("\x1b[0m");
}
