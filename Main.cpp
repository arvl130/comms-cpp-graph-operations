#include "Data.h"
#include <iostream>
using namespace std;

int main() {
  // Tells whether to keep the program running or not.
  bool keep_going = true;

  Graph g(8);
  g.addEdge(0, 6);
  g.addEdge(1, 5);
  g.addEdge(2, 0);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 1);
  g.addEdge(4, 3);
  g.addEdge(5, 7);
  g.addEdge(6, 1);
  g.addEdge(6, 7);

  while (keep_going) {
    int ch, gr, tr;
    cout << endl;
    cout << "----------------" << endl;
    cout << "Graph Operations" << endl;
    cout << "----------------" << endl;
    cout << endl;

    cout << "[1] Create Graph" << endl;
    cout << "[2] Traversal" << endl;
    cout << "[3] Find Path" << endl;
    cout << "[4] Path Cost" << endl;
    cout << "[5] Exit" << endl;
    cout << "Enter choice: ";

    cin >> ch;
    switch (ch) {
    case 1:
      cout << "Graph Operations" << endl;
      cout << "[1] Adjacency List" << endl;
      cout << "[2] Adjacency Matrix" << endl;
      cout << "Enter choice: ";
      cin >> gr;

      if (gr == 1) {
        g.printGraph();
        cout << endl << "DFS Traversal..." << endl;
        g.DFS(1);
        cout << endl << endl;
        cout << endl << "BFS Traversal..." << endl;
        g.BFS(0);
      } else if (gr == 2) {
        g.printGraph2();
      }
      break;

    case 2:
      cout << "Traversal" << endl;
      cout << "[1] BFS" << endl;
      cout << "[2] DFS" << endl;
      cout << "Enter choice: ";
      cin >> tr;
      if (tr == 1) {
        cout << endl << "BFS Traversal..." << endl;
        g.BFS(0);
      } else if (tr == 2) {
        cout << endl << "DFS Traversal..." << endl;
        g.DFS(1);
      }

      cout << endl << endl;
      break;

    case 3: {
      // Find Path
      int dest, src;

      cout << "Enter a source: ";
      cin >> src;

      cout << "Enter a destination: ";
      cin >> dest;

      g.printAllPaths(src, dest);
    } break;

    case 4: { // Path Cost
      int dest, src;

      cout << "Enter a source: ";
      cin >> src;

      cout << "Enter a destination: ";
      cin >> dest;

      g.printCostOnAllPaths(src, dest);
    } break;

    case 5:
      keep_going = false;
      break;

    default:
      continue;
    }
  }
  return 0;
}
