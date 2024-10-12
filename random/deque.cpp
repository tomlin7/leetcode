#include <iostream>
#include <vector>

using namespace std;

struct Queue {
    vector<int> q = vector<int>(5);
    int f = -1, r = -1, n = 5;
    bool isFull() { return (f == 0 && r == n - 1) || (f == (r + 1) % n); }
    bool isEmpty() { return f == -1; }

    void enQueueFront(int x) {
        if (isFull()) {
            cout << "Queue Overflow while enqueuing " << x << endl;
            return;
        }
        if (f == -1) {
            f = 0;
            r = 0;
        } else if (f == 0) {
            f = n - 1;
        } else {
            f--;
        }
        q[f] = x;
    }

    // normal
    int deQueueFront() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = q.at(f);
        if (f == r) {
            f = -1;
            r = -1;
        } else if (f == n - 1) {
            f = 0;
        } else {
            f++;
        }
        return x;
    }

    // normal
    void enQueueRear(int x) {
        if (isFull()) {
            cout << "Queue Overflow while enqueuing " << x << endl;
            return;
        }
        if (f == -1) {
            f = 0;
            r = 0;
        } else if (r == n - 1) {
            r = 0;
        } else {
            r++;
        }
        q[r] = x;
    }

    int deQueueRear() {
        if (f == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = q.at(f);
        if (f == r) {
            f = -1;
            r = -1;
        } else if (r == 0) {
            r = n - 1;
        } else {
            r--;
        }
        return x;
    }
};
int main() {
    Queue q;

    cout << "Enqueue Front 1, 2, 3" << endl;
    q.enQueueFront(1);
    q.enQueueFront(2);
    q.enQueueFront(3);

    cout << "Enqueue Rear 4, 5" << endl;
    q.enQueueRear(4);
    q.enQueueRear(5);

    cout << "Dequeue Front" << endl;
    cout << q.deQueueFront() << endl;
    cout << q.deQueueFront() << endl;

    cout << "Dequeue Rear" << endl;
    cout << q.deQueueRear() << endl;
    cout << q.deQueueRear() << endl;

    cout << "Enqueue Rear 6, 7" << endl;
    q.enQueueRear(6);
    q.enQueueRear(7);

    cout << "Dequeue Front" << endl;
    cout << q.deQueueFront() << endl;
    cout << q.deQueueFront() << endl;

    return 0;
}