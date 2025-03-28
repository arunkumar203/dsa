#include <iostream>
#include <vector>
using namespace std;
bool isCyclicUtil(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& stack) {
  visited[node] = true;
  stack[node] = true;

  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      if (isCyclicUtil(neighbor, graph, visited, stack)) {
        return true;
      }
    } else if (stack[neighbor]) {
      return true;
    }
  }

  stack[node] = false;
  return false;
}
bool isCyclic(int numNodes, vector<vector<int>>& graph) {
  vector<bool> visited(numNodes, false);
  vector<bool> stack(numNodes, false);

  for (int i = 0; i < numNodes; ++i) {
    if (!visited[i]) {
      if (isCyclicUtil(i, graph, visited, stack)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int numNodes = 4;
  vector<vector<int>> graph(numNodes);
  graph[0].push_back(1);
  graph[0].push_back(2);
  graph[1].push_back(2);
  graph[2].push_back(0);
  graph[2].push_back(3);
  graph[3].push_back(3);
  if (isCyclic(numNodes, graph)) {
    cout << "The graph contains a cycle." << endl;
  } else {
    cout << "The graph does not contain a cycle." << endl;
  }

  return 0;
}