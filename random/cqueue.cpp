#include <iostream>
#include <vector>

using namespace std;

struct Queue {
    vector<int> q = vector<int>(5);
    int f = -1, r = -1, n = 5;
    void enQueue(int x) {
        if ((f == 0 && r == n - 1) || (f == (r + 1) % n)) {
            cout << "Queue Overflow while enqueuing " << x << endl;
            return;
        }
        if (f == -1 && r == -1) {
            f = 0;
            r = 0;
        } else {
            r = (r + 1) % n;
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
            f = (f + 1) % n;
        }
        return x;
    }
};

// in example show a case that linear queue cant solve
int main() {
    Queue q;

    cout << "Enqueue 1, 2, 3, 4, 5" << endl;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    cout << "Dequeue" << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    cout << "Enqueue 6, 7, 8" << endl;
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);

    cout << "Dequeue" << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
}