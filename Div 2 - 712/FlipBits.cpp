#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    int count = 0;
    a.push_back('0');
    b.push_back('0');
    if (a == b)
    {
        cout << "YES"
             << "\n";
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            count += (a[i] == '1') - (a[i] == '0');
            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && count)
            {
                cout << "NO"
                     << "\n";
                return;
            }
        }
    }
    cout << "YES"
         << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}
