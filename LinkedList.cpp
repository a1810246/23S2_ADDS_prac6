#include<iostream>
#include <limits>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


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
     while (head != nullptr)
    {
        Node* temp = head; // 临时指针指向当前节点
        head = head->link; // 移动头指针到下一个节点
        delete temp;       // 删除当前节点
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    if(head == nullptr || pos<=1)
    {
        head = new Node(newNum, head);
        return;
    }

    Node* curr = head;
    for(int i=1; i<pos-1 && curr->link != nullptr; i++)
    {
        curr = curr->link;
    }

    Node* newNode = new Node(newNum, curr->link);
    curr->link = newNode;
}

bool LinkedList::deletePosition(int pos){
    if(head == nullptr || pos<1)
    {
        return false;
    }
    
    if(pos == 1){
    Node* deleteNode = head;
    head = head -> link;
    delete deleteNode;
    return true;
    }

    else{
        Node* prev = head;
        for(int i=1; i<pos-1 && prev->link!=nullptr; i++)
        {
            prev = prev -> link;
        }

        if(prev->link == nullptr)
        {
            return false;
        }
        else
        {
            Node* deleteNode = prev->link;
            prev->link = deleteNode->link;
            delete deleteNode;
            return true;
        }
    }
}

int LinkedList::get(int pos)
{
    if(pos<1 || head == nullptr)
    {
        return numeric_limits < int >::max();
    }
    else
    {
        Node* curr = head;
        for(int i = 1; i<pos && curr!=nullptr; i++)
        {
            curr = curr->link;
        }
        if(curr == nullptr)
        {
            return numeric_limits < int >::max();
        }
        else
        {
            return curr->data;
        }
    }
}


int LinkedList::search(int target)
{
    int i=1;
    Node* curr = head;
    while(curr != nullptr && curr->data != target)
    {
        curr = curr->link;
        i++;
    }

    if(curr == nullptr)
    {
        return -1;
    }

    return 1;
}

void LinkedList::printList()
{
    if(head == nullptr)
    {
        return;
    }

    Node* curr = head;

    cout << "[";
    while(curr != nullptr)
    {
        /*cout<<curr->data<<" ";
        curr = curr->link;*/
        cout << curr->data;
        if (curr->link != nullptr) {
            cout << " ";
        }
        curr = curr->link;
    }
    cout << "]";
}