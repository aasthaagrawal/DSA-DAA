/* Author: Aastha Agrawal
 * Excercises on Binary Search Tree
 * 1.) insertion in a BST
 * 2.) checking if a given element is present or not
 * 3.) checking wheather given BT is a BST or not
 * 4.) inorder successor and predecessor of a given element. If the element is not found then return the values within which the given element would be found
 * 5.) finding leaf with maximum leaf-to-root path sum and then printing the path
 * 6.) finding path sum between two given leaf nodes
 * 7.) return Kth smallest
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int key){
    Node* n = new Node;
    n->key=key;
    n->left=n->right=NULL;
    return n;
}

Node* insertBST(Node* root, int data){
    if(root==NULL){
        root=newNode(data);
    }
    else{
        if(root->key>data)
            root->left = insertBST(root->left,data);
        else
            root->right = insertBST(root->right,data);
    }
    return root;
}

void inorderPrint(Node* root){
    if(root==NULL)
        return;
    inorderPrint(root->left);
    cout<<root->key<<" ";
    inorderPrint(root->right);
}

bool search(Node* root, int key){
    if(root==NULL)
        return false;
    if(root->key==key)
        return true;
    if(root->key>key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

bool isBSTUtil1(Node* root, int min, int max){
    if(root==NULL)
        return true;
        
    if(root->key <min && root->key>max)
        return false;
    
    return (isBSTUtil1(root->left,min,root->key)) &&
            (isBSTUtil1(root->right,root->key,max));
}

bool BSTCheck(Node* root){
    if(root==NULL)
        return true;
    return isBSTUtil1(root,INT_MIN, INT_MAX);
}

void findPreSuc(Node* root, Node **pre, Node **suc, int key){
    if(root==NULL)
        return;
    
    if(root->key==key){
        Node* temp;
        if(root->left){
            temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            *pre=temp;
        }
        if(root->right){
            temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            *suc=temp;
        }
        return;
    }
    
    if(key>root->key){
        *pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else{
        *suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
}

void printPath(Node* root,Node* targetLeaf){
    if(root==targetLeaf){
        cout<<targetLeaf->key<<"->";
        return;
    }
    if(targetLeaf->key > root->key)
        printPath(root->right,targetLeaf);
    else
        printPath(root->left,targetLeaf);
        
    cout<<root->key<<"->";
}

void findMaxLeafToRoot(Node* root,int *maxSum, Node** targetLeaf,int curSum){
    if(root==NULL)
        return;
    curSum+=root->key;    
    if(root->left==NULL && root->right==NULL){
        if(curSum>*maxSum){
            *maxSum=curSum;
            *targetLeaf=root;
        }
    }
    
    findMaxLeafToRoot(root->left,maxSum,targetLeaf,curSum);
    findMaxLeafToRoot(root->right,maxSum,targetLeaf,curSum);
}

void maxSumPath(Node* root){
    if(!root)
        return;
    int maxSum;
    Node* targetLeaf;
    findMaxLeafToRoot(root,&maxSum,&targetLeaf,0);
    cout<<"Maximum leaf-to-root path sum:"<<maxSum<<endl;
    cout<<"Printing path for max leaf-to-root path sum:"<<endl;
    printPath(root,targetLeaf);
    cout<<"NULL"<<endl;
}

Node* findRoot(Node* root, int a,int b){
    if(root->key > a && root->key > b)
        return findRoot(root->left,a,b);
    else if(root->key < a && root->key < b)
        return findRoot(root->right,a,b);
    else
        return root;
}

int getPathSum(Node* root,int a){
    if(root->key==a)
        return root->key;
    if(a>root->key)
        return (root->key + getPathSum(root->right,a));
    else
        return (root->key + getPathSum(root->left,a));
}

int pathSum(Node* root, int a, int b){
    if(root==NULL)
        return 0;
    
    Node* targetRoot=findRoot(root,a,b);
    int Sum =getPathSum(targetRoot,a);
    Sum += getPathSum(targetRoot,b);
    Sum -=targetRoot->key;
    return Sum;
}

void KthSmallestUtil(Node* root, int k,int &count,int &element){
    if(root->left)
        KthSmallestUtil(root->left,k,count,element);
        
    count++;
    if(count==k){
        element=root->key;
    }
    if(root->right)
        KthSmallestUtil(root->right,k,count,element);
}

int KthSmallest(Node* root, int k){
    int count=0;
    int element;
    KthSmallestUtil(root,k,count,element);
    return element;
}

int main() {
	Node* root = NULL;
	
	//Insertion
	root = insertBST(root,6);
	root =insertBST(root,8);
	root =insertBST(root,1);
	root =insertBST(root,9);
	root =insertBST(root,3);
	root =insertBST(root,0);
	root =insertBST(root,7);
	inorderPrint(root);
	cout<<endl;
	
	//search
	cout<<search(root,1)<<endl;
	cout<<search(root,99)<<endl;
	
	//Is BST
	if(BSTCheck(root))
	    cout<<"Is BST"<<endl;
	else
	    cout<<"Not BST"<<endl;
	    
	//Inorder predecessor and successor
	Node *pre=NULL;
	Node *suc=NULL;
	findPreSuc(root,&pre,&suc,6);
	cout<<"Predecessor: "<<pre->key<<endl;
	cout<<"Successor: "<<suc->key<<endl;
	
	//Max leaf-to-root path sum
	maxSumPath(root);
	cout<<"Path sum between 7 and 9:"<<pathSum(root,7,9)<<endl;
	cout<<"Path sum between 3 and 9:"<<pathSum(root,3,9)<<endl;
	
	//Finding the Kth smallest element of the BST
	int k=6;
	cout<<k<<"th smallest element of the BST:"<<KthSmallest(root,k)<<endl;
	return 0;
}
