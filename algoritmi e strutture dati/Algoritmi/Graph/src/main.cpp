#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
#include "../include/graph.hpp"
#include "../include/codap.hpp"
constexpr int infinite = std::numeric_limits<int>::max();

void init_dijkstra(const Graph &g, int source, int *parent, float *distance)
{
    std::cout << "Start to node #" << source << std::endl;

    for (int i = 0; i < g.dim; i++)
    {
        distance[i] = infinite;
        parent[i] = 0;
    }
    distance[source - 1] = 0;
}
void relax_dijkstra(int u, int v, float w, int *parent, float *distance)
{
    if (distance[u - 1] + w < distance[v - 1])
    {
        distance[v - 1] = distance[u - 1] + w;
        parent[v - 1] = u;
    }
}
void dijkstra(const Graph &g, int source, int *parent, float *distance)
{
    init_dijkstra(g, source, parent, distance);
    
    codap queue = NULL;
	for (int i = 1; i <= g.dim; i++) 
		queue = enqueue(queue, i, distance[i - 1]);

    while (!isEmpty(queue))
    {
        int u = dequeue(queue);

        // for each node v adjacent with node u do
        auto arch = g.nodes[u - 1]->next;
        while (arch)
        {
            int v = arch->value;
            float w = arch->weight;
            
            relax_dijkstra(u, v, w, parent, distance);
            
            queue = Decrease_Priority(queue, v, distance[v - 1]);
            arch = arch->next;
        }
    }
}

void init_prim(const Graph &g, int source, int *parent, float *key)
{
    std::cout << "Start to node #" << source << std::endl;

    for (int i = 0; i < g.dim; i++)
    {
        key[i] = infinite;
        parent[i] = 0;
    }
    key[source - 1] = 0;
}
void relax_prim(int u, int v, float w, int *parent, float *key)
{
    if (key[v - 1] > w)
    {
        key[v - 1] = w;
        parent[v - 1] = u;
    }
}
void prim(const Graph &g, int source, int *parent, float *key)
{
    init_prim(g, source, parent, key);

    codap queue = NULL;
	for (int i = 1; i <= g.dim; i++) 
		queue = enqueue(queue, i, key[i - 1]);

    while(!isEmpty(queue))
    {
        auto u = dequeue(queue);

        // for each node v adjacent with node u do
        auto arch = g.nodes[u - 1]->next;
        while (arch)
        {
            int v = arch->value;
            float w = arch->weight;
            relax_dijkstra(u, v, w, parent, key);
            queue = Decrease_Priority(queue, v, key[v - 1]);
            arch = arch->next;
        }
    }
}


int main()
{
    // Build Graph
    bool oriented = false;
    bool weighted = true;
    Graph g = build_graph("../res/graph1.w", oriented, weighted);

    // Dijkstra algorithm
    int *parent = new int[g.dim]();
    float *distance = new float[g.dim]();
    int source = 7;

    dijkstra(g, source, parent, distance);

    std::cout << "\n\n#Node\tShortest distance\tParent\n";
    for (int i = 0; i < g.dim; i++)
        std::cout << "#" << i + 1 << "\t" << distance[i] << "\t\t\t" << parent[i] << std::endl;
    

    return 0;
}