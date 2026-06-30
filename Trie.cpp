#include "Trie.h"
Trie::Trie(){root=new TrieNode();}
void Trie::insert(string name, string phone)
{
    if(searchExact(name))
    {
        cout << "Contact already exists!\n";
        return;
    }

    TrieNode *current = root;

    for(char ch : name)
    {
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        int index;

        if(ch == ' ')
            index = 26;
        else
            index = ch - 'a';

        if(current->children[index] == nullptr)
            current->children[index] = new TrieNode();

        current = current->children[index];
    }

    current->isEnd = true;
    current->phone = phone;
}
void Trie::search(string prefix)
{
    TrieNode *current = root;

    for(char ch : prefix)
    {
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        int index;

        if(ch == ' ')
            index = 26;
        else
            index = ch - 'a';

        if(current->children[index] == nullptr)
        {
            cout << "No Contact Found!\n";
            return;
        }

        current = current->children[index];
    }

    displayContacts(current, prefix);
}
void Trie::displayAll()
{
    cout << "\n===== CONTACT LIST =====\n\n";
    displayContacts(root, "");
}
void Trie::displayContacts(TrieNode *node, string word)
{
    if(node == nullptr)
        return;

    if(node->isEnd)
        cout << word << " : " << node->phone << endl;

    for(int i = 0; i < 27; i++)
    {
        if(node->children[i] != nullptr)
        {
            char ch;

            if(i == 26)
                ch = ' ';
            else
                ch = 'a' + i;

            displayContacts(node->children[i], word + ch);
        }
    }
}
bool Trie::searchExact(string name)
{
    TrieNode *current = root;

    for(char ch : name)
    {
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        int index;

        if(ch == ' ')
            index = 26;
        else
            index = ch - 'a';

        if(current->children[index] == nullptr)
            return false;

        current = current->children[index];
    }

    return current->isEnd;
}
bool Trie::remove(string name)
{
    TrieNode *current = root;

    for(char ch : name)
    {
        if(ch >= 'A' && ch <= 'Z')
            ch += 32;

        int index = (ch == ' ') ? 26 : ch - 'a';

        if(current->children[index] == nullptr)
            return false;

        current = current->children[index];
    }

    if(current->isEnd)
    {
        current->isEnd = false;
        current->phone = "";
        return true;
    }

    return false;
}