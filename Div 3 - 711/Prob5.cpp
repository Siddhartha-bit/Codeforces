#include <bits\stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> q(n);

    for (int i = 0; i < n; i++)
        cin >> q[i];

    set<int> set1;
    set<int> set2;

    vector<int> res1(n, -1);
    vector<int> res2(n, -1);

    for (int i = 1; i <= n; i++)
    {
        set1.insert(i);
        set2.insert(i);
    }

    for (int i = 0, lastPlaced = -1; i < n; lastPlaced = q[i], i++)
    {
        if (lastPlaced != q[i])
        {
            res1[i] = q[i];
            set1.erase(q[i]);
        }
        else
        {
            auto it = set1.begin();
            res1[i] = *it;
            set1.erase(*it);
        }
    }

    for (int i = 0, last = -1, lastPlaced = -1; i < n; last = q[i], lastPlaced = res2[i], i++)
    {
        if (last != q[i])
        {
            res2[i] = q[i];
            set2.erase(q[i]);
        }
        else
        {
            auto it = --set2.lower_bound(lastPlaced);
            res2[i] = *it;
            set2.erase(*it);
        }
    }

    for (auto x : res1)
        cout << x << " ";
    cout << "\n";
    for (auto x : res2)
        cout << x << " ";
    cout << "\n";
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