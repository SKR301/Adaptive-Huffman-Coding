#include "node.h"

class AdaptiveHuffman{
private:
	std::vector<node> Tree;
	std::string data;
	std::string output;
	std::vector<node>tree;
	int NYT=0;
	int nodeNo=51;
	int currNode;

public:
	AdaptiveHuffman();
	node createNode(std::string, int, int, int, std::string);
	std::string encode(std::string);
	std::string decode(std::string);

	bool isCharFirst(int ind);
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
		if(isCharFirst(a)){										
			firstFlag=true;
			output+=tree[NYT].code;
			output+=givenCode(data[a]);
		} else {
			output+=retCodeData(std::string(1,data[a]));
		}

		update(firstFlag,std::string(1,data[a]));
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
bool AdaptiveHuffman::isCharFirst(int n){
	for(int a=0;a<n;a++){
		if(data[a]==data[n]){
			return false;
		}
	}
	return true;
}

//return code for specific data element
std::string AdaptiveHuffman::givenCode(char str){
	switch(str){
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
	for(int a=0;a<tree.size();a++){
		if(str==tree[a].character){
			currNode=a;
			return tree[a].code;
		}		
	}
	return "";
}

//update the tree
void AdaptiveHuffman::update(bool flag, std::string str){
	if(flag){
		tree[NYT].character="-";
		tree[NYT].leftChild=tree.size();
		tree[NYT].rightChild=tree.size()+1;

		createNode("NYT",tree[NYT].number-2,0,NYT,tree[NYT].code+"0");
		createNode(str,tree[NYT].number-1,1,NYT,tree[NYT].code+"1");

		tree[NYT].weight++;
		NYT=tree[NYT].leftChild;

		currNode=tree[NYT].parent;
	} else {
		int nodeMax=findNodeMax(currNode);
		if(nodeMax>0){
			switchNodes(currNode,nodeMax);
		}
		tree[currNode].weight++;
	}
	
	gotoParent(currNode);
}

//goto parent of node
void AdaptiveHuffman::gotoParent(int n){
	int nodeMax;
	while(tree[n].parent!=-1){
		n=tree[n].parent;
		nodeMax=findNodeMax(n);

		if(nodeMax<0){
			tree[n].weight++;
		} else {
			switchNodes(n,nodeMax);
			reNumCode(0);
			tree[n].weight++;
			nodeNo=51;
		}
	}
}

//return the node index with max node number. in block else -1
int AdaptiveHuffman::findNodeMax(int n){
	int w=tree[n].weight;
	int index=n;

	for(int a=0;a<tree.size();a++){
		if(tree[a].weight==w&&tree[a].number>tree[index].number){
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
	int parent_a=tree[a].parent;
	int parent_b=tree[b].parent;
	int parent_a_left=tree[parent_a].leftChild;
	int parent_a_right=tree[parent_a].rightChild;
	int parent_b_left=tree[parent_b].leftChild;
	int parent_b_right=tree[parent_b].rightChild;


	//swap number.
	int temp=tree[a].number;
	tree[a].number=tree[b].number;
	tree[b].number=temp;

	//swap code
	std::string str=tree[a].code;
	tree[a].code=tree[b].code;
	tree[b].code=str;

	//swap parent
	temp=tree[a].parent;
	tree[a].parent=tree[b].parent;
	tree[b].parent=temp;

	// swap parents chid
	if(parent_a_left==a){
		tree[parent_a].leftChild=b;
	} else {
		tree[parent_a].rightChild=b;
	}

	if(parent_b_left==b){
		tree[parent_b].leftChild=a;
	} else {
		tree[parent_b].rightChild=a;
	}
}

//rearrange node number. and codes
void AdaptiveHuffman::reNumCode(int n){
	if(tree[n].leftChild!=-1&&tree[n].rightChild!=-1){
		tree[tree[n].rightChild].number=(--nodeNo);
		tree[tree[n].leftChild].number=(--nodeNo);

		tree[tree[n].leftChild].code=tree[n].code+"0";
		tree[tree[n].rightChild].code=tree[n].code+"1";
			
		reNumCode(tree[n].rightChild);
		reNumCode(tree[n].leftChild);
	}	
}

//display
void AdaptiveHuffman::display(){
	for(int a=0;a<tree.size();a++){
		std::cout<<"\n"<<a<<" character:"<<tree[a].character<<" weight:"<<tree[a].weight<<" number:"<<tree[a].number<<" l:"<<tree[a].leftChild<<" r:"<<tree[a].rightChild<<" p:"<<tree[a].parent<<" code:"<<tree[a].code;
	}
	std::cout<<"\n";
	system("pause");
}