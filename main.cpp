#include<iostream>
#include<fstream>
using namespace std;

//node
class Node{
	public:
	int n;
	string data;
	Node* next;
	Node* prev;
};

void display(Node* node);

//push
void push(Node** ref,string newData,int n){
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

void append(Node** ref,string newData,int newN){
	Node* newNode=new Node();
	Node* last = * ref;
	newNode->data=newData;
	newNode->n=newN;
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
	cout<<"\n forward direction\n\n";
	while(node!=NULL)
	{
		cout<<" "<<node->data<<" ";
		last = node;
		node = node->next;
	}
	cout<<"\n reverse direction\n\n";
	while(last!=NULL)
	{
		cout<<" "<<last->data<<" ";
		last = last->prev;
	}
}


//saving templates
void saveFile(Node* node){
	Node* last;
	cout<<"\nsaving file\n";
	ofstream saving("templates.txt");
	while(node!=NULL){
		saving<<node->data<<"\n\n";
		last=node;
		node=node->next;
	}

}

void showTemplates(Node* node){
	int a;
	cout<<"Press 1 \nPress 2 \nPress 3\nPress 4\n";
	cin>>a;
	Node* last;
		while(node!=NULL){
		if(node->n==a){
			cout<<node->data<<endl;
			break;
		}
		last=node;
		node=node->next;
		cout<<endl;
	}
		display(node);
}
	
void display(Node* node){
		Node* last;
		int a;
		cout<<node;
		cout<<"Press 1 to see next\nPress 2 to see previous\nPress 0 to exit\n";
		cin>>a;
		while(a==0 && node!=NULL){
		if(a==1){ 
			cout<<"hello world";
			node=node->next;
			cout<<node->data;
		}
		else if(a==2){
			node=node->prev;
			cout<<node->data;
		}
		else if(a==0)
			showTemplates(node);
		}
}



int main(){
	Node* head=NULL;
	append(&head,"are vaya",1);
	append(&head,"chudi tomare",2);
	append(&head,"mayere chudi",3);
	append(&head,"choda chodir mayere chudi",4);
	//append(&head,"Subject:Congragulating on brillian success.\nHi name,\nI am glad to know that you are well. I heared about your promotion.I want to congratulate you.\nFrom name,\nDate 20/Semptember");
	saveFile(head);
	//printList(head);
	showTemplates(head);
	
}
