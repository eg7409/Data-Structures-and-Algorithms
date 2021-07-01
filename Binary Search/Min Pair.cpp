#include <bits/stdc++.h>
using namespace std;

//Min Pair

pair<int, int> solve(vector<int> v1, vector<int> v2, int n, int m)
{

    sort(v2.begin(), v2.end());
    int mini = INT_MAX;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v2.begin(), v2.end(), v1[i]);

        if (it != v2.end())
        {
            if (it - v2.begin() == 0)
            {
                if (mini > (abs(*it - v1[i])))
                {
                    mini = (abs(*it - v1[i]));
                    left = v1[i];
                    right = *it;
                }
            }
            else
            {
                if (mini > (abs(*it - v1[i]) || mini > abs(v2[it - v2.begin() - 1] - v1[i])))
                {

                    if (abs(*it - v1[i]) < abs(*(it - 1) - v1[i]))
                    {
                        mini = min(abs(*it - v1[i]), abs(v2[it - v2.begin() - 1] - v1[i]));
                        left = v1[i];
                        right = *it;
                    }
                    else
                    {
                        mini = min(abs(*it - v1[i]), abs(v2[it - v2.begin() - 1] - v1[i]));
                        left = v1[i];
                        right = v2[it - v2.begin() - 1];
                    }
                }
            }
        }
        //cout<<*it<<" "<<v1[i]<<" "<<v2[it-v2.begin()-1]<<" " <<mini<<endl;
    }
    return {left, right};
}
int main()
{

    vector<int> v1 = {-1, 5, 10, 20, 3};
    vector<int> v2 = {26, 134, 135, 15, 17};

    int n = v1.size(), m = v2.size();

    pair<int, int> p = solve(v1, v2, n, m);

    cout << p.first << " " << p.second << endl;
    return 0;
}
