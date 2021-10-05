#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


string s;
int dp[201][201];

vector<int> get_proper_div(int divUnit) {
    vector<int> temp;
    for(int i=1; i<divUnit; i++){
        if(divUnit % i == 0) {
            temp.push_back(i);
        }
    }

    return temp;
}

bool can_compress(int startidx, int endidx, int item) {
    for(int i=startidx; i< endidx; i+= item){
        if(s.substr(startidx, item) != s.substr(i, item)) {
            return false;
        }
    }
    return true;
}

int get_length(int num) {
    int pivot = 1, ret = 0;

    while(num /pivot) {
        pivot *= 10, ret++;
    }

    return ret;
}


int main() {
    cin >> s;
    int n = s.length();

    for(int i=0; i<n ; i++) {
        dp[i][i+1] = 1;
    }

    for(int i=2; i<=n; i++) {
        vector<int> divs = get_proper_div(i);

        for(int idx=0; idx <= n-i; idx++) {
            int compressedLength = i;

            for(int item: divs) {
                if(can_compress(idx, idx+i, item)) {
                    compressedLength = min(compressedLength, 2 + dp[idx][idx+item] + get_length(i / item));
                }
            }

            for(int j=idx+1; j< idx + i ; j++) {
                compressedLength = min(compressedLength, dp[idx][j] + dp[j][idx+i]);
            }

            dp[idx][idx+i] = compressedLength;

        }

    }


    cout << dp[0][n];

}