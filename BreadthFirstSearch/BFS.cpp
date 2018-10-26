#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

//Create a node
struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
};

void printleveldata(struct Node * root, int level);
void levelordertraversal(struct Node * root);
int findHeight(struct Node * node);
struct Node * newNode(int data);

void levelordertraversal(struct Node * root)
{
	int h = findHeight(root);
	for (int i = 1; i <= h; i++)
	{
		printleveldata(root, i);
	}
}

void printleveldata(struct Node * root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		cout << root->data;
		return;
	}
	else if (level > 1)
	{
		printleveldata(root->left, level - 1);
		printleveldata(root->right, level - 1);
	}
}

int findHeight(struct Node * node)
{
	if (node == NULL)
		return false;
	else
	{
		int left_h = findHeight(node->left);
		int right_h = findHeight(node->right);

		if (left_h > right_h)
		{
			return(left_h + 1);

		}
		else
		{
			return (right_h + 1);
		}
	}

	
}

struct Node * newNode(int data)
{
	struct Node * Node = (struct Node*)malloc(sizeof(struct Node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}


int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("BFS of binary tree is \n");
	levelordertraversal(root);

	return 0;
}