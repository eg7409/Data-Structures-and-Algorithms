#include <bits/stdc++.h>
using namespace std;

//Stock Span Problem


vector<int> stockSpan(vector<int> v)
{
    //Write your code here. Do not modify the function or parameters.
    stack<int> s;
    

    int n = v.size();

    vector<int> ans;
    ans.push_back(1);
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        if (v[s.top()] > v[i])
        {
            ans.push_back(1);
            s.push(i);
        
        }
        else
        {
            while (!s.empty() && v[s.top()] <= v[i])
            {
  
                s.pop();
            }

            if(s.empty()){
                ans.push_back(i+1);
            }
            else{
                ans.push_back(i - s.top());
            }
            
            s.push(i);
        }
        
    }
    return ans;
}

/*
vector<int> stockSpan(vector<int> v)
{
    //Write your code here. Do not modify the function or parameters.
    stack<int> s;
    stack<int> t;

    int n = v.size();

    vector<int> ans;
    ans.push_back(1);
    s.push(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (s.top() > v[i])
        {
            ans.push_back(1);
            s.push(v[i]);
        }
        else
        {
            while (!s.empty() && s.top() <= v[i])
            {
                t.push(s.top());
                s.pop();
            }
            ans.push_back(t.size() + 1);
            while (!t.empty())
            {
                s.push(t.top());
                t.pop();
            }
            s.push(v[i]);
        }
    }
    return ans;
}
*/
int main()
{

    vector<int> v = {10, 4, 5, 90, 120, 80};
    vector<int> ans = stockSpan(v);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
