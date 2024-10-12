// use std::env;

mod problems;

fn main() {
    // let args: Vec<String> = env::args().collect();

    let result = problems::latest::Solution::gcd_of_strings("abab".to_string(), "ab".to_string());

    println!("{}", result);
}
