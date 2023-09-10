#ifndef NODE_H
#define NODE_H
#include<list>
class Node
{
    public:
        friend class LinkedList;
        Node();
        Node(int data, Node* link);

    private:
        int data;
        Node* link;
};

#endif 