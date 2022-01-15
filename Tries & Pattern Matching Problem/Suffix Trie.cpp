#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node{
	public:

	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}

};

class Trie{

	public:
	Node* root;

	Trie(){
		root = new Node('\0');
	}

	void insert_helper(string word){

		Node* temp = root;

		for(auto ch : word){

			if(temp->m.count(ch)==0){
				Node*n = new Node(ch);
				temp->m[ch] = n;
			}

			temp = temp->m[ch];
		}

		temp->isTerminal = true;

	}

	bool search(string word){

		Node* temp = root;

		for(auto ch : word){

			if(temp->m.count(ch)==0){
				return false;
			}

			temp = temp->m[ch];
		}

		if(temp->isTerminal){
			return true;
		}
		return false;
	}

	void insert(string word){

		for(int i=0;i<word.size();i++){
			insert_helper(word.substr(i));
		}
	}
};


int main(){

	vector<string> word = {"hello"};

	Trie t;

	for(auto i : word){
		t.insert(i);
	}

	cout<<"Enter number of queries"<<endl;
	int q;
	cin>>q;

	string search_word;

	while(q--){
		cin>>search_word;

		if(t.search(search_word)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}



	return 0;
}
