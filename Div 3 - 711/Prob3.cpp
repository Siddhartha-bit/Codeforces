#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll LCSubStr(string X, string Y, ll m, ll n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int result = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
        }
    }
    cout << m + n - 2 * result << "\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        string s, t;
        cin >> s >> t;
        LCSubStr(s, t, s.length(), t.length());
    }

    return 0;
}