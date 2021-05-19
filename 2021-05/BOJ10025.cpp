#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, K;
bool visit[200002];

int parentRecord[200002];
vector<int> record;
int dir[3] = { -1, 1, 2 };
int answer;
void BFS() {
   queue <pair<int,int>> q;
   
   q.push({ N, 0 });
   visit[N] = true;

   while (!q.empty()) {
      int cur = q.front().first;
      int time = q.front().second;
      q.pop();

      if (cur == K) {
         cout << time << endl;
         for (int i = cur; i != N; i = parentRecord[i]) { 
            record.push_back(i);
         }
         record.push_back(N);
         return;
      }

      for (int i = 0; i < 3; i++) {
         int next;
         if (i == 2) {
            next = cur * dir[i];
         }
         else {
            next = cur + dir[i];
         }

         if (next > 100000 or next < 0) {
            continue;
         }

         if (visit[next]) {
            continue;
         }

         q.push({ next, time + 1 });
         parentRecord[next] = cur;
         visit[next] = true;
      }
      
   }

}

int main() {
   cin >> N >> K;

   BFS();
   for (int i = 0; i < record.size(); i++) {
      cout << record[record.size() - i - 1] << " ";
   }


}
