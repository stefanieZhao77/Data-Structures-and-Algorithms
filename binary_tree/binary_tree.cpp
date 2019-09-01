#include<iostream>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};
void Insert(node *n, int x)
{
	if (x < n->val)
	{
		if (n->left == NULL)
		{
			node *temp = new node;
			temp->val = x;
			temp->left = NULL;
			temp->right = NULL;
			n->left = temp;
		}
		else
		{
			Insert(n->left, x);
		}
	}
	else
	{
		if (n->right == NULL)
		{
			node *temp = new node;
			temp->val = x;
			temp->left = NULL;
			temp->right = NULL;
			n->left = temp;
		}
		else
		{
			Insert(n->right, x);
		}
	}
}


void Remove(node *p, node *n, int x)
{
	while (n != NULL && n->val!=x)
    {
        p = n; //p is father node of n
        if(x < n->val) n = n->left;
        else n=n->right;
    }
    if(p == NULL) return;
    // if the goal node has left tree and right tree
    if(n->left != NULL && n->right !=NULL){
        node *minN = n->right;
        node *minNN = n; //father
        while(minN->left != NULL){
            minNN = minN;
            minN = minN->left;
        }
        n->val = minN->val;
        n = minN;
        p = minNN;
    }
    node *child;
    if(n->left != NULL) child = p->left;
    else if(n ->right !=NULL) child = p->right;
    else child = NULL;

    if (p ->left == n) p->left = child;
    else p->right = child; 
    
}


int main()
{
	int value;
	int ch;
	node *root = new node;
	cout << "\nEnter the value of root node :";
	cin >> value;
	root->val = value;
	root->left = NULL;
	root->right = NULL;
	do
	{
		cout << "\n1. Insert";
		cout << "\n2. Delete";

		cin >> ch;
		int x;
		switch (ch)
		{
		case 1:
			cout << "\nEnter the value to be Inserted : ";
			cin >> x;
			Insert(root, x);
			break;
		case 2:
			cout << "\nEnter the value to be Deleted : ";
			cin >> x;
			Remove(root, root, x);
			break;
		}
	} while (ch != 0);
}