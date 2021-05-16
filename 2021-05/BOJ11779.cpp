#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
#define INF 1000000000
using namespace std;

int N;
int bus;

int startCity, endCity;
vector<pair<int, int> > vec[1001];
int minCost[1001];
int trace[1001];

void dijkstra(int start) {
   queue<int> pq;
   minCost[start] = 0;

   pq.push(start);
   
   while (!pq.empty()) {
      int current = pq.front();
      int cost = minCost[current];

      pq.pop();

      for (int i = 0; i < vec[current].size(); i++) {
         int next = vec[current][i].first;
         int nextCost = vec[current][i].second + cost;

         if (nextCost < minCost[next]) {
            minCost[next] = nextCost;
            pq.push(next);
            trace[next] = current;
         }

      }
   }
   

}

int main() {
   cin >> N;
   cin >> bus;
   for (int i = 1; i <= N; i++) {
      minCost[i] = INF;
   }

   for (int i = 0; i < bus; i++) {
      int x, y, z;

      cin >> x >> y >> z;

      vec[x].push_back(make_pair(y, z));
   }

   cin >> startCity >> endCity;

   dijkstra(startCity);
   
   cout << minCost[endCity] << '\n';

   stack<int> ans;
   int u = endCity;
   while (true)
   {
      ans.push(u);
      if (u == startCity) break;
      u = trace[u];
   }
   cout << ans.size() << '\n';
   
   while (!ans.empty())
   {
      cout << ans.top() << " ";
      ans.pop();
   }

}