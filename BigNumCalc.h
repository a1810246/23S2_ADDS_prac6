#include<iostream>
#include<list>
using namespace std;

class bigNumCalc
{
    public:
        list<int> buildBigNum(string numString);
        list<int> add(list<int> num1, list<int> num2);
        list<int> sub(list<int> num1, list<int> num2);
        list<int> mul(list<int> num1, list<int> num2);

};