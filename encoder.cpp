#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <math.h>
#include <bitset>
#include "priorityqueue.hpp"

using namespace std;

// takes in an character and returns the ascii encoding of it
int hashFunction(char c){
    return int(c);
}


// recursively traverses the huffman tree and encodes the letters
void traverse(fstream &InputFile, node* n, string msg, string encoding[]){
    if(n->leftChild != NULL){
        traverse(InputFile,n->leftChild, msg+"0", encoding);
    } 
    if(n->rightChild != NULL){
        traverse(InputFile,n->rightChild, msg+"1", encoding);
    }
    if(n->leftChild == NULL && n->rightChild==NULL){
        cout << n->letter << " -- " << msg << endl; 
        int index = hashFunction(n->letter);
        encoding[index] = msg;        
        InputFile << msg;
        InputFile << " -- "; 
        InputFile.put(n->letter);
        InputFile << "\n";
    }
}

void encode(){
  char mychar;
    ifstream fin;
    fin.open("lorem.txt");
    fin >> std::noskipws;
    vector<letter> letters;     // vector of different letters in the file and their frequencies
    vector<char> characters;    // vector of different characters in the file 
    bool found;
    int numCharacters = 0;      
    
    // read in file and find different letters and their frequencies
    
    while (fin >> mychar){
        found = false;
        characters.push_back(mychar);
        for(int i=0;i<letters.size();i++){
            if(letters[i].letter == mychar){
                letters[i].frequency++;
                found = true;
                break;
            }
        }
        if (found == false){
            letter c;
            c.letter = mychar;
            c.frequency = 1;
            letters.push_back(c);
        }
        numCharacters++;
    }
    
    PriorityQueue q1(letters);    // intialize priority queue
    
    // perform huffman coding algorithim
    while (q1.sizeQ() > 1){
        
        node *firstNode = q1.dequeue();
        node *secondNode = q1.dequeue();
        node *thirdNode = new node;
        
        
        thirdNode->value = firstNode->value + secondNode->value;
        thirdNode->leftChild = firstNode;
        thirdNode->rightChild = secondNode;
        
        q1.insertNode(thirdNode);
        
    }
    
    // deqeue the root from the priority queue
    node *n = q1.dequeue();
    
    // intialize array for all 128 ascii characters
    string key[128] = {};
    
    
    // travese the huffman tree and insert encoding for each letter into the ascii array
    for(int i = 0; i < characters.size(); i++){
        cout << characters[i];   
    }
    cout << endl;
    fstream encodedFile("codesFile.txt");
    traverse(encodedFile, n, "", key);
    
    string encodedString = "";     // a concatenated string of 1's and 0's for every character 
    int encodedCharacter;
    
    for(int i =0;i < characters.size();i++){   /// changed to -1 because charactes has extra thing at end
        encodedCharacter = hashFunction(characters[i]);
        encodedString += key[encodedCharacter];
    }
    
    int counter = 0;
    
    // creates and array of ints based on the number of bytes in the encodedString
    
    float numBytes = encodedString.length()/8.0;
    int requiredBytes = ceil(numBytes) + 1.0;
    int *bitsToInt = new int[requiredBytes];
    string tempByte = "";
    
    for(int i =0; i < encodedString.length(); i++){
        tempByte += encodedString[i];
        if(tempByte.length() == 8){
            int numRep = stoi(tempByte, 0, 2);
            bitsToInt[((i+1)/8)-1] = numRep;   // converts the string byte into its ascii representation
            tempByte = "";
            counter = 0;
        }
    }
    
    // checks if the last byte has uneven number of bits, if so, add remanding number of 0's to the last byte and record the number of added zeros in the last element of the array
    int numAdded = 0;
    if(tempByte!=""){
        int remandier = 8-tempByte.length();  // number of 0's to add
        for(int i=0;i<remandier; i++){
            tempByte += "0";
            numAdded++;
        }
        bitsToInt[requiredBytes-2] = stoi(tempByte, 0, 2);   // converts the string byte into its ascii representation
    }
    
    bitsToInt[requiredBytes-1] = numAdded;  // record the number of extra 0's that were added to the last byte

    // makes empty file
    ofstream myfile;
    myfile.open ("binaryfile");
    myfile.close();
    
    unsigned char arr[requiredBytes] = {};
    for(int i =0; i<requiredBytes; i++){
        arr[i] = bitsToInt[i];
    }

    // writes to binary file
    fstream ff;
    ff.open("binaryfile");

    for(int i =0; i<requiredBytes;i++){
        ff.write (reinterpret_cast<char*>(&arr[i]), 1);
    }
    ff.close();
}
