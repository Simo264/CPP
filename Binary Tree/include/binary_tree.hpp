#ifndef BT_TREE__
#define BT_TREE__

using type = char;
struct Node
{
    type value;
    Node* left;
    Node* right;
};
using Binary_Tree = Node*;

Node* create_node(type);
type get_value(Binary_Tree);
Node* get_left(Binary_Tree);
Node* get_right(Binary_Tree);

void insert(Binary_Tree&, Node*);

void DFS_Inorder(Binary_Tree);
void DFS_Preorder(Binary_Tree);
void DFS_Postorder(Binary_Tree);
void BFS_visit(Binary_Tree);

int calc_height(Binary_Tree);
int num_of_nodes(Binary_Tree);
int num_of_leefs(Binary_Tree);

bool is_complete(Binary_Tree);
bool same_structure(Binary_Tree, Binary_Tree);

#endif