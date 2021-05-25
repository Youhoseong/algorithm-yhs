/*
-> cycle은 dfs
-> cycle여부를 단 한번의 dfs탐색으로 체크 하지 않아도 된다.

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct info {
    int now, t;
};

int n;
bool visit[3000];
bool cycle[3000];

vector<int> dist[3000];

void dfs(int start, int cur, int cnt) {
    if (start == cur && cnt >= 3) {
        cycle[cur] = true;
        return;
    }
    visit[cur] = true;
    for (int i = 0; i < dist[cur].size(); i++) {
        int next = dist[cur][i];

        if (!visit[next]) dfs(start, next, cnt + 1);
        else if (start == next && cnt >= 2) dfs(start, next, cnt+1);


    }
}

int bfs(int start) {
    queue <info> q;
    bool visit[3000] = { false, };

    q.push({ start, 0 });
    visit[start] = true;

    while (!q.empty()) {
        info t = q.front();
        q.pop();
        int now = t.now;
        int time = t.t;

        if (cycle[now]) {
            return time;
        }

        for (int i = 0; i < dist[now].size(); i++) {
            int next = dist[now][i];

            if (visit[next]) continue;

            q.push({ next, time + 1 });
            visit[next] = true;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;
        a--; b--;
        dist[a].push_back(b);
        dist[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        memset(visit, false, sizeof(visit));
        dfs(i, i, 0);

    }

    for (int i = 0; i < n; i++) {
        if (cycle[i]) {
            cout << 0 << ' ';
            continue;
        }
        cout << bfs(i) << ' ';
    }
    puts("");

    return 0;
}