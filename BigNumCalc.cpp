#include "BigNumCalc.h"

list<int> bigNumCalc::buildBigNum(string numString)
{
    list<int>bigNum;
    int length = numString.length();

    for(int i=0; i<length; i++)
    {
        //Converting string to int by minus '0'
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
            c=c%10;
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

list<int> bigNumCalc::sub(list<int> num1, list<int> num2)
{
    list<int> result; // 存储结果的链表
    int borrow = 0;   // 借位初始化为0
    
    num1.reverse();
    num2.reverse();
    
    list<int>::iterator it1 = num1.begin();
    list<int>::iterator it2 = num2.begin();

    // 从个位开始逐位相减
    while (it1 != num1.end() || it2 != num2.end())
    {
        int n1 = 0, n2 = 0;
        
        // 如果链表1非空，取出第一个元素
        if (it1 != num1.end())
        {
            n1 = *it1;
            it1++;
        }

        // 如果链表2非空，取出第一个元素
        if (it2 != num2.end())
        {
            n2 = *it2;
            it2++;
        }

        // 计算当前位的差值，考虑借位
        int diff = n1 - n2 - borrow;

        // 如果差值小于0，需要借位
        if (diff < 0)
        {
            diff += 10;
            borrow = 1; // 设置借位为1
        }
        else
        {
            borrow = 0; // 没有借位
        }

        // 将差值添加到结果链表中
        result.push_back(diff);
    }

    // 移除结果链表前面的0（如果有）
    while (!result.empty() && result.back() == 0)
    {
        result.pop_back();
    }

    // 如果结果链表为空，说明两数相等，返回一个包含0的链表
    if (result.empty())
    {
        result.push_back(0);
    }

    result.reverse();
    return result;
}




