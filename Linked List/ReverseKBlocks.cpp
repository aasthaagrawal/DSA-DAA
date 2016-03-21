/* Author: Aastha Agrawal
 * Reverse linked list in size of k
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  struct Node* next;
};

Node* newNode(int data){
    Node* n = new Node;
    n->key=data;
    n->next=NULL;
    return n;
}

void printLL(Node* root){
    while(root){
        cout<<root->key<<" ";
        root=root->next;
    }
    cout<<endl;
}

Node* reverseKBlocks(Node* root,int k){
    
    Node *cur,*prev,*next;
    int count=0;
    prev=NULL;
    cur=root;
    while(cur && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
    }
    
    if(next){
        root->next=reverseKBlocks(next,k);
    }
    return prev;
}

void insert(Node **head,int key){
    
    Node *n = newNode(key);
    if(*head==NULL){
        *head=n;
        return;
    }
    Node *temp = *head;

    while(temp->next){
        temp=temp->next;
    }
    temp->next=n;
}

int main() {
    Node *root=NULL;
    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);
    insert(&root,6);
    insert(&root,7);
    insert(&root,8);
    insert(&root,9);
    insert(&root,10);
    printLL(root);
    root=reverseKBlocks(root,3);
    printLL(root);
	return 0;
}
