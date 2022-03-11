#include <iostream>
using namespace std;
int N;
string arr[2];

bool solve(string arr[]) {
    bool result = true;
    int alpha1[26] = {};
    int alpha2[26] = {};
    for(int i=0; i<arr[0].size(); i++) {
        alpha1[arr[0][i] - 'a']++;
    }
    for(int i=0; i<arr[1].size(); i++) {
        alpha2[arr[1][i] - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(alpha1[i] != alpha2[i]) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> arr[0] >> arr[1];
        if(solve(arr)) {
            cout << "Possible" << '\n';
        } else {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}