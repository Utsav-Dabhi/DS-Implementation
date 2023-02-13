#include<iostream>
#include<list>
using namespace std;

bool* visited;

struct Graph {
    int numOfVertices;
    list<int> *adjLists;
};

void createGraph(Graph* g, int vert) {
    g->numOfVertices = vert;
    g->adjLists = new list<int>[vert];
    visited = new bool[vert];
}

void addEdge(Graph* g, int v1, int v2) {
    g->adjLists[v1].push_back(v2);
    g->adjLists[v2].push_back(v1);
}

void dfs(Graph* g, int startVert) {
    visited[startVert] = true;

    list<int> adjList = g->adjLists[startVert];

    cout << startVert << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); i++)
        if (!visited[*i])
            dfs(g, *i);
}

void printGraph(Graph* g) {
    cout << "\nThe graph is: " << endl;
    for (int i = 0; i < g->numOfVertices; i++) {
        cout << "\nVertex " << i << ": ";
        list<int> :: iterator it;
        for(it = g->adjLists[i].begin(); it != g->adjLists[i].end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;
}

int main() {
    Graph gph;

    int vert;
    cout << "\nEnter no of vertices: ";
    cin >> vert;

    createGraph(&gph, vert);
    printGraph(&gph);

    int noOfEdges;
    cout << "\nEnter no of edges to be added: ";
    cin >> noOfEdges;

    int v1, v2;
    for (int i = 0; i < noOfEdges; i++) {
        cout << "\nEnter vertices between whom edge is to be added: ";
        cin >> v1 >> v2;
        addEdge(&gph, v1, v2);
    }

    printGraph(&gph);

    int startVert;
    cout << "\nEnter start vertex for dfs traversal: ";
    cin >> startVert;

    cout << "\nDFS traversal: ";
    dfs(&gph, startVert);
    
    return 0;
}