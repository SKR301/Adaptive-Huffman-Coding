#include "node.h"

class AdaptiveHuffman{
private:
	std::vector<node> Tree;

public:
	AdaptiveHuffman();
	node createNode(std::string, int, int, int, std::string);
	std::string encode();
	std::string decode();
};

AdaptiveHuffman::AdaptiveHuffman(){
	Tree.push_back(createNode("NYT", 51, 0, -1, ""));
	std::cout<<Tree[0].code<<Tree[0].parent<<Tree[0].rightChild<<Tree[0].leftChild<<Tree[0].weight<<Tree[0].number<<Tree[0].character;
}

std::string AdaptiveHuffman::encode(){

	return "";
}

std::string AdaptiveHuffman::decode(){

	return "";
}

node AdaptiveHuffman::createNode(std::string str, int n, int freq,int p, std::string c){
	node temp;
	temp.character = str;
	temp.number = n;
	temp.weight = freq;
	temp.leftChild = -1;
	temp.rightChild = -1;
	temp.parent = p;
	temp.code = c;
	
	return temp;
}