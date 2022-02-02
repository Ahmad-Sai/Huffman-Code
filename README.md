# Huffman-Code

**What is Huffman Coding?**

Huffman coding is an algorithm that performs lossless data compression. The Huffman coding algorithm generates binary codes for each letter in a specific text file based on its frequency. High frequency characters receive shorter Huffman codes, whereas low frequency characters get longer codes. The Huffman code algorithm was designed so that no two Huffman codes of a specific character are the same, which gives it its strength. Having unique Huffman codes for each character means that performing compression and decompression on a file, with the use of _trees_, is quick, easy, and efficent.

This implementation of the Huffman Coding algorithm takes in a file named _lorem.txt_ with the size of 14990 bytes and performs compression on it using _encode.cpp_. Running _encode.cpp_ results in a binary file that is 7892 bytes, which is almost half as large as the original file, as well as a _codesFile_ of size 601 bytes, which contains the Huffman encodings for each character. To decompress the binary file, you need to run _decode.cpp_, which reads in the file _codesFile_ and reconstructs the Huffman tree based on its contents. Decoding the file is simple, the program traverses the Huffman tree, until it finds the specific Huffman code in the _encodeString_, then it extracts that character and puts it in a new string. This program was made possible by implementing a Huffman tree and using priority queues.


The program uses:
-  A hash function to calculate the ascii encoding of a character
-  A prioirty queue that holds the characters in their frequencies
-  A huffman tree that holds the encodings for each character

_main.cpp_ is the driver of the program and automatically encodes and decodes the file for you.


Original file is: 14990 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867970-6b858cef-4f2f-4ef1-8d0f-aeca1835d4aa.png)

Size of binary file: 7892 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867850-d8064395-720f-4b3e-ae7c-7e3fe54c286d.png)

Size of codesFile: 601 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867908-598c4f53-00f2-46c1-b670-6686a7a3948f.png)


After the huffman coding alogirthim was run on _lorem.txt_ we see that the file is almost 50% smaller in size.
