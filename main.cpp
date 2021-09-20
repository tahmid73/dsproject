#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//node
class Node{
	public:
	int n;
	string data,salutaition,body;
	//string format[6];
	Node* next;
	Node* prev;
};

void display(Node* node);
void writeEmail(Node* node);

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

void append(Node** ref,string newData,int newN,string newSalutaition,string newBody){
	Node* newNode=new Node();
	Node* last = * ref;
	newNode->data=newData;
	newNode->n=newN;
	newNode->salutaition=newSalutaition;
	newNode->body=newBody;
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
		cout<<"-----------------------";
		cout<<endl;
		cout<<" "<<node->data<<" ";
		cout<<endl;
		cout<<"-----------------------";
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
	//1cout<<"\nsaving file\n";
	ofstream saving("templates.txt");
	while(node!=NULL){
		saving<<node->data<<"\n\n";
		last=node;
		node=node->next;
	}

}

void showTemplates(Node* node){
	int a;
	cout<<"******WELCOME TO AUTO EMAIL WRITEING******"<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"1.Leave Email \n2.Greeting Email\n3.Welcome Email\n4.Offer Email\n";
	cout<<"-----------------------"<<endl;
	cin>>a;
	Node* last;
		while(node!=NULL){
		if(node->n==a){
			cout<<endl;
			cout<<"-----------------------"<<endl;
			cout<<node->data<<endl;
			cout<<"-----------------------"<<endl;
			break;
		}
		last=node;
		node=node->next;
		cout<<endl;
	}
		display(node);
}
//to display all templates
void display(Node* node){
		int a=1;
		//cout<<endl;
		while(a!=0 && node!=NULL){
		if(node->prev!=NULL&& node->next!=NULL){
		cout<<"\n\nPress 1 to see next\nPress 2 to see previous\nPress 3 to select this template\nPress 0 to exit\n\n";
		}
		else if(node->prev==NULL){
			cout<<"\n\nPress 1 to see Next\nPress 0 to exit\nPress 3 to select this template\n\n";
		}
		else if(node->next==NULL){
			cout<<"\n\nPress 2 to see Previous\nPress 3 to select this template\nPress 0 to exit\n\n";
		}
			cin>>a;
		if(a==1){ 
			cout<<endl;
			cout<<"-----------------------";
			cout<<endl;
			node=node->next;
			cout<<" "<<node->data<<" ";
			cout<<endl;
			cout<<"-----------------------";
		}
		else if(a==2){
			node=node->prev;
			cout<<endl;
			cout<<"-----------------------";
			cout<<endl;
			cout<<" "<<node->data<<" ";
			cout<<endl;
			cout<<"-----------------------";
		}
		else if(a==3){
			writeEmail(node);
		}
		else if(a==0)
			return;
		
		else{
			display(node);
		}
		}
}

void writeEmail(Node* node){
	string from,to,date,Signature;
	string receiversName;
	string subject;
	char sub[250];
	cout<<"Input sender's Email: ";
	cin>>from;
	cout<<"Input Receiver's Email: ";
	cin>>to;
	cout<<"Input Date (DD/MM/YYYY): ";
	cin>>date;
	cout<<"Input Subject: ";
	getline(cin,subject);
	cin.getline(sub,250);
	cout<<"Sender's name: ";
	cin>>Signature;
	cout<<"Receiver's name: ";
	cin>>receiversName;

	cout<<endl<<endl;
	cout<<"From: "<<from<<endl<<"To: "<<to<<endl;
	cout<<"Date: "<<date<<endl<<"Subject: "<<sub<<endl;
	cout<<node->salutaition;
	cout<<node->body;
	cout<<Signature;

}

 
int main(){
	Node* head=NULL;
	Node* formateHead=NULL;
	append(&formateHead,"From",1);
	append(&formateHead,"to",2);
	append(&formateHead,"Date",3);
	append(&formateHead,"Subject",4);
	append(&formateHead,"Salutation",5);
	append(&formateHead,"Body",6);
	append(&formateHead,"Signature",7);
	//1printList(formateHead);
	string leave,congratulate,welcome;
	append(&head,"Leave Email",1,"Sir,\nI hope you are well.\nThis email is to inform you that I was absent today\nI will be back from tomorrow.\n","I am not feeling well today.It would be great if you grant my leave.\nSincerly,\n");
	append(&head,"Greeting Email",2,"Dear name,\nI hope you are well.\nI want to congratulate you for your success!","I heard about your impressive and brilliant success.\nfor this I want to heathly congratulate you.\nSincerly,\n");
	append(&head,"Welcome Email",3,"Dear name,\nWelcome to our team!We're so excited to have you in our team.\n","You will be joining from next month.We looking forward to work with you.\nSincerly,\n");
	append(&head,"Offer email",4,"Dear name,\nI am very excited to accept your offer to join us.","We will be joining us as we discussed on the phone.If there is any additional information you need to know please feel free to contact me.\n I will be happy to provide it.I will be looking forward for you.\nSincerly,\n");
	saveFile(formateHead);
	showTemplates(head);
}
