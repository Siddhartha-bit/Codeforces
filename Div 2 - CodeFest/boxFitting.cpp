#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

#define NDEBUg
#define PW 20
array<int, PW> arr;
int n, w;

bool valid(int height)
{
    for (int pw = 0; pw < PW; pw++)
    {
        long long units_i_have = 1ll * height * (w / (1 << pw));
        if (units_i_have < arr[pw])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> w;

        for (int i = 0; i < PW; i++)
            arr[i] = 0;

        for (int _ = 0; _ < n; _++)
        {
            int w;
            cin >> w;
            arr[log2(w)] += 1;
        }

        // suffix cumulative count
        for (int i = PW - 2; i >= 0; i--)
            arr[i] += 2 * arr[i + 1];

        int beg = 1, end = n, ans = -1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;

            if (valid(mid))
            {
                end = mid - 1;
                ans = mid;
            }
            else
            {
                beg = mid + 1;
            }
        }

        assert(ans != -1);
        cout << ans << endl;
    }
}