#include<iostream>
using namespace std;


struct node{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct queue{
	int size;
	int front;
	int rear;
	node **Q;
};


void create(struct queue *q,int size)
{
	q->size=size;
	q->Q=(node**)malloc(q->size*(sizeof(node *)));
	q->rear=q->front=0;
}
void enqueue(struct queue *q,node *x)
{
	if(q->rear==q->size-1)
	 cout<<"Queue is full"<<endl;
	 else
	 {
	 	q->rear=(q->rear+1)%q->size;
	 	q->Q[q->rear]=x;
	 }
}
void displayq(struct queue q)
{
	int i;
	cout<<"The queue is : ";
	for(i=(q.front+1);i<q.size;i++)
	{
		cout<<q.Q[i]<<" ";
	}
	cout<<endl;
}

node* dequeue(struct queue *q)
{
	node *x=NULL;
	if(q->front==q->rear)
	 cout<<"Queue is empty"<<endl;
	 else
	 {
	 	q->front=(q->front+1)%q->size;
	 	x=q->Q[q->front];
	 }
	  return x;
}

int isempty(struct queue q)
{
	if(q.front==q.rear)
	 return 1;
	 else
	  return 0;
}

//  now code for creating the binary tree ;

struct node *root=NULL;       // for accesing this variable anywhere ;

void Treecreate()
{
	struct node *p,*t;
	int x;
	struct queue q;
	create(&q,100);
	
	cout<<"Enter root value ";
	cin>>x;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	
	enqueue(&q,root);
	
	while(!isempty(q))
	{
		p=dequeue(&q);
		cout<<"Enter left child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		
		cout<<"Enter right child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(struct node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}
void postorder(struct node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}
int main()
{
    Treecreate();
    cout<<"preorder of the tree is "<<endl;
     preorder(root);
     cout<<"\n\ninorder of the tree is "<<endl;
     inorder(root);
     cout<<"\n\npostorder of the tree is "<<endl;
     postorder(root);
	return 0;
}

