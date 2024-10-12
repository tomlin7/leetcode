use std::collections::HashSet;

pub struct Solution;

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut a = 0;
        let mut cur = HashSet::new();
        for c in s.chars() {
            if cur.contains(&c) {
                a += 1;
                cur.clear();
            }
            cur.insert(c);
        }

        a + 1
    }
}
