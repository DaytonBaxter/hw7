//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"


MyString::MyString()
{

}

/*!
 * Constructor
 * @param receives character
 */
MyString::MyString(const char *character)
{
    int val = 1;
    while(character[val] != '\0')
    {
        val++;
    }
    nlength = val;
   if(nlength > 1) {
       internalCString = make_unique<char[]>(nlength);
        val = 0;
        while (character[val] != '\0')
        {
            internalCString[val] = character[val];
            val++;
        }
        val = 0;
        while (internalCString[val] != '\0')
        {
            val++;
        }
   }
    else
   {
       internalCString = make_unique<char[]>(1);
       internalCString = nullptr;
   }
} // end constructor

/*!
 * Get the internal cstring
 * @return internalCString
 */
char *MyString::getInternalCString() const
{
    return internalCString.get();
}// end getInternalCString

/*!
 * compares unique pointers of characters
 * @param lhs
 * @param rhs
 * @return a number that is the result of the comparison
 */
int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    int index=0;
    while(lhs.internalCString[index] != '\0' && rhs.internalCString[index] != '\0')
    {
        if(lhs.internalCString[index] < rhs.internalCString[index])
        {
            if(lhs.nlength == rhs.nlength)
                return -2;
            return 1;
        }
        else if(lhs.internalCString[index] > rhs.internalCString[index])
        {
            if(lhs.nlength == rhs.nlength)
                return -2;
            return -1;
        }
        if(lhs.nlength == (index +1) && rhs.nlength == (index +1))
        {
            return 0;
        }
        index++;
    }
    if(lhs.internalCString[index] == '\0' && rhs.internalCString[index] != '\0')
        return -1;
    if(rhs.internalCString[index] == '\0' && lhs.internalCString[index] != '\0')
        return 1;
    return 0;
}// end compareStr
