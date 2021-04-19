#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, string s)
{

    int count = 0;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '*')
        {
            s[i] = 'x';
            count++;
            int j = (i + k > n) ? n - 1 : i + k;
            while (j > i)
            {
                if (s[j] == '*')
                    break;
                j--;
            }
            i = j;
            i--;
        }
        i++;
    }

    cout << count << endl;
}

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n;
        cin >> k;
        cin >> s;
        solve(n, k, s);
    }

    return 0;
}
