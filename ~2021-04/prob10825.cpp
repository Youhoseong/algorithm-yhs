#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct kme {
    string name;
    int K, M, E;
};

bool cmp(kme a, kme b){
  	if (a.K == b.K && a.E == b.E && a.M == b.M) return a.name < b.name;
	else if (a.K == b.K && a.E == b.E) return a.M > b.M;
	else if (a.K == b.K) return a.E < b.E;
	else return a.K > b.K;
}
int main(){
    int N;
    cin >> N;

    vector<kme> v(N);

    for(int i=0; i<N;i++) {
        cin >> v[i].name >> v[i].K >> v[i].E >> v[i].M;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0 ; i<N; i++)
       cout <<  v[i].name << '\n';
    return 0;
}