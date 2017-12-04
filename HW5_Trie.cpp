/*
 * Author : Marc Greenfield
 * Date : 12/1/17
 * Homework 5 - Trie dictionary
 * Used theoryofprogramming.com to try to get this to work but could not figure it out for some reason
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define ALPHABET 25

using namespace std;

class TrieNode{
public:
    TrieNode* parent;
    TrieNode* children[ALPHABET];
    vector<int> occurences;
};

class TrieTree{
public:
    TrieNode* root;

    TrieTree(){root = (TrieNode*) calloc(1, sizeof(TrieNode));}

    void insert (char text[], int index)
    {
        vector<char> word(text, text + strlen(text));
        TrieNode* temp = root;

        int i = 0;

        while (i < word.size()){
            if (temp->children[word[i] - 'a'] == NULL ){
                temp -> children[word[i] - 'a'] = (TrieNode*) calloc(1, sizeof(TrieNode));
                temp -> children[word[i] - 'a'] -> parent = temp;
            }
            temp = temp->children[word[i]-'a'];
            ++i;
        }
        temp -> occurences.push_back(index);
    }

    bool searchWord(TrieNode* trie_tree, string text){
        vector <char> word (text,text +strlen(text));
        TrieNode* temp = trie_tree;

        while (word.size() != 0){
            if (temp ->children[wor[0] -'a'] != NULL){
                temp = temp->children[word[0]-'a'];
                word.erase(word.begin());
            }
            else{
                break;
            }
        }
        if (word.size() == 0 && temp->occurences.size() != 0){
            return true;
        }
        else{
            return false;
        }
    }
}


int main() {
	TrieTree t;
	ifstream f ("dict.txt");
	string word;
    int i = 0;
	while(f >> word){
		t.insert(word, i);
        i++;
	}

	ifstream g ("hw5.txt");
	string check;
	while(g >> check){
        bool val = t.searchWord(t.root, check);
        if (val == true){
            cout << check + "True" << endl;
        }
	}
}
