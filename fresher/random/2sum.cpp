#include <iostream>
using namespace std;

int main() {
    int a[10] = {2, 3, 5, 6, 7, 10, 12, 13, 14, 15};
    int i = 0, j = 9;
    while (i <= j) {
        int sum = a[i] + a[j];
        if (sum == 11) {
            cout << "found" << " " << a[i] << " " << a[j] << endl;
            return 0;
        } else if (sum < 11) {
            i++;
        } else {
            j--;
        }
    }
}
