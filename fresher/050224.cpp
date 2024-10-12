#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char,int> freq(string s){
        unordered_map<char, int> occ;
        for(auto i=0;i<s.size();i++){
            if (occ.find(s[i]) == occ.end())
                occ[s[i]] = 1;
            else
                occ[s[i]] += 1;
        }
        return occ;
    }
    int firstUniqChar(string s) {
        unordered_map<char, int> occ = freq(s);
        for(auto i=0;i<s.size();i++){
            if (occ[s[i]] == 1)
                return i;
        }
        return -1;  
    }
};
