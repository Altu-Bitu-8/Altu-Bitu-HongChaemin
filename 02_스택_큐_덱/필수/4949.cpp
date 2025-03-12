#include <iostream>
#include <stack>

using namespace std;

bool checkBracket(const string& input) { // 문자열이 균형을 이루면 true, 아니면 false
    stack<char> bracket; 
        
    for (char c : input) {
        if (c == '(' || c == '[') {
            bracket.push(c);
        }
        else if (c == ')') {
            if (!bracket.empty() && bracket.top() == '(') {
                bracket.pop();
            }
            else {
                return false;
            }
        }
        else if (c == ']') {
            if (!bracket.empty() && bracket.top() == '[') {
                bracket.pop();
            }
            else {
                return false;
            }
        }
    }
    return bracket.empty();
}

int main()
{
    string input;
    
    while (true) { 
        getline(cin, input);

        if (input == ".") {
            break;
        }
        
        if (checkBracket(input)) {
            cout << "yes\n"; 
        } 
        else {
            cout << "no\n"; 
        }
    }
    
    return 0;
}
