# Adaptive-Huffman-Coding
A program to encode/decode an input string using Adaptive Huffman Coding Algorithm (vectors used).
  
  ## Table of Content
  - [Technologies](#technologies)
  - [Setup](#setup)
  - [Working](#working)
  - [Screenshots](#screenshots)
  - [Contributors](#contributors)
  
  ## Technologies
  - C++
  
  ## Setup
  How to start the program:-
  1. Make sure you have an environment to run C++ programs.
  2. Go to your **command line** in the directory.
  3. Compile the c++ code using `g++ -o "my file name.cpp" "Adaptive Huffman encode.cpp"`.
  4. Now run `./"my file name"`.
  
  ## Working
  ### The cpp files:-
  - It will ask you to enter the input text.
  - After the input press `Enter`.
  - You will get it's encode/decoded form.
 
  ### The header files:-
  - Paste the `AdaptiveHuffman.h` and `Node.h` file in your desired directory.
  - Import and use the header with following code :-

  include the header
  ```
          #include "AdaptiveHuffman.h"
  ```
  use the header
  ```
          AdaptiveHuffman AH;
          
          // input parameter is a plain text which you want to encode
          // returns the encoded std::string for input parameter
          AH.encode("aardvark");                               
          
          // input parameter is a encode text which you want to decode
          // returns the decoded std::string for input parameter
          AH.decode("00000101000100000110001011010110001010"); 
          
  ```
  
  ## Screenshots
  Some screenshots of the program:-
  - *Adaptive Huffman Encode*<br />
  ![Adaptive Huffman Encode](https://github.com/SKR301/Adaptive-Huffman-Coding/blob/master/ScreenShots/encode.png)
  - *Adaptive Huffman Decode*<br />
  ![Adaptive Huffman Decode](https://github.com/SKR301/Adaptive-Huffman-Coding/blob/master/ScreenShots/decode.png)
  
  ## Contributors
  @SKR301- [Saurav Kumar](https://github.com/SKR301)
