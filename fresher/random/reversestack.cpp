#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stack<int> s2 = s;
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }

    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}