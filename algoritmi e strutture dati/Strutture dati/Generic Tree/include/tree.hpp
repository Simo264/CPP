#ifndef _TREE_
#define _TREE_

using type = const char*;
struct Node
{
    type value;
    Node* firstChild;
    Node* nextSibling;
    Node* parent;
};

using Tree = Node*;

Node* create_node(type);
type get_value(Tree);
Node* get_firstChild(Tree);
Node* get_nextSibling(Tree);
Node* get_parent(Tree);

void insert_child(Tree, Tree);
void insert_sibling(Tree, Node*);


void DFS_Preorder(Tree);
void DFS_Postorder(Tree);
void BFS_visit(Tree);
void serialize(Tree);

int calc_height(Tree);
int dimension(Tree);


#endif