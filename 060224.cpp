#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};

        unordered_map<string, vector<string>> ans;
        for(string i:strs){
            string temp = i;
            sort(temp.begin(), temp.end());
            ans[temp].push_back(i);
        }

        vector<vector<string>> vals;
        for(auto i=ans.begin(); i!=ans.end(); i++)
            vals.push_back(i->second);

        return vals;
    }
};