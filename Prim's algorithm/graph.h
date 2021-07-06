#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <iostream>

// Forward declaration of vertex class
class vertex;

class edge
{
public:
    vertex *v;
    int weight;
    
    edge(vertex* vt,int w)
    {
        v = vt; weight = w;
    }
};

// Each vertex contains within it a list of edges
// to the other vertices the vertex is connected to.
class vertex
{
public:
    char key;
    int d;
    vertex *p;
    std::vector<edge> edges;
    
    vertex() {}
    vertex(char v) { key = v; d = 0; p = nullptr; }
};

class VComp {
public:
    bool operator()(vertex* one,vertex* two) {
        return (one->d < two->d) || (one->d == two->d && one < two);
    }
};

class graph
{
public:
    graph();
    ~graph();
    void prim(char root);
    void primPrint(char current);
private:
    // Since the edges are stored in the vertices, we only need
    // a list of vertices in the graph.
    std::vector<vertex*> verts;
    // For convenience, we also set up a map that maps vertex labels
    // to vertices
    std::map<char,vertex*> V;
    int INFINITY;
};

graph::graph()
{
    INFINITY = 100000;
    std::ifstream in;
    in.open("vertices.txt");
    
    char key;
    while (in >> key) {
        vertex* newVert = new vertex(key);
        V[key] = newVert;
        verts.push_back(newVert);
    }
    in.close();
    
    in.open("edges.txt");
    char start, end;
    int dist;
    while(in >> start >> end >> dist) {
        vertex *u = V[start];
        vertex *v = V[end];
        u->edges.push_back(edge(v,dist));
    }
    in.close();
}

graph::~graph() {
    std::map<char,vertex*>::iterator itr = V.begin();
    while(itr != V.end()) {
        delete itr->second;
        itr++;
    }
}

void graph::prim(char root) {
    std::set<vertex*,VComp> Q;
    std::vector<vertex*>::iterator  itr = verts.begin();
    while(itr != verts.end()) {
        vertex *v = *itr;
        if(v->key != root) {
            v->d = INFINITY;
            v->p = nullptr;
        } else {
            v->d = 0;
            v->p = v;
        }
        Q.insert(v);
        itr++;
    }
    
    while(!Q.empty() ) {
        vertex* u = *(Q.begin());
        Q.erase(Q.begin());
        
        std::vector<edge>& edges = u->edges;
        std::vector<edge>::iterator itr2 = edges.begin();
        while(itr2 != edges.end()) {
            vertex* v = itr2->v;
            if(Q.find(v) != Q.end() && itr2->weight < v->d) { // + u->d ?
                Q.erase(Q.find(v));
                v->p = u;
                v->d = itr2->weight;
                Q.insert(v);
            }
            itr2++;
        }
    }
}

void graph::primPrint(char current) {
    vertex *u = V[current];
    std::vector<edge>& edges = u->edges;
    std::vector<edge>::iterator itr = edges.begin();
    while (itr != edges.end()) {
        vertex* v = itr->v;
        if (v->p == u) {
            std::cout << current << " " << v->key << " " << itr->weight << std::endl;
            std::cout << v->key << " " << current << " " << itr->weight << std::endl;
            primPrint(v->key);
        }
    itr++;
    }
}
