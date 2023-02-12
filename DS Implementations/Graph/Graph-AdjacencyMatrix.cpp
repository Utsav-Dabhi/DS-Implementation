#include<iostream>
using namespace std;

struct Graph {
    bool** adjMatrix;
    int noOfVertices;
};

void createGraph(Graph* g, int vert) {
    g->noOfVertices = vert;
    g->adjMatrix = new bool*[vert];

    // intialize the matrix
    for (int i = 0; i < vert; i++) {
        g->adjMatrix[i] = new bool[vert];

        for (int j = 0; j < vert; j++) {
            g->adjMatrix[i][j] = false;
        }
    }
}

pair<int, int> acceptAndCheckInput(Graph* g) {
    int v1, v2;
    cout << "\nEnter vertices: ";
    cin >> v1 >> v2;

    while (v1 >= g->noOfVertices) {
        cout << "\nVertex " << v1 << " does not exist!";
        cout << "Re-enter v1: ";
        cin >> v1;
    }

    while (v2 >= g->noOfVertices) {
        cout << "\nVertex " << v2 << " does not exist!";
        cout << "Re-enter v2: ";
        cin >> v2;
    }

    pair<int, int> p = {v1, v2};

    return p;
}

void addEdge(Graph* g, int v1, int v2) {
    g->adjMatrix[v1][v2] = true;
    g->adjMatrix[v2][v1] = true;
}

void removeEdge(Graph* g, int v1, int v2) {
    g->adjMatrix[v1][v2] = false;
    g->adjMatrix[v2][v1] = false;
}

void areAdjacent(Graph* g, int v1, int v2) {
    if (g->adjMatrix[v1][v2] == true) {
        cout << "\n" << v1 << " and " << v2 << " are adjacent" << endl;
    } else {
        cout << "\n" << v1 << " and " << v2 << " are not adjacent" << endl;
    }
}

void printGraph(Graph* g) {
    cout << "\nThe graph is: " << endl;
    cout << "    ";
    for (int i = 0; i < g->noOfVertices; i++) {
        cout << i << " ";
    }
    cout << endl << "    ";
    for (int i = 0; i < g->noOfVertices; i++) {
        cout << "_" << " ";
    }
    cout << endl;

    for (int i = 0; i < g->noOfVertices; i++) {
        cout << i << ":  ";

        for (int j = 0; j < g->noOfVertices; j++) {
            cout << g->adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
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