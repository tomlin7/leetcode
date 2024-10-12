struct custom{
    bool operator()(pair<char,int> const &a, pair<char,int> const &b){
        return a.second > b.second;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        map<char,int> occ;
        for(char c:s)
            occ[c]++;
        
        string ans;
        vector<pair<char, int>> srt(occ.begin(), occ.end());
        sort(srt.begin(), srt.end(), custom());
        for(auto j:srt)
            ans+=string(j.second, j.first);
        
        return ans;
    }
};