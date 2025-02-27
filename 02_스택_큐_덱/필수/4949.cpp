#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string input;
    
    getline(cin, input);
    
    while (input != ".") { 
        stack<char> bracket; 
        bool result = true;
        
        for (char c : input) {
            if (c == '(' || c == '[') {
                bracket.push(c);
            }
            else if (c == ')') {
                if (!bracket.empty() && bracket.top() == '(') {
                    bracket.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
            else if (c == ']') {
                if (!bracket.empty() && bracket.top() == '[') {
                    bracket.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
        }
        
        if (bracket.empty() && result) {
            cout << "yes\n"; 
        } 
        else {
            cout << "no\n"; 
        }
        
        getline(cin, input);
    }
    
    return 0;
}