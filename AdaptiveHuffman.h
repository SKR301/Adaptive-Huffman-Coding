#include "node.h"

class AdaptiveHuffman{
private:
	std::vector<node> Tree;

public:
	AdaptiveHuffman();
	node createNode(std::string, int, int, int, std::string);
	std::string encode(std::string);
	std::string decode(std::string);
};

AdaptiveHuffman::AdaptiveHuffman(){
	Tree.push_back(createNode("NYT", 51, 0, -1, ""));
}

std::string AdaptiveHuffman::encode(std::string inputText){
	// bool firstFlag;
	// for(int a=0;a<data.length();a++){
	// 	firstFlag=false;
	// 	if(first(a)){										
	// 		firstFlag=true;
	// 		output+=tree[NYT].code;
	// 		output+=givenCode(data[a]);
	// 	} else {
	// 		output+=retCodeData(string(1,data[a]));
	// 	}

	// 	update(firstFlag,string(1,data[a]));
	// }
	return "";
}

std::string AdaptiveHuffman::decode(std::string){

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