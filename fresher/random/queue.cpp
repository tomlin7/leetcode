#include <iostream>
#include <vector>

using namespace std;

struct Queue {
    vector<int> q = vector<int>(5);
    int f = -1, r = -1, n = 5;
    void enQueue(int x) {
        if (r == n - 1) {
            cout << "Queue Overflow while enqueuing " << x << endl;
            return;
        }
        if (f == -1) {
            f = 0;
            r = 0;
        } else {
            r++;
        }
        q[r] = x;
    }

    int deQueue() {
        if (f == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = q.at(f);
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f++;
        }
        return x;
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6); // queue overflow

    cout << q.deQueue() << endl; // 1
    cout << q.deQueue() << endl; // 2
    cout << q.deQueue() << endl; // 3
    cout << q.deQueue() << endl; // 4
    cout << q.deQueue() << endl; // 5
    q.deQueue();                 // queue underflow

    return 0;
}