#include "graph.h"

int main() {
  graph G;
  // Starting from vertex s
  char root = 'a';

  G.prim(root);
    
  G.primPrint(root);
}
