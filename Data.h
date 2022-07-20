#pragma once
#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
  int V;
  list<int> *adj;                      // Programmer2
  int **adj2;                          // Programmer2
  void DFSUtil(int v, bool visited[]); // Lead
  void BFSUtil(int s, bool visited[]); // Lead
  bool path_exists = false;
  int path_found_count = 0;
  void printAllPathsUtil(int, int, bool[], int[], int &);
  void printCostOnAllPathsUtil(int, int, bool[], int[], int &);

public:
  Graph(int);                  // All
  void addEdge(int u, int v);  // All
  void addEdge2(int u, int v); // Programmer2
  void printGraph();           // All
  void printGraph2();          // Programmer2
  void DFS(int v);             // Lead
  void BFS(int s);             // Lead
  void printAllPaths(int src, int dest);
  void printCostOnAllPaths(int src, int dest);
};
