#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e5;

inline ll ceil(ll x, ll y)
{
    return (x + y - 1) / y;
}

void solve(int n, int m)
{
    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    vector<bool> is_seen(m + 1, 0);
    is_seen[0] = 1;

    for (int timestep = 1; timestep <= n; timestep++)
    {
        auto new_is_seen = is_seen;

        int t, y;
        ll x;
        cin >> t >> x >> y;

        auto operation = [&](ll &curr) {
            if (t == 1)
                curr = curr + ceil(x, mod);
            else
                curr = ceil(curr * x, mod);
        };

        for (int k = 0; k <= m; k++)
        {
            if (is_seen[k])
            {
                ll curr = k;
                operation(curr);

                for (int a = 1; a <= y; a++)
                {
                    if (curr > m)
                        break;
                    if (is_seen[curr])
                        break;

                    new_is_seen[curr] = true;
                    dp[curr] = timestep;

                    operation(curr);
                }
            }
        }
        is_seen = new_is_seen;
    }
    for (int i = 1; i <= m; i++)
        cout << dp[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    solve(n, m);
}