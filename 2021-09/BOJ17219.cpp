#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<string, string> um;

    for(int i=0; i<N; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;

        um[temp1] = temp2;
    }

    for(int i=0; i<M; i++) {
        string temp1;
        cin >> temp1;

        cout << um[temp1] << '\n';
    }


}