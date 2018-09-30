/*
Reversing a Linked List in Iterative Manner
Implemented in Object Oriented manner
1. Each object of Node Class is a node in Linked List
2. Each object of Sll class corresponds to a Linked List (Collection of Node Class objects)

Reversing a linked list in Iterative manner 
1. Maintain Three pointers : previous , current and next 
2. At each iteration , make curr point to previous . 
3. Move forward and make prev now as curr & curr now as next
4. At the end make sure head now points to the last node (prev) 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
class Node {
	public :
			int data,n;
			Node * link;
};
class Sll {
	private :
			Node * head;

	public :
			Sll(int nodes) {
				this->head = NULL;
			}
			void add(int value) {
				if(head == NULL) {
					Node * newNode = new Node();
					newNode->data = value;
					newNode->link = NULL;
					head = newNode;
				}
				else {
					Node *temp,*prev;
					temp = head;
					while(temp != NULL) {
						prev = temp;
						temp = temp->link;
					}
					Node * newNode = new Node();
					newNode->data = value;
					newNode->link = NULL;
					prev->link = newNode;
				}
			}
			void reverse_iterative(){
				if(head == NULL) 
					cout<<"The list is empty !";
				else if(head->link == NULL)
					cout<<"Only One element in the list !";
				else {
					Node * prev = NULL;
					Node * curr = head;
					Node * next = NULL;
					while(curr != NULL) {
						next = curr->link;
						curr->link = prev;
						prev = curr;
						curr = next;
					}	
					head = prev;	
				}

			} 
			void print() {
				cout<<"LIST CONTENTS : "<<endl;
				if(head == NULL)
					cout<<"The list is empty !";
				else {
					Node * temp = head;
					while(temp != NULL) {
						cout<<temp->data<<"	";
						temp = temp->link;
					}
					cout<<endl;
				}
			}
};
int main() {
	int n,value;
	cout<<"Enter number of nodes : ";
	cin>>n;
	Sll mylist(n);
	cout<<"Enter the List : "<<endl;
	for(int i=1;i<=n;i++){
		cin>>value;
		mylist.add(value);
	}
	mylist.print();
	mylist.reverse_iterative();
	mylist.print();
	return 0;
}