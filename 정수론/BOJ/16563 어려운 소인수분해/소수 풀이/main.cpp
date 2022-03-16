#include <iostream>

using namespace std;
#define endl '\n'
int min_factor[5000005];

void solve(int n)
{
    while (n > 1)
    {
        cout << min_factor[n] << ' ';
        n /= min_factor[n];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    min_factor[0] = min_factor[1] = -1;
    for (int i = 2; i <= 5000000; i++)
    {
        min_factor[i] = i;
    }
    for (int v = 2; v * v <= 5000000; v++)
    {
        if (min_factor[v] == v)
        { // v가 소수라면
            for (int k = v * v; k <= 5000000; k += v)
            {
                if (min_factor[k] == k)
                    min_factor[k] = v; // k 는 v 의 배수이다.
            }
        }
    }
    int n;
    cin >> n;
    while (n--)
    {
        int v;
        cin >> v;
        solve(v);
    }
    return 0;
}