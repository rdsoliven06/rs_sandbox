#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Method 1: This method will return the minimun number
// depth of a binary tree.
int minDep(Node* root)
{
	// Zero node check
	if (root == NULL) { return 0; }
	
	// One node or leaf node check
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	int l = INT_MAX, r = INT_MAX;
	
	// If the left subtree is not null, recur for left subtree
	if (root->left)
	{
		l = minDep(root->left);
	}
	
	// If the right subtree is not null, recur for right subtree
	if (root->right)
	{
		r = minDep(root->right);
	}
	
	return std::min(l,r) + 1;
}

// Method 2
int minDepth(Node* root, int level)
{
	if (root == NULL)
	{
		return level;
	}
	
	level++; //increment 
	
	// determine minimum left and right number of depth
	return std::min(minDepth(root->left, level), minDepth(root->right, level));
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	std::cout << "The miniminum depth number of the tree is " << minDep(root) << std::endl;

	return 0;
}
