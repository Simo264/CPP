#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

/* Liste di adiacenza */
struct adj_node
{
    int value;
    float weight;
    adj_node* next;
};
using adj_list = adj_node*;

struct Graph
{
    adj_list* nodes;
    int dim;
};

int get_dim(const Graph&);
adj_list get_adjlist(const Graph&, const int);
int get_adjnode(const adj_node*);
adj_list get_nextadj(const adj_list&);

Graph new_graph(int);
//  Aggiunge l’arco orientato (s,d) con peso w alla lista di 
//  adiacenza del nodo s
void add_arc(Graph&, int, int, float);

//  Aggiunge l’arco non orientato (s,d) con peso w alla lista 
//  di adiacenza del nodo s e del nodo d
void add_edge(Graph&, int, int, float);

void BFS_visit(const Graph&, int);
bool is_connected(const Graph& g, int v = 1);

Graph build_graph(const char *, bool, bool);
void display_graph(const Graph &g);


#endif