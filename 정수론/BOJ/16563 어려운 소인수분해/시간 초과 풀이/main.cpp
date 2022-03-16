#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        int target = 0;
        cin >> target;
        int small = 2; // 소인수 
        while(target != 1) {
            if(target % small ==0) {
                target /= small;
                cout << small << ' ';
            } else {
                small++;
            }
        }
        cout << '\n';
    }
    return 0;
}