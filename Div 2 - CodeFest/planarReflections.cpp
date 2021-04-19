#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int K = 1001;
const int mod = 1e9 + 7;

int n, k;
int dp[N][K][2];

int solve(int curPlane, int age, int dir)
{
    if (age == 1)
        return 1;

    if (dp[curPlane][age][dir] != -1)
        return dp[curPlane][age][dir];

    int ans = 2;

    if (dir == 1)
    {
        if (curPlane < n)
            ans += solve(curPlane + 1, age, dir) - 1;

        ans %= mod;

        if (curPlane > 1)
            ans += solve(curPlane - 1, age - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curPlane][age][dir] = ans;
    }
    else
    {
        if (curPlane > 1)
            ans += solve(curPlane - 1, age, dir) - 1;

        ans %= mod;

        if (curPlane < n)
            ans += solve(curPlane + 1, age - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curPlane][age][dir] = ans;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << "\n";
    }
}