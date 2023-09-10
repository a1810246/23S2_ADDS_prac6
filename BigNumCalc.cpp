#include "BigNumCalc.h"

list<int> bigNumCalc::buildBigNum(string numString)
{
    list<int>bigNum;
    int length = numString.length();

    for(int i=0; i<length; i++)
    {
        //Converting string to int
        bigNum.push_back(numString[i]-'0');
    }

    return bigNum;
}

list<int> bigNumCalc::add(list<int> num1, list<int> num2)
{
    list<int>sum;
    int carry = 0;
    num1.reverse();
    num2.reverse(); 
    list<int>::iterator it1 = num1.begin();
    list<int>::iterator it2 = num2.begin();

    while(it1 != num1.end() || it2 != num2.end())
    {
        int c = carry;
        if(it1 != num1.end())
        {
            c += *it1;
            it1++;
        }

        if(it2 != num2.end())
        {
            c += *it2;
            it2++;
        }

        if(c>=10)
        {
            c=c-10;
            carry=1;
        }
        else
        {
            carry=0;
        }

        sum.push_back(c);
    }
    if(carry>0)
    {
        sum.push_back(1);
    }
    while(!sum.empty() && sum.back()==0)
    {
        sum.pop_back();
    }
    sum.reverse();
    return sum;

}
