#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class EdgeListGraph {
    int n;
    vector<pair<int, int>> edges;
public:
    explicit EdgeListGraph(int n) {
        this->n = n;
    }

    void addEdge(int u, int v) {
        if (u < 1 || u > n || v < 1 || v > n || hasEdge(u, v)) {
            return;
        }
        edges.emplace_back(u, v);
    }

    bool hasEdge(int u, int v) {
        for (pair<int, int>& edge : edges) {
            if (edge.first == u && edge.second == v) {
                return true;
            }
        }
        return false;
    }

    vector<int> neighbors(int u) {
        vector<int> result;
        if (u < 1 || u > n) {
            return result;
        }
        for (pair<int, int>& edge : edges) {
            if (edge.first == u) {
                result.push_back(edge.second);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    EdgeListGraph g(n);

    for (int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        } else if (cmd == "HAS") {
            int u, v;
            cin >> u >> v;
            cout << (g.hasEdge(u, v) ? "true" : "false") << '\n';
        } else { // NEIGHBORS
            int u;
            cin >> u;
            vector<int> out = g.neighbors(u);
            if (out.empty()) cout << "(empty)\n";
            else {
                for (int i = 0; i < (int)out.size(); ++i) cout << (i ? " " : "") << out[i];
                cout << '\n';
            }
        }
    }
    return 0;
}
