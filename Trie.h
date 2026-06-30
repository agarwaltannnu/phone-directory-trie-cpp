#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <string>
using namespace std;
class TrieNode{
public:
    TrieNode* children[27];
    bool isEnd;
    string phone;
    TrieNode(){isEnd=false;phone="";for(int i=0;i<27;i++)children[i]=nullptr;}
};
class Trie{
    TrieNode* root;
    void displayContacts(TrieNode*,string);
public:
    Trie();
    void insert(string,string);
    void search(string);
    bool searchExact(string);
    bool remove(string name);
    void displayAll();
};
#endif
