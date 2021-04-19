#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            count++;
    }

    if (count % 2 == 1 || s[0] == '0' || s[n - 1] == '0')
    {
        cout << "NO\n";
        return;
    }

    string a, b;
    int k = 0;
    bool flip = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a.push_back(2 * k < count ? '(' : ')');
            b.push_back(a.back());
            k++;
        }
        else
        {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n"
         << a << '\n'
         << b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}
