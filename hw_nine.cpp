#include <iostream>
#include <list>

using namespace std;

class algraph {
  int numVertices;
  list<int>* adjLists;
  bool* visited; 

   public:
  algraph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

//граф түзүү 
algraph::algraph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// графка кырларын кошуу
void algraph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS алгоритми
void algraph::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
 algraph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}

