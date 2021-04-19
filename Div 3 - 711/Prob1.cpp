#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long long m, n, x;
        cin >> n >> m >> x;
        long long i = (x - 1) % n + 1;
        long long j = (x - 1) / n + 1;
        cout << m * (i - 1) + j << endl;
    }
}
