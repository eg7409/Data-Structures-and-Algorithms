#include <bits/stdc++.h>
using namespace std;

// Balanced or not?

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

// Redundant Paranthesis

bool checkRedundant(string s)
{

    stack<int> st;

    int n = s.length();
    bool f = false;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            f = false;
            if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
                    {
                        f = true;
                    }
                    st.pop();
                }
                st.pop();
            }
            else if (s[i] == '}')
            {
                while (!st.empty() && st.top() != '{')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
                    {
                        f = true;
                    }
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && st.top() != '[')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
                    {
                        f = true;
                    }
                    st.pop();
                }
                st.pop();
            }

            if (!f)
            {
                return true;
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return false;
}

int main()
{

    string s1 = "((a+b]+c)";
    string s2 = "((a+{b})+c)";

    if (isBalanced(s1))
    {
        if (checkRedundant(s1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "S1 is not balanced\n";
    }

    if (isBalanced(s2))
    {
        if (checkRedundant(s2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "S2 is not balanced\n";
    }

    return 0;
}
