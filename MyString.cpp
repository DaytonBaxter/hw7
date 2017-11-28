//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"


MyString::MyString()
{

}

MyString::MyString(const char *character)
{
    //cout << "Valueo "<< character << endl;
    int val = 1;
    while(character[val] != '\0')
    {
        val++;
    }
    nlength = val;

   if(nlength > 1) {
       internalCString = make_unique<char[]>(nlength);
        val = 0;
        while (character[val] != '\0') {

            internalCString[val] = character[val];
            val++;
        }

        cout << "Value ";
        val = 0;
        while (internalCString[val] != '\0') {
            cout << internalCString[val];
            val++;
        }
        cout << " Val is "<<val<< " and " << nlength << endl;
   }
    else{
       internalCString = make_unique<char[]>(1);
       internalCString = nullptr;
   }

}

char *MyString::getInternalCString() const
{
    return internalCString.get();
}

int MyString::compareStr(const MyString &lhs, const MyString &rhs) {
    int answer = 0;
    int index;
    while(lhs.internalCString[index] )
    {

    }
    return 1;
}
