#include "Node.h"

Node::Node(int data, Node* link):data(data),link(link){

}

Node::Node(){
    data = 0;
    this->link = nullptr;
}

