#include<bits/stdc++.h>
#include "AdaptiveHuffman.h"

int main(int argc, char const *argv[])
{

	std::string testDecodedString1 = "aardvark";
	std::string testDecodedString2 = "x";
	std::string testDecodedString3 = "saurav";

	std::string testEncodedString1 = "00000101000100000110001011010110001010";
	std::string testEncodedString2 = "1101";




	AdaptiveHuffman AH;

	std::cout<<"\n";
	std::cout<<"\n\n----------Encode Test1:------------";
	std::cout<<"\nInput String:\t"<<testDecodedString1;
	std::string encodedTestString1 = AH.encode(testDecodedString1);
	if(encodedTestString1 == testEncodedString1){
		std::cout<<"\n\nPASSED!\n";
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t"<< encodedTestString1;
	std::cout<<"\nExpected output\t"<< testEncodedString1;

	std::cout<<"\n";
	std::cout<<"\n\n----------Encode Test2:------------";
	std::cout<<"\nInput String:\t"<<testDecodedString2;
	std::string encodedTestString2 = AH.encode(testDecodedString2);
	if(encodedTestString2 == testEncodedString2){
		std::cout<<"\n\nPASSED!\n";
	} else {
		std::cout<<"\n\nFAILED!\n";
	}
	std::cout<<"\nActual output:\t"<< encodedTestString2;
	std::cout<<"\nExpected output\t"<< testEncodedString2;



	std::cout<<"\n\n";
	system("pause");
	return 0;
}