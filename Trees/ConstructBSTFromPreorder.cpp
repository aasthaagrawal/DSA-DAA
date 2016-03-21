/* Author: Aastha Agrawal
 * Construct the BST given the preorder traversal
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

Node* newNode(int data){
    Node *node = new Node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

Node* constructTreeUtil(int preOrder[], int n, int &index, int min, int max){
    if(index==n)
        return NULL;
    
    Node* root = NULL;
    int key=preOrder[index];
    if(key>min && key<max){
        root=newNode(key);
        index++;
        if(index<n){
            root->left=constructTreeUtil(preOrder,n,index,min,key);
            root->right=constructTreeUtil(preOrder,n,index,key,max);
        }
    }    
    return root;
}

Node* constructTree(int preOrder[], int n){
    int index=0;
    return constructTreeUtil(preOrder,n,index,INT_MIN,INT_MAX);
}

void printInorder(Node* root){
    if(!root)
        return;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int preOrder[] = {10,5,1,7,40,50};
    int n= (sizeof(preOrder))/(sizeof(int));
    Node* root= constructTree(preOrder, n);
    printInorder(root);
    return 0;
}
