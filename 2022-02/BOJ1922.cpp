#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
typedef struct obj {
    int weight;
    int from;
    int to;
} Obj;

vector<Obj> v;
int parent[10001];

bool compare(Obj a, Obj b) {
    if(a.weight < b.weight) {
        return true;
    } else {
        return false;
    }
}

int find_root(int vertex) {
    if(parent[vertex] == vertex) {
        return vertex;
    } else {
        return find_root(parent[vertex]);
        // 성능 개선을 위해 트리 구조 변형해주기도 있음. (unbalanced tree에 대한 대비)
        // return parent[vertex] = find_root(parent[vertex]);
    }
}


int main() {
    cin >> V >> E;

    for(int i=1; i<=V; i++) {
        parent[i] = i;
    }

    for(int i=0; i<E; i++) {
        int from, to, value;
        cin >> from >> to >>value;

        v.push_back({value, from, to});

    }

    sort(v.begin(), v.end(), compare);

    int ans = 0;
    for(int i=0; i<v.size(); i++) {

        int v1 = find_root(v[i].from);
        int v2 = find_root(v[i].to);

        if(v1 != v2) {
            if(v1 > v2) {
                parent[v2] = v1;
            } else {
                parent[v1] = v2;
            }

            ans += v[i].weight;
        }
    }

    cout << ans << '\n';


}