#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Implement a directed graph with vertices 1..n.
class ListGraph {
    vector<vector<int>> adjList;
public:
    explicit ListGraph(int n) {
        adjList.resize(n + 1);
    }

    // Adds the directed arc u -> v.
    void addEdge(int u, int v) {
        vector<int>& neighbors = adjList[u];
        for (int neighbor : neighbors) {
            if (neighbor == v) {
                return; // Edge already exists
            }
        }
        neighbors.push_back(v);
    }

    bool hasEdge(int u, int v) {
        vector<int>& neighbors = adjList[u];
        for (int neighbor : neighbors) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }

    vector<int>& neighbors(int u) {
        if (u >= 0 && u < adjList.size()) {
            return adjList[u];
        }
        static vector<int> empty;
        return empty;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    ListGraph g(n);

    for (int i = 0; i < q; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        } else if (command == "HAS") {
            int u, v;
            cin >> u >> v;
            cout << (g.hasEdge(u, v) ? "true" : "false") << '\n';
        } else { // NEIGHBORS
            int u;
            cin >> u;
            vector<int>& out = g.neighbors(u);
            if (out.empty()) {
                cout << "(empty)\n";
            } else {
                for (int j = 0; j < static_cast<int>(out.size()); ++j) {
                    cout << (j == 0 ? "" : " ") << out[j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
