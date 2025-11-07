#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
	//constructor
	Node(int d){
		this->data=d;
		this->prev=NULL;
		this->next=NULL;
	}
	//destructor
	~Node(){
		int value=this->data;
		if (next!=NULL){
			delete next;
			next=NULL;
		}cout<<"Memory free for node with data "<<value<<endl;;
	}
};
void insertAtHead(Node* &head,int d){
	if(head==NULL){
		Node* temp=new Node(d);
		head=temp;	
	}else{
		Node* temp=new Node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
	}	
}
void insertAtTail(Node* &tail,int d){
	if(tail==NULL){
		Node* temp=new Node(d);
		tail=temp;
	}
	Node* temp=new Node(d);
	temp->prev=tail;
	tail->next=temp;
	tail=temp;
}
void insertAtPosition(Node* &tail,Node* &head,int position,int d){
	if (position==1){
		insertAtHead(head,d);
		return;
	}
	Node* temp=head;
	int count=1;
	while(count<position-1){
		temp=temp->next;
		count++;
	}if(temp->next==NULL){
		insertAtTail(tail,d);
		return;
	}
	//create node;
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next=temp->next;
	nodeToInsert->prev=temp;
	temp->next->prev=nodeToInsert;
	temp->next=nodeToInsert;
}
void deleteNode(int position,Node* &head){
	if (position==1){
		Node* temp = head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}else{
		Node* curr=head;
		Node* prev=NULL;
		int count = 1;
		while(count<position){
			prev=curr;
			curr=curr->next;
			count++;
		}
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
} 
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}cout<<endl;
}
int main(){
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;
	print(head);
	insertAtHead(head,8);
	print(head);
	insertAtTail(tail,12);
	print(head);
	cout<<endl<<"Insertion ho rha hai "<<endl;
	insertAtPosition(tail,head,3,11);
	print(head);
	cout<<"Head: "<<head->data<<endl;
	cout<<"Tail: "<<tail->data<<endl;
	deleteNode(4,head);
	print(head);
	return 0;	
}
