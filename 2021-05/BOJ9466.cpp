#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int T, N;
int wantTeam[100001];
int cnt;
bool visit[100001];
bool done[100001];

void DFS(int node) {
   stack<int> s;

   s.push(node);
   visit[node] = true;

   while (!s.empty()) {
      
      int currentNode = s.top();
      //cout << currentNode << endl;

      int nextNode = wantTeam[currentNode];
      if (!visit[nextNode]) {
         s.push(nextNode);
         visit[nextNode] = true;

      }
      else if (!done[nextNode]) {
         //cout << currentNode << " " << nextNode << endl;
         for (int i = nextNode; i != currentNode; i = wantTeam[i]) {
         //   cout <<"i:" << i << endl;
            cnt++;
         }
         cnt++;
         done[currentNode] = true;
         s.pop();
      }
      else {
         done[currentNode] = true;
         s.pop();
      }
   }


}

int main()
{
   cin >> T;

   for (int i = 0; i < T; i++) {
      for (int j = 1; j <= N; j++) {
         visit[j] = false;
         done[j] = false;
      }

      cin >> N;

      for (int j = 1; j <= N; j++)
         cin >> wantTeam[j];

      cnt = 0;
      for (int j = 1; j <= N; j++) {
         if(!visit[j])
            DFS(j);
      }
      cout << N - cnt << endl;

   }
}