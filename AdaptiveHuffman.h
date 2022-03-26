#include "node.h"

class AdaptiveHuffman{
private:
	std::vector<node> Tree;
	std::string data;
	std::string output;
	int NYT=0;
	int nodeNo=51;
	int currNode;

public:
	AdaptiveHuffman();
	node createNode(std::string, int, int, int, std::string);
	std::string encode(std::string);
	std::string decode(std::string);

	bool isCharFirst(int, std::string);
	std::string givenCode(char);
	std::string retCodeData(std::string);
	void update(bool flag, std::string);
	void gotoParent(int);
	int findNodeMax(int);
	void switchNodes(int,int);
	void reNumCode(int);
	void display();
};

AdaptiveHuffman::AdaptiveHuffman(){
	Tree.push_back(createNode("NYT", 51, 0, -1, ""));
}

// encode the input text
std::string AdaptiveHuffman::encode(std::string inputText){
	bool firstFlag;
	for(int a=0;a<inputText.length();a++){
		firstFlag=false;
		if(isCharFirst(a, inputText)){	
			firstFlag=true;
			output+=Tree[NYT].code;	
			output+=givenCode(inputText[a]);			
		} else {
			output+=retCodeData(std::string(1,inputText[a]));
		}
		update(firstFlag,std::string(1,inputText[a]));
	}
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

//return true if symbol is first appearance
bool AdaptiveHuffman::isCharFirst(int ind, std::string str){
	for(int a=0;a<ind;a++){
		if(str[a]==str[ind]){
			return false;
		}
	}
	return true;
}

//return code for specific data element
std::string AdaptiveHuffman::givenCode(char ch){
	switch(ch){
		case 'a': return "00000";break;
		case 'b': return "00001";break;
		case 'c': return "00010";break;
		case 'd': return "00011";break;
		case 'e': return "00100";break;
		case 'f': return "00101";break;
		case 'g': return "00110";break;
		case 'h': return "00111";break;
		case 'i': return "01000";break;
		case 'j': return "01001";break;
		case 'k': return "01010";break;
		case 'l': return "01011";break;
		case 'm': return "01100";break;
		case 'n': return "01101";break;
		case 'o': return "01110";break;
		case 'p': return "01111";break;
		case 'q': return "10000";break;
		case 'r': return "10001";break;
		case 's': return "10010";break;
		case 't': return "10011";break;
		case 'u': return "1010";break;
		case 'v': return "1011";break;
		case 'w': return "1100";break;
		case 'x': return "1101";break;
		case 'y': return "1110";break;
		case 'z': return "1111";break;
		default: return "";
	}
}

//return code for the data element
std::string AdaptiveHuffman::retCodeData(std::string str){
	for(int a=0;a<Tree.size();a++){
		if(str==Tree[a].character){
			currNode=a;
			return Tree[a].code;
		}		
	}
	return "";
}

//update the Tree
void AdaptiveHuffman::update(bool flag, std::string str){
	if(flag){
		Tree[NYT].character="-";
		Tree[NYT].leftChild=Tree.size();
		Tree[NYT].rightChild=Tree.size()+1;

		Tree.push_back(createNode("NYT",Tree[NYT].number-2,0,NYT,Tree[NYT].code+"0"));
		Tree.push_back(createNode(str,Tree[NYT].number-1,1,NYT,Tree[NYT].code+"1"));

		Tree[NYT].weight++;
		NYT=Tree[NYT].leftChild;

		currNode=Tree[NYT].parent;
	} else {
		int nodeMax=findNodeMax(currNode);
		if(nodeMax>0){
			switchNodes(currNode,nodeMax);
		}
		Tree[currNode].weight++;
	}
	
	gotoParent(currNode);
}

//goto parent of node
void AdaptiveHuffman::gotoParent(int n){
	int nodeMax;
	while(Tree[n].parent!=-1){
		n=Tree[n].parent;
		nodeMax=findNodeMax(n);

		if(nodeMax<0){
			Tree[n].weight++;
		} else {
			switchNodes(n,nodeMax);
			reNumCode(0);
			Tree[n].weight++;
			nodeNo=51;
		}
	}
}

//return the node index with max node number. in block else -1
int AdaptiveHuffman::findNodeMax(int n){
	int w=Tree[n].weight;
	int index=n;

	for(int a=0;a<Tree.size();a++){
		if(Tree[a].weight==w&&Tree[a].number>Tree[index].number){
			index=a;
		}
	}

	if(index==n){
		return -1;
	}
	
	return index;
}

//switch the nodes
void AdaptiveHuffman::switchNodes(int a,int b){

	//swap parent's child
	int parent_a=Tree[a].parent;
	int parent_b=Tree[b].parent;
	int parent_a_left=Tree[parent_a].leftChild;
	int parent_a_right=Tree[parent_a].rightChild;
	int parent_b_left=Tree[parent_b].leftChild;
	int parent_b_right=Tree[parent_b].rightChild;


	//swap number.
	int temp=Tree[a].number;
	Tree[a].number=Tree[b].number;
	Tree[b].number=temp;

	//swap code
	std::string str=Tree[a].code;
	Tree[a].code=Tree[b].code;
	Tree[b].code=str;

	//swap parent
	temp=Tree[a].parent;
	Tree[a].parent=Tree[b].parent;
	Tree[b].parent=temp;

	// swap parents chid
	if(parent_a_left==a){
		Tree[parent_a].leftChild=b;
	} else {
		Tree[parent_a].rightChild=b;
	}

	if(parent_b_left==b){
		Tree[parent_b].leftChild=a;
	} else {
		Tree[parent_b].rightChild=a;
	}
}

//rearrange node number. and codes
void AdaptiveHuffman::reNumCode(int n){
	if(Tree[n].leftChild!=-1&&Tree[n].rightChild!=-1){
		Tree[Tree[n].rightChild].number=(--nodeNo);
		Tree[Tree[n].leftChild].number=(--nodeNo);

		Tree[Tree[n].leftChild].code=Tree[n].code+"0";
		Tree[Tree[n].rightChild].code=Tree[n].code+"1";
			
		reNumCode(Tree[n].rightChild);
		reNumCode(Tree[n].leftChild);
	}	
}

//display
void AdaptiveHuffman::display(){
	for(int a=0;a<Tree.size();a++){
		std::cout<<"\n"<<a<<" character:"<<Tree[a].character<<" weight:"<<Tree[a].weight<<" number:"<<Tree[a].number<<" l:"<<Tree[a].leftChild<<" r:"<<Tree[a].rightChild<<" p:"<<Tree[a].parent<<" code:"<<Tree[a].code;
	}
	std::cout<<"\n";
	system("pause");
}