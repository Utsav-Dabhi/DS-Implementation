#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

struct Graph {
    int numOfVertices;
    list<int> *adjList;
};

pair<int, int> acceptAndCheckInput(Graph* g) {
    int v1, v2;
    cout << "\nEnter vertices: ";
    cin >> v1 >> v2;

    while (v1 >= g->numOfVertices) {
        cout << "\nVertex " << v1 << " does not exist!";
        cout << "Re-enter v1: ";
        cin >> v1;
    }

    while (v2 >= g->numOfVertices) {
        cout << "\nVertex " << v2 << " does not exist!";
        cout << "Re-enter v2: ";
        cin >> v2;
    }

    pair<int, int> p = {v1, v2};

    return p;
}

void createGraph(Graph* g, int vert) {
    g->numOfVertices = vert;
    g->adjList = new list<int>[vert];
}

void addEdge(Graph* g, int v1, int v2) {
    g->adjList[v1].push_back(v2);
    g->adjList[v2].push_back(v1);
}

void removeEdge(Graph* g, int v1, int v2) {
    g->adjList[v1].remove(v2);
    g->adjList[v2].remove(v1);
}

void areAdjacent(Graph* g, int v1, int v2) {
    int mini = min(v1, v2);
    int maxi = max(v1, v2);

    bool found = (find(g->adjList[mini].begin(), g->adjList[mini].end(), maxi) != g->adjList[mini].end());

    if (found) {
        cout << "\n" << v1 << " and " << v2 << " are adjacent" << endl;
    } else {
        cout << "\n" << v1 << " and " << v2 << " are not adjacent" << endl;
    }
}

void printGraph(Graph* g) {
    cout << "\nThe graph is: " << endl;
    for (int i = 0; i < g->numOfVertices; i++) {
        cout << "\nVertex " << i << ": ";
        list<int> :: iterator it;
        for(it = g->adjList[i].begin(); it != g->adjList[i].end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;
}

int main() {
    Graph gph;

    int i = 0;
    while (i != 5) {
        cout << "\nWhat operation do you want to perform?\n1. Create a graph\n2. Add edge\n3. Remove edge\n4. Are adjacent?\n5. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int vert;
                cout << "\nEnter no of vertices: ";
                cin >> vert;

                createGraph(&gph, vert);
                printGraph(&gph);

                break;

            case 2: {
                pair<int, int> pr = acceptAndCheckInput(&gph);

                addEdge(&gph, pr.first, pr.second);
                printGraph(&gph);
            }

                break;

            case 3: {
                pair<int, int> pr = acceptAndCheckInput(&gph);

                removeEdge(&gph, pr.first, pr.second);
                printGraph(&gph);
            }

                break;

            case 4: {
                pair<int, int> pr = acceptAndCheckInput(&gph);

                areAdjacent(&gph, pr.first, pr.second);
            }

                break;

            case 5:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}