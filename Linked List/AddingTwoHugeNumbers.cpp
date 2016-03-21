/* Author: Aastha Agrawal
 * Adding two numbers represented as a Linked List
 */

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* newNode(int key){
    node* n = new node;
    n->data=key;
    n->next=NULL;
    return n;
}

void push(node** head, int key){
    node* temp=*head;
    if(!temp){
        *head = newNode(key);
        return;
    }
    temp=newNode(key);
    temp->next=*head;
    *head=temp;
}

void printLL(node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

node* representLL(int a){
    node* temp=NULL;
    int mod;
    while(a){
        mod=a%10;
        push(&temp,mod);
        a=a/10;
    }
    return temp;
}

node* addLL(node* aLL,node* bLL){
    stack<int> a;
    stack<int> b;
    int carry, dig_sum;
    carry=0;
    node *result=NULL;
    while(aLL){
       a.push(aLL->data);
       aLL=aLL->next;
    }
    while(bLL){
       b.push(bLL->data);
       bLL=bLL->next;
    }
    while(!a.empty() && !b.empty()){
        dig_sum=a.top() + b.top() + carry;
        carry=dig_sum/10;
        dig_sum=dig_sum%10;
        push(&result,dig_sum);
        a.pop();
        b.pop();
    }
    if(!a.empty()){
        while(!a.empty()){
            dig_sum=a.top() + carry;
            carry=0;
            push(&result,dig_sum);
            a.pop();
        }
    }
    else if(!b.empty()){
        while(!b.empty()){
            dig_sum=b.top() + carry;
            carry=0;
            push(&result,dig_sum);
            b.pop();
        }
    }
    else{
        if(carry!=0)
            push(&result,carry);
    }
    return result;
}

int main() {
	int a=9145;int b=55;
	//cin>>a>>b;
	node* aLL=representLL(a);
	node* bLL=representLL(b);
	printLL(aLL);
	printLL(bLL);
	node* result = addLL(aLL,bLL);
	printLL(result);
	return 0;
}
