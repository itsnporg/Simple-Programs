/* 
Given a Binary Search Tree, find the sum of all leaf nodes. BST has the following property (duplicate nodes are possible):

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case consists of integer N, denoting the number of elements in the BST. The second line of each test case consists of N space-separated integers denoting the elements in the BST.

Output:
For each testcase, in a new line, print the sum of leaf nodes.

*/

/* 
Input:
2
6
67 34 82 12 45 78
1
45
Output:
135
45

Explanation:
In first test case, the BST for the given input will be-

               67

          /        \

     34              82

  /    \           /

12   45         78

Hence, the required sum= 12 + 45 + 78 = 135

*/



#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *insert(Node *r,int num);
int sumOfLeafNodes(Node *r);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);

int main(void) {
    int t,n,data;
    scanf("%d",&t);
    while(t--){
        Node *root=NULL;
        scanf("%d",&n);
        //printf("n=%d\n",n);
        while(n--){
            scanf("%d",&data);
            //printf("data=%d\n",data);
            root=insert(root,data);
        }
        //inOrderDisplay(root);
        printf("%d\n",sumOfLeafNodes(root));
    }
	return 0;
}

Node *insert(Node *r,int num){
    if(r==NULL){
        r = new Node(num);
    }else{
        if(num<r->data){
            r->left=insert(r->left,num);
        }else{
            r->right=insert(r->right,num);
        }
    }
    return r;
}

void preOrderDisplay(Node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node *r){
    if(r!=NULL){
        inOrderDisplay(r->left);
        printf("%d ",r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node *r){
    if(r!=NULL){
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ",r->data);
    }
}

int search(Node *r,int num){
    if(r==NULL)return 0;
    else if(r->data==num)return 0;
    else if(r->data > num)
        search(r->left,num);
    else 
        search(r->right,num);
}


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


//Recursive Approach
int sumOfLeafNodes(Node *r ){
     if(r==NULL)
     return 0;
     if(r->left==NULL && r->right==NULL)
     return r->data;
     return sumOfLeafNodes(r->left)+sumOfLeafNodes(r->right);
}
