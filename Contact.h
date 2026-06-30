#ifndef CONTACT_H
#define CONTACT_H
#include <string>
using namespace std;
class Contact{
public:
    string name,phone;
    Contact(){}
    Contact(string n,string p){name=n;phone=p;}
};
#endif
