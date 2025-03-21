#include <iostream>
#include <vector>

using namespace std;

// 문자열에서 각 알파벳의 개수 세는 함수
vector<int> countAlphabet(string s) {
    vector<int> alphabet(26, 0); 

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        alphabet[c - 'A']++; // 현재 알파벳의 개수 증가
    }
    
    return alphabet;
}

// 두 단어가 비슷한 단어인지 확인하는 함수
bool isSimilar(const string base, const string cmp) {
    // 1: 두 단어의 길이 차이가 1보다 클 경우 비슷한 단어일 수 없음
    int lengthDiff = abs((int)base.length() - (int)cmp.length());
    if (lengthDiff > 1) return false;

    // 기준 문자열과 비교 문자열의 알파벳 개수 계산
    vector<int> baseCount = countAlphabet(base);
    vector<int> cmpCount = countAlphabet(cmp);

    // 알파벳 구성 차이 계산
    int diff = 0;
    for (int i = 0; i < 26; i++) {
        diff += abs(baseCount[i] - cmpCount[i]);
    }

    // 2: 알파벳 구성 차이에 따라 비슷한 단어 판별
    if (diff == 0) { // 두 단어가 동일한 단어
        return true;
    } 
    else if (diff == 2 && lengthDiff == 0) { // 길이가 같고 한 문자가 교체된 경우
        return true;
    } 
    else if (diff == 1 && lengthDiff == 1) { // 길이가 다르고 한 문자가 추가되거나 삭제된 경우
        return true;
    }
    else { 
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> words(n); // 입력받은 단어들을 벡터에 저장
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string base = words[0]; // 기준이 되는 단어
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (isSimilar(base, words[i])) {
            count++; // 비슷한 단어라면 카운트
        }
    }

    cout << count;

    return 0;
}