#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    set<string> substring;
    
    for (int i=0; i<s.length(); i++) {
        string str = "";
        for (int j=i; j<s.length() ; j++) {
            str += s[j];
            substring.insert(str);
        }
    }
    
    cout << substring.size() << '\n';
    
    return 0;
}