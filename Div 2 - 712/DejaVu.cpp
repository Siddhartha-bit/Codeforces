#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPalindrome(const string &s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

void solve(int n)
{
    while (n--)
    {
        string input;
        cin >> input;

        string t = 'a' + input, t1 = input + 'a';

        if (!isPalindrome('a' + input))
            cout << "YES"
                 << "\n",
                cout << 'a' + input << '\n';
        else if (!isPalindrome(input + 'a'))
            cout << "YES"
                 << "\n",
                cout << input + 'a' << '\n';
        else
            cout << "NO"
                 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    solve(n);
}