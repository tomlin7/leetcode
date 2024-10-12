#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> l;
        for(int i:nums){
            vector<int> d = {i};
            for(int j:nums){
                if (i == j) continue;

                int fit = 1;
                for (int k: d)
                    if(!(k%j == 0 || j%k == 0))
                        fit = 0;
                if(fit)
                    d.push_back(j);
            }
            l = max(d, l, [](vector<int> a, vector<int> b){return a.size() < b.size();});
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<int> l = s.largestDivisibleSubset(nums);
    for(int i: l){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}