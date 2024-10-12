#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> perm(n);
        
        auto it = max_element(nums.begin(), nums.end());
        int j = distance(nums.begin(), it);
        
        for (int i = 0; i < j; ++i) {
            perm[i] = i + 1;
        }
        perm[j] = 0;
        for (int i = j + 1; i < n; ++i) {
            perm[i] = i;
        }
        
        return perm;
    }
};
