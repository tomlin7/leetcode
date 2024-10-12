#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int current=0, next=0, d=0, n = heights.size(), i=0;
        for(i=0; i<n-1; i++) {
            current = heights[i];
            next = heights[i+1];
            cout << "i: " << i << " current: " << current << " next: " << next << " d: " << next-current << " bricks: " << bricks << " ladders: " << ladders << endl;
            if(current>=next)
                continue;

            d = next-current;
            if(d <= bricks){
                bricks -= d;
                continue;
            } 
            
            if(ladders>0){
                ladders--;
                continue;
            }
            break;
        }

        return i;
    }
};

int main() {
    Solution s;
    vector<int> heights = {1,5,1,2,3,4,10000};
    int bricks = 4, ladders = 1;
    cout << s.furthestBuilding(heights, bricks, ladders) << endl;
    return 0;
}