#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    int stu[7][2];
    for(int i=0; i<7; i++) {
        for(int j=0;j<2; j++) {
            stu[i][j] = 0;
        }
    }
    while(N--) {
        int grade;
        int ss;
        cin >> ss >> grade;
        stu[grade][ss]++;
    }

    int sum = 0;
    for(int i=1; i<=6; i++) {
        for(int j=0; j<2; j++) {
            if(stu[i][j] == 0) continue;
            if(K == 1) {
                sum += stu[i][j];
            } else {
                sum += (stu[i][j]) / K;
                if(stu[i][j] % K != 0) {
                    sum += 1;
                }
            }
        }
    }
    cout << sum;
    return 0 ;
}