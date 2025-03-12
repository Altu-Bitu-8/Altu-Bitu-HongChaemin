#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    // a가 항상 더 큰 자릿수가 되도록 만들기
    if (a.length() < b.length()) {
        swap(a, b);
    }
    
    int len_a = a.length();
    int len_b = b.length();
    
    // 자리수 맞춰주기
    string padding = "";
    for (int i=0; i<(len_a-len_b); i++) {
            padding += "0";
    }
    b = padding + b;
    
    // 뒤부터 한 자리씩 덧셈
    string result = "";
    int carry = 0;
    int sum;
    for (int i = len_a-1; i>=0; i--) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        
        result += (sum % 10) + '0';
    }
    
    if (carry == 1) {
        result += "1";
    }
    
    reverse(result.begin(), result.end());
    cout << result << '\n';
    
    return 0;
}
