#include<iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len)
{
    head = nullptr;
    for(int i=0; i<len; i++){
    insertPosition(i+1, array[i]);
    }
}

LinkedList::~LinkedList()
{

}

void LinkedList::insertPosition(int pos, int newNum)
{
    if(head == nullptr || pos<=1)
    {
        head = new Node(newNum, head);
    }
}
