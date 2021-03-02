class Node
{
    private:
        int payload;
        Node* nextNode;
        
    
    public:
        Node(int payload);
        void setNextNode(Node* n);
        Node* getNextNode();
        int getPayload();
};