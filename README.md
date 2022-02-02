# Huffman-Code

**What is Huffman Coding?**

Huffman coding is an algorithm that performs lossless data compression. The Huffman coding algorithm generates binary codes for each letter in a specific text file based on its frequency. High frequency characters receive shorter Huffman codes, whereas low frequency characters get longer codes. The Huffman code algorithm was designed so that no two Huffman codes of a specific character are the same, which gives it its strength. Having unique Huffman codes for each character means that performing compression and decompression on a file, with the use of _trees_, is quick, easy, and efficent.

This implementation of the Huffman Coding algorithm takes in a text file and performs compression on it using _encode.cpp_. Running _encode.cpp_ results in a binary file, as well as a _codesFile_, which contains the Huffman encodings for each character. To decompress the binary file, you need to run _decode.cpp_, which reads in the file _codesFile_ and reconstructs the Huffman tree based on its contents. Decoding the file is simple, the program traverses the Huffman tree, until it finds the specific Huffman code in the _encodeString_, then it extracts that character and puts it in a new string.

The program uses:
-  A hash function to calculate the ascii encoding of a character
-  A prioirty queue that holds the characters with their frequencies
-  A huffman tree that holds the encodings for each character

**_For the program to run correctly make sure the text file you want to compress doesn't have any blank lines or newline breaks. And you need to have an empty text file named "codesFile.txt" in your current directory!_**

To change the file you want to compress, go to **_encode.cpp_** and change **_Line 39_** to take in the name of the file you want to compress. 

To compile use: g++ main.cpp priorityqueue.cpp priorityqueue.hpp

Below is an example of **_main.cpp _** being run on a text file named **_lorem.txt_** of size 14990 bytes. The program outputs to files, compress version of the original file that is almost 50% smaller. 

Original file is: 14990 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867970-6b858cef-4f2f-4ef1-8d0f-aeca1835d4aa.png)

Size of binary file: 7892 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867850-d8064395-720f-4b3e-ae7c-7e3fe54c286d.png)

Similar results were seen from running the program on a text file that contains the book "DUNE".
