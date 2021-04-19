#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> q;
    map<int, int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x]++;
    }
    for (auto x : v)
    {
        q.push({x.second, x.first});
    }

    int size = n;
    while (q.size() >= 2)
    {
        auto t1 = q.top();
        q.pop();
        auto t2 = q.top();
        q.pop();
        t1.first--;
        t2.first--;
        if (t1.first)
            q.push(t1);
        if (t2.first)
            q.push(t2);
        size -= 2;
    }
    cout << size << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tests;
    cin >> tests;
    while (tests--)
    {
        solve();
    }
}
