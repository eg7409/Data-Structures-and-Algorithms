#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<int> v, int r)
{

    int n = v.size();

    map<int, int> right, left;

    for (int i = 0; i < n; i++)
    {
        right[v[i]]++;
    }

    int c = 0;

    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        right[v[i]]--;

        if (v[i] % r == 0)
        {
            int m1 = v[i] / r, m2 = v[i] * r;

            temp = left[m1] * right[m2];
            c += temp;
        }

        left[v[i]]++;
    }

    cout << c << endl;
}

int main()
{

    vector<int> v = {1, 16, 4, 16, 64, 16};
    int r = 4;

    solve(v, r);
    return 0;
}
