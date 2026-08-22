#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    deque<char> stk;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push_back(c);
        }
        else {
            if (stk.empty()) {
                cout << "no" << endl;
                return 0;
            }
            char top = stk.back();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                stk.pop_back();
            }
            else {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    if (stk.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}