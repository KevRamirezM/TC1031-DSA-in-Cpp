#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ArcListGraph {
    struct Arc {
        int from;
        int to;
    };

    int n;
    vector<Arc> arcs;

public:
    explicit ArcListGraph(int n) {
        this->n = n;
    }

    void addEdge(int u, int v) {
        if (u < 1 || u > n || v < 1 || v > n || hasEdge(u, v)) {
            return;
        }
        arcs.insert(arcs.begin(), {u, v});
    }

    bool hasEdge(int u, int v) {
        for (Arc& arc : arcs) {
            if (arc.from == u && arc.to == v) {
                return true;
            }
        }
        return false;
    }

    vector<int> outNeighbors(int u) {
        vector<int> result;
        if (u < 1 || u > n) {
            return result;
        }
        for (Arc& arc : arcs) {
            if (arc.from == u) {
                result.push_back(arc.to);
            }
        }
        return result;
    }

    vector<int> inNeighbors(int v) {
        vector<int> result;
        if (v < 1 || v > n) {
            return result;
        }
        for (Arc& arc : arcs) {
            if (arc.to == v) {
                result.push_back(arc.from);
            }
        }
        return result;
    }
};

static void printVec(const vector<int>& a) {
    if (a.empty()) {
        cout << "(empty)\n";
        return;
    }
    for (int i = 0; i < (int)a.size(); ++i) cout << (i ? " " : "") << a[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    ArcListGraph g(n);

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
        } else if (cmd == "OUT") {
            int u;
            cin >> u;
            printVec(g.outNeighbors(u));
        } else { // IN
            int v;
            cin >> v;
            printVec(g.inNeighbors(v));
        }
    }
    return 0;
}
