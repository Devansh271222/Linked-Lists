#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		
	//constructor
	Node(int d){
		this->data=d;
		this->next=NULL;
	}
	~Node(){
		int value=this->data;
		if(this->next!=NULL){
			delete next;
			next=NULL;
		}
		cout<<"Memory is free for node with data "<<value<<endl;
	}
		
};
void insertNode(Node* &tail,int element,int d){
	
	if(tail==NULL){
		Node* newNode = new Node(d);
		tail=newNode;
		newNode->next=newNode;
	}else{
		Node* curr=tail;
		while(curr->data!=element){
			curr=curr->next;
		}Node* temp = new Node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}
void deleteNode(Node* tail,int value){
	//empty
	if(tail==NULL){
		cout<<"List is empty please check again";
	}else{
		Node* prev=tail;
		Node* curr=prev->next;
		while(curr->data!=value){
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		if (curr==prev){
			tail=NULL;
		}else if(tail==curr){
			tail=prev;
		}
		curr->next=NULL;
		delete curr;
	}
}
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}
int main(){
	Node* tail=NULL;
	insertNode(tail,5,3);
	print(tail);
	insertNode(tail,3,5);
	print(tail);
	insertNode(tail,5,7);
	print(tail);
	insertNode(tail,5,6);
	print(tail);
	insertNode(tail,3,4);
	print(tail);
	deleteNode(tail,4);
	print(tail);
}
