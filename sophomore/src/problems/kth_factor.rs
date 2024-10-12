pub struct Solution;

impl Solution {
    pub fn kth_factor(n: i32, k: i32) -> i32 {
        let mut factors = vec![];
        for i in 1..=n {
            if n % i == 0 {
                factors.push(i);
            }
        }

        return factors.get(k as usize - 1).unwrap_or(&-1).clone();
    }
}
