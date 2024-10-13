pub struct Solution;

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mx = *candies.iter().max().unwrap();

        let mut a = vec![];
        for c in candies {
            a.push(c + extra_candies >= mx);
        }

        a
    }
}
