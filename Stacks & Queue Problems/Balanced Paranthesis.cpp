#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

bool check(string s)
{
    stack<char> st;

    for (auto ch : s)
    {

        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            st.push(ch);
            break;

        case ')':
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;

        default:
            continue;
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{

    cout << isBalanced("((a+b]*x-d)")<<endl;
    cout << check("((a+b)*x-d)");

    return 0;
}
