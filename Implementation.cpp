#include "Data.h"
#include <iostream>
#include <list>

using namespace std;

Graph::Graph(int x) {
  V = x;
  adj = new list<int>[V];
  adj2 = new int *[V];

  for (int i = 0; i < V; i++)
    adj2[i] = new int[V];

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      adj2[i][j] = 0;
}

void Graph::addEdge(int u, int v) { adj[u].push_back(v); }

void Graph::addEdge2(int u, int v) { adj2[u][v] = 1; }

// A utility function to print the adjacency list
// representation of graph
void Graph::printGraph() {
  cout << "Adjacency List..." << endl;
  for (int v = 0; v < V; ++v) {
    cout << "V[" << v << "]";
    for (auto x : adj[v])
      cout << " -> " << x;
    cout << endl;
  }
}

void Graph::printGraph2() {
  cout << "Adjacency Matrix..." << endl << endl;
  cout << "\t";

  for (int i = 0; i < V; i++)
    cout << "V[" << i << "]"
         << "\t";
  cout << endl;

  for (int i = 0; i < V; i++) {
    cout << "V[" << i << "]"
         << "\t";
    for (int j = 0; j < V; j++)
      cout << adj2[i][j] << "\t";
    cout << endl;
  }
  cout << endl;
}

void Graph::DFSUtil(int v, bool visited[]) {
  // Mark the current node as visited and
  // print it
  visited[v] = true;
  cout << v << " ";

  // Recur for all the vertices adjacent
  // to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Call the recursive helper function
  // to print DFS traversal

  DFSUtil(v, visited);
  for (int i = 0; i < V; i++)
    if (!visited[i])
      DFSUtil(i, visited);

  for (int i = 0; i < V; i++)
    if (!visited[i])
      cout << i << " ";
}

void Graph::BFS(int s) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  BFSUtil(s, visited);
  for (int i = 0; i < V; i++)
    if (!visited[i])
      BFSUtil(i, visited);

  for (int i = 0; i < V; i++)
    if (!visited[i])
      cout << i << " ";
}

void Graph::BFSUtil(int s, bool visited[]) {
  // Create a queue for BFS
  list<int> queue;

  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  // 'i' will be used to get all adjacent
  // vertices of a vertex
  list<int>::iterator i;

  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    cout << s << " ";
    queue.pop_front();

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      if (!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

void Graph::printAllPaths(int src, int dest) {
  // Initialize all vertices as not visited.
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create an array to store paths.
  int *path = new int[V];
  int path_index = 0; // Initialize path[] as empty.

  // Reset path exists variable.
  path_exists = false;

  // Reset number of paths found.
  path_found_count = 0;

  // Call the recursive helper function to print all paths.
  cout << "Getting all possible paths...\n" << endl;
  printAllPathsUtil(src, dest, visited, path, path_index);

  if (!path_exists) {
    cout << "No path found." << endl;
  }
}

void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[],
                              int &path_index) {
  // Mark the current node and store it in path[]
  visited[u] = true;
  path[path_index] = u;
  path_index++;

  // If current vertex is same as destination,
  // then print current path[]
  if (u == d) {
    path_exists = true;
    path_found_count++;

    for (int i = 0; i < path_index; i++) {
      if (i != 0)
        cout << " -> " << path[i];
      else
        cout << "Path " << path_found_count << ": " << path[i];
    }

    cout << endl;
  } else // If current vertex is not destination
  {
    // Recur for all the vertices adjacent to current vertex.
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (!visited[*i])
        printAllPathsUtil(*i, d, visited, path, path_index);
  }

  // Remove current vertex from path[] and mark it as unvisited.
  path_index--;
  visited[u] = false;
}

void Graph::printCostOnAllPaths(int src, int dest) {
  // Initialize all vertices as not visited.
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create an array to store paths.
  int *path = new int[V];
  int path_index = 0; // Initialize path[] as empty.

  // Reset path exists variable.
  path_exists = false;

  // Reset number of paths found.
  path_found_count = 0;

  // Call the recursive helper function to print all paths.
  cout << "Getting cost on all possible paths..." << endl;
  printCostOnAllPathsUtil(src, dest, visited, path, path_index);

  if (!path_exists) {
    cout << endl;
    cout << "No path found." << endl;
  }
}

void Graph::printCostOnAllPathsUtil(int u, int d, bool visited[], int path[],
                                    int &path_index) {
  // Mark the current node and store it in path[]
  visited[u] = true;
  path[path_index] = u;
  path_index++;

  // If current vertex is same as destination,
  // then print current path[]
  if (u == d) {
    path_exists = true;
    path_found_count++;

    cout << endl;
    cout << "Path " << path_found_count << ":" << endl;

    int path_cost = 0;
    for (int i = 0; i < path_index; i++) {
      path_cost++;
    }

    if (path_cost - 1 == 1)
      cout << "Cost: " << path_cost - 1 << " hop from origin. Path:";
    else
      cout << "Cost: " << path_cost - 1 << " hops from origin. Path:";

    for (int i = 0; i < path_index; i++) {
      if (i != 0)
        cout << " -> " << path[i];
      else
        cout << " " << path[i];
    }

    cout << endl;
  } else // If current vertex is not destination
  {
    // Recur for all the vertices adjacent to current vertex.
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (!visited[*i])
        printCostOnAllPathsUtil(*i, d, visited, path, path_index);
  }

  // Remove current vertex from path[] and mark it as unvisited.
  path_index--;
  visited[u] = false;
}