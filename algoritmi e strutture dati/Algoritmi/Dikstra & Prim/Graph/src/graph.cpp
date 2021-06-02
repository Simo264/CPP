#include "../include/graph.hpp"
#include <iostream>
#include <queue>
#include <fstream>


int get_dim(const Graph &g)                         { return g.dim; }
adj_list get_adjlist(const Graph &g, const int i)   { return g.nodes[i - 1]; }
int get_adjnode(const adj_node *node)               { return node->value + 1; }
adj_list get_nextadj(const adj_list &nodes)         { return nodes->next; }
Graph new_graph(int n)
{
    Graph g{new adj_list[n], n};
    for (int i = 0; i < n; i++)
        g.nodes[i] = new adj_node{i + 1, 0, nullptr};
    return g;
}

void add_arc(Graph &g, int s, int d, float w)
{
    if (s > g.dim || d > g.dim)
    {
        std::cout << "In function " << __PRETTY_FUNCTION__
                  << " 'source' or 'dest' is not valid" << std::endl;
        return;
    }

    auto node = g.nodes[s - 1];
    auto arch = node->next;
    if (arch)
    {
        while (arch->next)
            arch = arch->next;
        arch->next = new adj_node{d, w, nullptr};
    }
    else
        node->next = new adj_node{d, w, nullptr};
}
void add_edge(Graph &g, int s, int d, float w)
{
    add_arc(g, s, d, w);
    add_arc(g, d, s, w);
}

void BFS_visit(const Graph &g, int v)
{
    if(v <= 0  || v > g.dim)
    {
        std::cout << __PRETTY_FUNCTION__ << " ['v' is not valid]" << std::endl;
        return;
    }

    if (g.dim > 0)
    {
        bool *reached = new bool[g.dim];
        for (int i = 0; i < g.dim; i++)
            reached[i] = false;

        std::queue<int> q;
        q.push(v);

        reached[v - 1] = true;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            std::cout << "#" << u << " ";

            auto node = g.nodes[u - 1];
            auto arch = node->next;
            std::cout << "\tVisito i vicini di " << u << " che non sono stati scoperti: ";

            while (arch)
            {
                int w = arch->value;
                if (!reached[w - 1])
                {
                    std::cout << w << " ";
                    reached[w - 1] = true;
                    q.push(w);
                }
                arch = arch->next;
            }
            std::cout << std::endl;
        }

        delete[] reached;
    }
}
bool is_connected(const Graph &g, int v)
{
    if(v <= 0  || v > g.dim)
    {
        std::cout << __PRETTY_FUNCTION__ << " ['v' is not valid]" << std::endl;
        return false;
    }

    if (g.dim > 0)
    {
        bool *reached = new bool[g.dim];
        for (int i = 0; i < g.dim; i++)
            reached[i] = false;

        std::queue<int> q;
        q.push(v);

        reached[v - 1] = true;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            auto node = g.nodes[u - 1];
            auto arch = node->next;

            while (arch)
            {
                int w = arch->value;
                if (!reached[w - 1])
                {
                    reached[w - 1] = true;
                    q.push(w);
                }
                arch = arch->next;
            }
        }

        bool connected = true;
        for (int i = 0; i < g.dim && connected; i++)
            if (!reached[i])
                connected = false;    
        
        delete[] reached;
        return connected;
    }

    return false;
}


Graph build_graph(const char *filename, bool oriented, bool weighted)
{
    Graph g{nullptr, 0};

    std::ifstream ifs(filename);
    if (ifs)
    {
        int num_of_nodes;
        ifs >> num_of_nodes;
        g = new_graph(num_of_nodes);

        if (!weighted)
        {
            int source, dest;
            while (ifs >> source >> dest)
                add_edge(g, source, dest, 0);
        }
        else if (weighted)
        {
            int source, dest, weight;
            while (ifs >> source >> dest >> weight)
                add_edge(g, source, dest, weight);
        }
        ifs.close();
    }

    return g;
}
void display_graph(const Graph &g)
{
    for (int i = 0; i < g.dim; i++)
    {
        std::cout << g.nodes[i]->value << " ";
        auto arch = g.nodes[i]->next;
        while (arch)
        {
            if (arch->weight == 0)
                std::cout << " --> " << arch->value;
            else
                std::cout << " --(" << arch->weight << ")-> " << arch->value;

            arch = arch->next;
        }
        std::cout << std::endl;
    }
}
