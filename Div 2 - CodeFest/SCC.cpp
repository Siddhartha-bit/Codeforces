#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> indegree[i];
    }

    vector<pair<int, pair<int, int>>> diff;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (indegree[i] > indegree[j])
                diff.push_back({indegree[i] - indegree[j], {i, j}});
            else
                diff.push_back({indegree[j] - indegree[i], {j, i}});
        }
    }

    sort(diff.rbegin(), diff.rend());

    for (auto it : diff)
    {
        if (it.first < 0)
            break;

        int a = it.second.first, b = it.second.second;
        cout << "? " << a + 1 << " " << b + 1 << endl;
        cout.flush();
        string response;
        cin >> response;
        if (response == "Yes")
        {
            cout << "! " << a + 1 << " " << b + 1 << endl;
            cout.flush();
            return 0;
        }
    }

    cout << "! 0 0" << endl;
    cout.flush();
    return 0;
}