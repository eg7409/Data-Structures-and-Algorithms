#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
	char data;
	unordered_map<char, Node *> m;
	bool isTerminal;

	Node(char d)
	{
		data = d;
		isTerminal = false;
	}
};

class Trie
{

public:
	Node *root;

	Trie()
	{
		root = new Node('\0');
	}

	void insert(string word)
	{

		Node *temp = root;

		for (auto ch : word)
		{

			if (temp->m.count(ch) == 0)
			{
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}

			temp = temp->m[ch];
		}

		temp->isTerminal = true;
	}
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m)
{

	Node *temp = t.root;

	for (int j = i; j < document.size(); j++)
	{
		char ch = document[j];

		if (temp->m.count(ch) == 0)
		{
			return;
		}

		temp = temp->m[ch];

		if (temp->isTerminal)
		{
			string out = document.substr(i,j-i+1);
			m[out] = true;
		}
	}

}

void documentSearch(string document, vector<string> words)
{

	Trie t;

	for (auto i : words)
	{
		t.insert(i);
	}

	unordered_map<string, bool> m;

	for (int i = 0; i < document.size(); i++)
	{
		searchHelper(t, document, i, m);
	}

	for(auto w : words){
		if(m[w]){
			cout<<w<<" "<<"True"<<endl;
		}
		else{
			cout<<w<<" "<<"False"<<endl;
		}
	}
}

int main()
{

	string document = "little cute cat is lying on the floor";
	vector<string> word = {"cute cat","ttle","cat","quick","big"};

	documentSearch(document,word);

	return 0;
}
