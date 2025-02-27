#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;
    
    int W = W0;
    int BMR = I0;
    
    // 일일 기초 대사량의 변화를 고려하지 않았을 때
    for (int i = 0; i < D; i++) {
        W += I - (BMR + A);
    }

    if (W <= 0) {
            cout << "Danger Diet\n";
    } else {
        cout << W << " " << BMR << '\n';
    }
    
    // 일일 기초 대사량의 변화를 고려했을 때
    W = W0;
    BMR = I0;
    bool danger = false;
    
    for (int i=0; i < D; i++) {
        int E = I - (BMR + A);
        W += E; 
        
        if (abs(E) > T) {
            BMR += floor(E / 2.0);
        }
        
        if (W <= 0 || BMR <=0) {
            danger = true;
            break;
        }
    }
    
    if(danger) {
        cout << "Danger Diet\n";
    } else {
        cout << W << " " << BMR << " ";
        
        int E = I0 - (BMR + 0); // 초기 상태로 돌아갔을 때
        if (E > 0) {
            cout << "YOYO\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}