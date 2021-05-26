#include <iostream>
#include "../include/binary_tree.hpp"

int main()
{
    Binary_Tree Tree = create_node('A');
    insert(Tree, create_node('B'));
    insert(Tree, create_node('G'));
    insert(Tree->left, create_node('C'));
    insert(Tree->left, create_node('F'));
    insert(Tree->right, create_node('D'));
    insert(Tree->right, create_node('E'));


}