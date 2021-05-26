#include "../include/tree.hpp"
#include <iostream>
#include <queue>

Node* create_node(type value)       { return new Node {value, nullptr, nullptr, nullptr }; }
type get_value(Tree tree)           { return tree->value; }
Node* get_firstChild(Tree tree)     { return tree->firstChild; }
Node* get_nextSibling(Tree tree)    { return tree->nextSibling; }
Node* get_parent(Tree tree)         { return tree->parent; }

void insert_child(Tree parent, Tree child) 
{
    child->nextSibling = parent->firstChild;
    child->parent = parent;
    parent->firstChild = child;
}
void insert_sibling(Tree tree, Node* node)
{
    tree->nextSibling = node->nextSibling;
    tree->parent = node->parent;
    node->nextSibling = tree;

}

void DFS_Preorder(Tree tree) 
{
    if(tree)
    {
        std::cout << get_value(tree) << " ";
        auto u = get_firstChild(tree);
        while(u)
        {
            DFS_Preorder(u);
            u = get_nextSibling(u);
        }
    } 
}
void DFS_Postorder(Tree tree) 
{
    if(tree)
    {
        auto u = get_firstChild(tree);
        while(u)
        {
            DFS_Preorder(u);
            u = get_nextSibling(u);
        }
        std::cout << get_value(tree) << " ";
    } 
}
void BFS_visit(Tree tree) 
{
    if(tree)
    {
        std::queue<Node*> q;
        q.push(tree);

        while(!q.empty())
        {
            auto u = q.front();
            q.pop();

            std::cout << get_value(u) << " ";
            
            while(u = get_nextSibling(u))
            {
                q.push(u);
            }
        }
    } 
}
void serialize(Tree tree)
{
    if(tree)
    {
        std::cout<<"(";
        std::cout << get_value(tree);

        Tree t1 = get_firstChild(tree);
        while(t1)
        {
            serialize(t1);
            t1 = get_nextSibling(t1);
        }
            std::cout << ")";
    } 
}

int calc_height(Tree tree)
{
    if(!get_firstChild(tree)) return 0;
        
    int max(0);
    int max_loc(0);

    Tree subtree = get_firstChild(tree);
    while(subtree)
    {
        max_loc = calc_height(subtree);
        if(max_loc>max)
            max = max_loc;
        subtree = get_nextSibling(subtree);
    }

    return max + 1;
}
int dimension(Tree tree)
{
    int dim(0);
    int dim1(0);
    Tree subtree = get_firstChild(tree);

    while(subtree)
    {
        dim1 = dimension(subtree);
        dim += dim1;
        subtree = get_nextSibling(subtree);
    }
    return dim + 1;
}