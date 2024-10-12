#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for(int i=left+1;i<=right;i++)
            left &= i; 
        
        return left;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5,7) << endl;
    cout << s.rangeBitwiseAnd(0,0) << endl;
    cout << s.rangeBitwiseAnd(1,2147483647) << endl;
    return 0;
}