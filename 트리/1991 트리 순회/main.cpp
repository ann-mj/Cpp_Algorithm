#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N; // 노드의 개수
int tree[27][3];
string f;
string m;
string b;
void front(int idx) {
    f.push_back(idx+'A');
    if(tree[idx][0]) front(tree[idx][0]);
    if(tree[idx][1]) front(tree[idx][1]);
}

void mid(int idx) {
    if(tree[idx][0]) mid(tree[idx][0]);
    m.push_back(idx+'A');
    if(tree[idx][1]) mid(tree[idx][1]);
}
void up_back(int idx) {
    if(tree[idx][0]) up_back(tree[idx][0]);
    if(tree[idx][1]) up_back(tree[idx][1]);
    b.push_back(idx+'A');
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--) {
        char a,b,c;
        cin >> a >> b >> c;
        if(b != '.') {
            tree[a - 'A'][0] = b - 'A'; // lc
            tree[b - 'A'][2] = a - 'A'; // parent
        }
        if(c != '.') {
            tree[a - 'A'][1] = c - 'A'; // rc
            tree[c - 'A'][2] = a - 'A';
        }
    }

    front(0);

    mid(0);
    up_back(0);
    cout << f << '\n';
    cout << m << '\n';
    cout << b << '\n';
    return 0;
}