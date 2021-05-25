#include "../include/binary_tree.hpp"
#include <iostream>
#include <queue>

Node* create_node(type value) { return new Node { value, nullptr, nullptr }; }

type get_value(Binary_Tree tree) { return tree->value; }
Node* get_left(Binary_Tree tree) { return tree->left; }
Node* get_right(Binary_Tree tree) { return tree->right; }

void insert(Binary_Tree& tree, Node* node)
{
	if(!tree)
	{
		tree = node;
	}
	else
	{
		if(!tree->left || !tree->right)
		{
			if(!tree->left)
				tree->left = node;
			else if(!tree->right)
				tree->right = node;
		}
	}
}

void DFS_Inorder(Binary_Tree tree)
{
	if(tree)
	{
		DFS_Inorder(tree->left);
		std::cout << tree->value << " ";
		DFS_Inorder(tree->right);
	}
}
void DFS_Preorder(Binary_Tree tree)
{
	if(tree)
	{
		std::cout << tree->value << " ";
		DFS_Preorder(tree->left);
		DFS_Preorder(tree->right);
	}
}
void DFS_Postorder(Binary_Tree tree)
{
	if(tree)
	{
		DFS_Postorder(tree->left);
		DFS_Postorder(tree->right);
		std::cout << tree->value << " ";
	}
}
void BFS_visit(Binary_Tree tree)
{
	if(tree)
	{
		std::queue<Node*> q;
		q.push(tree);

		while(!q.empty())
		{
			auto node = q.front();
			q.pop();

			std::cout << node->value << " ";
			if(node->left) 	q.push(node->left);
			if(node->right)	q.push(node->right);
		}
	}
}

int calc_height(Binary_Tree tree)
{
	if(!tree) return 0;
	int left_height = calc_height(tree->left);
	int right_height = calc_height(tree->right);
	return std::max<decltype(left_height)>(left_height, right_height) + 1;
}
int num_of_nodes(Binary_Tree tree)
{
	if(!tree) return 0;
	return num_of_nodes(tree->left) + num_of_nodes(tree->right) + 1;
}
int num_of_leefs(Binary_Tree tree)
{
	if(!tree) return 0;

	if(!tree->left && !tree->right)
		return 1;
	
	return num_of_leefs(tree->left) + num_of_leefs(tree->right);
}
bool is_complete(Binary_Tree tree)
{
	if(!tree) 						return true;
	if(!tree->left && !tree->right) return true;
	if(tree->left && tree->right)	return is_complete(tree->left) && is_complete(tree->right);
	return false;
}
bool same_structure(Binary_Tree T1, Binary_Tree T2)
{
	if(!T1 && !T2) return true;
	if(!T1 || !T2) return false;
	return same_structure(T1->left, T2->left) && same_structure(T1->right, T2->right); 
}
