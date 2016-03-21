/* Author: Aastha Agrawal
 * Preorder traversal using iterative method
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node* insert(Node* root, int data){
    if(root==NULL)
        return newNode(data);
    if(root->data>data)
        root->left=insert(root->left,data);
    else if(root->data<data)
        root->right=insert(root->right,data);
    return root;
}

void iterativePreorder(Node* root){
    stack<Node* > st;
    while(st.empty()==false || root!=NULL){
        while(root){
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        root=root->right;
    }
}

int main() {
	Node* root;
	root=insert(root,55);
	insert(root,35);
	insert(root,213);
	insert(root,12);
	insert(root,0);
	insert(root,5);
	insert(root,78);
	insert(root,99);
	insert(root,9);
	iterativePreorder(root);
	return 0;
}
