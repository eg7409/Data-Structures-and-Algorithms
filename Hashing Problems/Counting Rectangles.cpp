#include <bits/stdc++.h>
#define ll long long
using namespace std;

class comp
{

public:
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return x.first < y.first;
    }
};

void solve(int n, vector<pair<int, int>> v)
{

    set<pair<int, int>, comp> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(make_pair(v[i].first, v[i].second));
    }

    int ans = 0;

    for (auto i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (v[i].first == v[j].first || v[j].second == v[i].second)
            {
                continue;
            }
            pair<int, int> p1 = {v[i].first, v[j].second};
            pair<int, int> p2 = {v[j].first, v[i].second};

            if (s.find(p1) != s.end() && s.find(p2) != s.end())
            {
                ans++;
            }
        }
    }

    cout << ans / 2 << endl;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = {x, y};
    }

    solve(n, v);

    return 0;
}

/*

8
0 1
0 0
1 1
1 0
2 1
2 0
3 1
3 0

*/
