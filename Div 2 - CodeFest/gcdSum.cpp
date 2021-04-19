#include <bits/stdc++.h>
using namespace std;

#define ll long long

int sumDigit(ll input)
{
    int_least16_t sum = 0;
    while (input > 0)
    {
        sum += input % 10;
        input /= 10;
    }
    return sum;
}

bool gcd(ll input, int sum)
{
    if (input % sum == 0)
        return (sum == 1) ? 0 : 1;
    else
        return gcd(sum, input % sum);
}

void solve()
{
    ll input;
    cin >> input;
    if (gcd(input, sumDigit(input)))
    {
        cout << input << "\n";
    }
    else if (gcd(input + 1, sumDigit(input + 1)))
    {
        cout << input + 1 << "\n";
    }
    else
        cout << input + 2 << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}