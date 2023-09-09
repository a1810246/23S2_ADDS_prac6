
class Node
{
    public:
        Node();
        Node(int data, Node* link);

    private:
        int data;
        Node* link;
};