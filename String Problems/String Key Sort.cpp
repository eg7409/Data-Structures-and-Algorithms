#include <bits/stdc++.h>
using namespace std;

//String Key Sort

string extractKey(string s, int key)
{

  char *c = strtok((char *)s.c_str(), " "); //s.c_str()

  while (key > 1)
  {
    c = strtok(NULL, " ");
    key--;
  }

  return (string)c;
}

int convertToINT(string s)
{

  int p = 1;
  int num = 0;

  for (int i = s.length() - 1; i >= 0; i--)
  {
    num += (s[i]-'0') * p;
    p *= 10;
  }
  return num;
}

bool numeric(pair<string, string> a, pair<string, string> b)
{
  string key1 = a.second;
  string key2 = b.second;

  return convertToINT(key1) < convertToINT(key2);
}
bool lexico(pair<string, string> a, pair<string, string> b)
{
  string key1 = a.second;
  string key2 = b.second;

  return key1 < key2;
}

int main()
{

  int n;
  cin >> n;

  cin.get(); //to consume extra endl

  string s;
  vector<string> v;

  for (int i = 0; i < n; i++)
  {
    getline(cin, s);
    v.push_back(s);
  }

  int key;
  string reversal, order;
  cin >> key >> reversal >> order;

  vector<pair<string, string>> p;

  for (int i = 0; i < n; i++)
  {
    p.push_back({v[i], extractKey(v[i], key)});
  }

  if (order == "numeric")
  {
    sort(p.begin(), p.end(), numeric);
  }
  else
  {
    sort(p.begin(), p.end(), lexico);
  }

  if(reversal == "true"){
    reverse(p.begin(),p.end());
  }

  for(auto i : p){
    cout<<i.first<<endl;
  }

  return 0;
}
