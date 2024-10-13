use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut s = s.chars().collect::<Vec<char>>();
        let mut st = vec![];

        for i in 0..s.len() {
            let c = s[i];
            match c {
                'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U' => {
                    st.push(c);
                }
                _ => {}
            }
        }

        let mut out = s.clone();
        for i in 0..s.len() {
            let c = s[i];
            match c {
                'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U' => {
                    out[i] = st.pop().unwrap();
                }
                _ => {}
            }
        }
        out.iter().collect()
    }
}
