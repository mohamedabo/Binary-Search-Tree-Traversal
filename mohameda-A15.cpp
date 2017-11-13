// Binary Search Tree
// Originally created by Dr. Jan Pearce
// Modified by Mario Nakazawa

// Your name: Abdirahman Mohamed

//    NOTE THAT THIS VERSION NO LONGER COMPLETELY MATCHES THE VERSION
//    IN THE ASSIGNMENT. Namely, duplicates are no longer inserted
//    into the tree, and a lot of comments are included in this code.

#include<iostream>
using namespace std;

// This class is really just a struct because it is a bag of variable
// and information without any functionality built into it. It
// represented a single node in the binary search tree, holding the
// value of the node, and pointers to the left and right children,
// respectively.
class BstNode
{
public:
  int data;
  BstNode* left;
  BstNode* right;
};

// precondition: none, as any value, positive or negative, will
// work. The value must be an integer though, as specified in the data
// type of the parameter.
// postcondition: a new object of type BstNode will be created with the
// value of data, and it is a leaf (i.e. has NULL values for both left
// and right children).
BstNode*
GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// This function seems counterintuitive. Notice that the base case
// would create the node, but then this function returns the reference
// to that node, which is assigned to the left or right child of the
// node that called this function. This relationship ripples back to
// the original called function, which would return the root of the tree.
// precondition: none
// postcondition: If the values does not exist in the tree, it is
// inserted and the pointer to the root of the tree is eventually
// returned.
BstNode*
insert(BstNode* thisNode, int data)
{
  // BASE CASE: If the current location is empty, then create a new
  // node with that value.
  if( thisNode == NULL) {
    thisNode = GetNewNode(data);
  }

  // RECURSIVE CALL 1: If the value we want to insert is less than
  // where we are, then go down the left child recursively.
  else if(data < thisNode->data) {
    thisNode->left = insert( thisNode->left, data );
  }

  // RECURSIVE CALL 2: If the value is greater than where we are now,
  // go down the right child and make sure that the
  else if( data > thisNode->data ) {
    thisNode->right = insert( thisNode->right, data );
  }

  // Note that if the value already exists in the tree, we ignore it.

  // this function ends by returning the current node
  return thisNode;
}

BstNode* rawinput(BstNode*root){
/* takes an input from the user and added it to the tree */
    int s; // intitialize input
    cout<< "Enter a number:"<<endl;
        for(int i=1;i<=5;i++){
                cin>>s;
                root = insert(root,s); // insert the input alongside the root
    }
    return root;
}

void inorder (BstNode*root)
/*Arranges output in order from left to root to right  */
{

 if (root==NULL) // The base case: if root is empty
        return; // return root
    inorder(root->left); // recursive call to all items on the left of the root
    cout<< root->data<<endl; //  printing root
    inorder(root->right); // recursive call to all items on the right of the root

}


void preorder(BstNode*root)
/*Arranges output preorder from root to left to right  */
{
    if (root==NULL)
        return;
    cout<< root->data<<endl; // printing root
    preorder(root->left); // recursive call to all items on the left of the root
    preorder(root->right); // recursive call all items on the right the root

}



void postorder(BstNode*root)
/*Arranges output postorder from left to right to root */
{


   if (root==NULL)
        return;
    postorder(root->left); // recursive call to all items on the left of the root
    postorder(root->right); // recursive call to all items on the right of the root
    cout<< root->data<<endl; // printing the root
}



// The main function, which returns a zero if the program runs
// successfully to completion.
int main() {
  BstNode* head = NULL;
  head= rawinput(head); // call to rawinput function
  cout<<"Preorder traversal of binary tree is"<<endl;
  preorder(head); // call to preorder function
  cout<<"In order traversal of binary tree is"<<endl;
  inorder(head); // call to inorder function
  cout<<"Postorder traversal of binary tree is"<<endl;
  postorder(head); // call to postorder function
  return 0;
}
