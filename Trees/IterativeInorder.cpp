/* Author: Aastha Agrawal
 * Inorder traversal using iterative method
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

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    
    if(root->data<data)
        root->right=insert(root->right,data);
    else if(root->data>data)
        root->left=insert(root->left,data);
    return root;
}

void recursiveInorder(Node* root){
    if(root==NULL)
        return;
    recursiveInorder(root->left);
    cout<<root->data<<" ";
    recursiveInorder(root->right);
}

void iterativeInorder(Node* root){
    stack<Node* > st;
    while(st.empty()==false || root!=NULL){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}

int main() {
    Node* root;
    root=insert(root,6);
    insert(root,10);
    insert(root,3);
    insert(root,22);
    insert(root,1);
    insert(root,4);
    insert(root,0);
    insert(root,13);
    //recursiveInorder(root);
    //cout<<endl;
    iterativeInorder(root);
	return 0;
}
