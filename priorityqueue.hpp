#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <vector>

using namespace std;


struct letter{
    char letter;
    int frequency;
};

struct node{
    char letter = '\0';
    int value = 0;
    node *leftChild = NULL;
    node *rightChild = NULL;
    
};

class PriorityQueue{
    private:
        vector<node*> letterVect;
    
    public:
        PriorityQueue(vector<letter> letters);
        void insertNode(node* newNode);
        void PrintQueue();
        node* dequeue();
        int sizeQ();
};

#endif
