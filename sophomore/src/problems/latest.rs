use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut s = s.split_whitespace().collect::<Vec<&str>>();
        s.reverse();
        s.join(" ")
    }
}
