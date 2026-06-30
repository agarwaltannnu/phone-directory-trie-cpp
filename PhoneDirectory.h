#ifndef PHONE_DIRECTORY_H
#define PHONE_DIRECTORY_H
#include "Trie.h"
class PhoneDirectory{
    Trie directory;
public:
    void loadData(string);
    void menu();
    void searchByPhone();
};
#endif
