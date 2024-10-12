pub struct Solution;

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut seen = vec![false; 26];
        let mut ret = 1;

        for c in s.bytes() {
            if seen[(c - b'a') as usize] {
                // exists, reset seen
                seen.fill(false);
                ret += 1;
            }
            seen[(c - b'a') as usize] = true;
        }

        ret
    }
}
