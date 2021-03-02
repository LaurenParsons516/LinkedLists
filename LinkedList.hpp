#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        LinkedList();
        void display();
        void addEnd(int value);
        int removeEnd();
        void addFront(int value);
        int removeFront();
};