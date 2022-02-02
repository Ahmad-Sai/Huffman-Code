#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <math.h>
#include <bitset>
#include "priorityqueue.hpp"

using namespace std;

void decode(){
    fstream out;
    out.open("binaryfile");
    out >> std::noskipws;
    vector<int> asc;
    unsigned char c;
    // read in file 
    while (out >> c){
        int k = c;
        asc.push_back(k);
     }

    //convert ints to a binary string
    string longString = "";
    for(int i=0;i<asc.size()-2; i++){
        longString += bitset<8>(asc[i]).to_string();
    }
    
    // reverse the specialBit to its orignal value
    string specialBit = std::bitset<8>(asc[asc.size()-2]).to_string();
    int addedZeros = asc[asc.size()-1];    // number of added zeros to specialBit
    string newByte = "";

    // retrieve the special bit
    for(int i =0; i<8-addedZeros; i++){
        newByte += specialBit[i];
    }
    
    longString += newByte;
    
    
    // reconstruct huffman tree
    node* root = new node;
    node* currNode;
    ifstream file("codesFile.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            currNode = root;
            for(int i =0;i<line.length(); i++){
                if(line[i]=='0'){
                    if(currNode->leftChild == NULL){
                        node* temp = new node;
                        currNode->leftChild = temp;
                        currNode = temp;
                    } else{
                        currNode = currNode->leftChild;
                    }
                }
                 if(line[i]=='1'){
                    if(currNode->rightChild == NULL){
                        node* temp = new node;
                        currNode->rightChild = temp;
                        currNode = temp;
                    } else{
                        currNode = currNode->rightChild;
                    }
                }
                if(line[i] ==' '){
                    currNode->letter =line[line.length()-1]; 
                    break;
                }
            }
        }
    }
    file.close();
    
    
    // traverses the tree and decodes the file
    string newString = "";
    node* curr = root;
    bool term = false;
    
    for(int i=0;i<longString.length(); i++){
        term = false;
        if(longString[i] == '0'){
            curr = curr->leftChild;
        } else if(longString[i] == '1'){
            curr = curr->rightChild;
        }
        
        if(curr->leftChild == NULL && curr->rightChild==NULL){
            newString += curr->letter;
            curr = root;
            term = true;
        }
    }
    cout << newString<<endl;
}
