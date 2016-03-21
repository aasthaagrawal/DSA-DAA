/* Author: Aastha Agrawal
 * Printing binary tree according to vertical order (Vertical traversal)
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void verticalOrder(Node* root, int hd, map< int, vector<int> > &hash){
    
    if(root==NULL)
        return;

    hash[hd].push_back(root->data);
    verticalOrder(root->left,hd-1,hash);
    verticalOrder(root->right,hd+1,hash);
}

void printVerticalOrder(Node* root){
    map< int, vector<int> > hash;
    int hd = 0;
    verticalOrder(root,hd,hash);
    
    map< int, vector<int> >::iterator it = hash.begin();
    for(;it!=hash.end();it++){
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    
    cout<<"Vertical order traversal is as follows"<<endl;
    printVerticalOrder(root);
	return 0;
}
