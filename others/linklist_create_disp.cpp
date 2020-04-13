#include<iostream>
using namespace std;

class node{
	public:
	int data=0;
	node *next=NULL;
};

node create(int *arr,int n){
	node *t,*first;
	t=new node();
	t->data=arr[0];
	first=t;
	for(int i=1;i<n;i++){
		t=new node();
		t->data=arr[i];
		t=t->next;
	}
	return *first;	
};

void display(node *p){
	while(p->next!=NULL){
		cout<<p->data;
	}
}

int main(){
	
	int arr[]={9,45,67,32};
	int n=4;
	node *ll;
	*ll=create(arr,n);
	display(ll);
}
