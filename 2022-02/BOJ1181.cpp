#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;

vector<string> v;
unordered_map<string, bool> um;
bool compare(string a, string b) {
    if( a.length() < b.length()) {
        return true;

    } else if(a.length() == b.length()) {
        if(a < b) {
            return true;
        }
    }

    return false;
}


int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        if(um.find(temp) == um.end()){
            v.push_back(temp);
            um[temp] = true;
        }

    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << '\n';
    }

}