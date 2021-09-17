#include<iostream>
#include<fstream>
using namespace std;

//node
class Node{
	public:
	string data;
	Node* next;
	Node* prev;
};


//push
void push(Node** ref,string newData){
	Node* newNode=new Node();
	newNode->data=newData;
	newNode->next=(*ref);
	newNode->prev=NULL;
	if((*ref)!=NULL){
		(*ref)->prev=newNode;
	(*ref)=newNode;
	}
}

void insertAfter(Node* prevNode,string newData){
	if(prevNode==NULL){
		cout<<"given node not found";
		return;
	}
	Node* newNode=new Node();
	newNode->data=newData;
	newNode->next=prevNode->next;
	prevNode->next=newNode;
	newNode->prev=prevNode;
	if(newNode->next!=NULL){
		newNode->next->prev=newNode;
	}
}

void append(Node** ref,string newData){
	Node* newNode=new Node();
	Node* last = * ref;
	newNode->data=newData;
	newNode->next=NULL;
	if(*ref==NULL){
		newNode->prev=NULL;
		*ref=newNode;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=newNode;
	newNode->prev=last;
	return;
}


//for printing template
void printList(Node* node){
	Node* last;
	cout<<"\n forward direction";
	while(node!=NULL)
	{
		cout<<" "<<node->data<<" ";
		last = node;
		node = node->next;
	}
	cout<<"\n reverse direction";
	while(last!=NULL)
	{
		cout<<" "<<last->data<<" ";
		last = last->prev;
	}
}

int main(){
	ofstream file("templates.txt");
	ifstream readFile("templates.txt");
	string texts;
	file<<"Hello world amaro porano jaha chay";
	file.close();
	while(getline(readFile,texts));

	Node* head=NULL;
	append(&head,"hi");
	push(&head,"hello");
	push(&head,"mayere");
	append(&head,"chudi");
	insertAfter(head->next,"tore");
	printList(head);

	
}