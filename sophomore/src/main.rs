// use std::env;

mod problems;

fn main() {
    // let args: Vec<String> = env::args().collect();

    let result = problems::latest::Solution::reverse_vowels("abab".to_string());

    println!("{}", result);
}
