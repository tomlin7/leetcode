pub struct Solution;

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut n = n;
        let mut flowerbed = flowerbed;
        let s = flowerbed.len();
        for i in 0..flowerbed.len() {
            if flowerbed[i] == 0 {
                let prev = if i == 0 { 0 } else { flowerbed[i - 1] };
                let next = if i == s - 1 { 0 } else { flowerbed[i + 1] };
                if prev == 0 && next == 0 {
                    flowerbed[i] = 1;
                    n -= 1;
                }
            }
        }

        n <= 0
    }
}
