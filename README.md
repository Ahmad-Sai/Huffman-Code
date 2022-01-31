# Huffman-Code

**What is Huffman Coding?**

Huffman coding is an algorithim that performs lossless data compression. The huffman coding algorithim generates binary codes for each letter in a specific text file based on its frequency. More freuqenc characters receive a smaller huffman code, whereas low frequenecy characters get long huffman codes. The huffman code algorithim was designed so that no two huffman codes of a specif character are the same, which gives it its strength. Having unqiue huffman codes for each character means that perform compression and decomrpession on a file is with the use of _trees_ is quick and easy.

Original file is: 14990 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867970-6b858cef-4f2f-4ef1-8d0f-aeca1835d4aa.png)

Size of binary file: 7892 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867850-d8064395-720f-4b3e-ae7c-7e3fe54c286d.png)

Size of codesFile: 601 bytes:

![image](https://user-images.githubusercontent.com/85080576/151867908-598c4f53-00f2-46c1-b670-6686a7a3948f.png)


After the huffman coding alogirthim was run on _lorem.txt_ we see that the file is almost 50% smaller in size.
