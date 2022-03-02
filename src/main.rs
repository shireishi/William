use std::{io, env};

fn main() -> None {
    let args: Vec<String> = env::args().collect();
    println!("{:?}", args);
}