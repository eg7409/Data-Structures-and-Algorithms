#include <bits/stdc++.h>
using namespace std;

// Max Subarray

void solve(vector<int> v, int k)
{
    int n = v.size();

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && v[q.back()] < v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    for (int i = k; i < n; i++)
    {
        if (i - k == q.front())
        {
            q.pop_front();
        }

        while (!q.empty() && v[q.back()] < v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> v = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    solve(v, 3);
    return 0;
}
