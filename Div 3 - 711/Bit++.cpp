#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    int X = 0;

    for (auto x : input)
    {
        if (x[1] == '-')
            X--;
        else if (x[1] == '+')
            X++;
    }

    cout << X << endl;
}
