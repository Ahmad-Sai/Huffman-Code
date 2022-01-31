#include <iostream>
#include <vector>
#include "priorityqueue.hpp"

using namespace std;

PriorityQueue::PriorityQueue(vector<letter> letters){
    
    // sorts the nodes based on priority
    
    for(int i =0; i < letters.size()-1; i++){
        for (int j = 0; j < letters.size()-i-1; j++){
            if (letters[j].frequency > letters[j+1].frequency){
                letter temp = letters[j+1];
                letters[j+1] = letters[j];
                letters[j] = temp;
            }
        }
    }
    
    // inserts nodes into a priority queue
    vector<node*> nodes;
    for(int i=0; i<letters.size(); i++){
        node *temp = new node;
        temp->value = letters[i].frequency;
        temp->letter = letters[i].letter;
        nodes.push_back(temp);
        letterVect.push_back(nodes[i]);
    }    
}

void PriorityQueue::insertNode(node* newNode){
    bool found = false;
    for(int i=0; i<letterVect.size(); i++){
        if(newNode->value < letterVect[i]->value){
            auto it = letterVect.begin() + i;
            letterVect.insert(it, newNode);
            found = true;
            break;
        }
    }
    if (!found){
        letterVect.push_back(newNode);
    }
}

void PriorityQueue::PrintQueue(){
     for(int i =0; i < letterVect.size(); i++){
         cout << letterVect[i]->letter << " -- " << letterVect[i]->value << endl;
     }
 }    

node* PriorityQueue::dequeue(){
    node* first = letterVect[0];
    letterVect.erase(letterVect.begin());
    return first;
}

int PriorityQueue::sizeQ(){
    return letterVect.size();
}
