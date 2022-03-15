#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int k = gcd(n,m);
    int lcm = n*m/k;
    answer.push_back(k);
    answer.push_back(lcm);
    return answer;
}