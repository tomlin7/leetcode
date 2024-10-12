#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> occ;
        unordered_set<int> people;

        for(auto i:trust){
            occ[i[1]]++;
            people.insert(i[0]);
        }

        auto tj = *max_element(occ.begin(), occ.end(), [](const pair<int,int> &a, const pair<int,int> &b)->bool{ return a.second < b.second; });
        cout << tj.first << " " << tj.second << endl;
        return (tj.second == n-1 && people.find(tj.first) == people.end())? tj.first : -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    cout << s.findJudge(4, trust) << endl;
    return 0;
}
