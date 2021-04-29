/*
1. 이분탐색
2. max, min값을 잘 이해하고, 변수 크기에 대한 이해 필요

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;



bool comp(int a, int b) {
    return a > b;
}

int main() {
    int K, N;
   
    vector<long long> v;
    //vector<bool> lenVector;
    scanf("%d %d", &K, &N);


    for(int i=0 ; i<K; i++){
        int temp;

        scanf("%d", &temp);
        v.push_back(temp);

    }
    
    sort(v.begin(), v.end(), comp);
    long long maxLength = v[0];

    long long minLength = 1;
    long long answer = 0;

    while(minLength<=maxLength) {
        long long mid = (maxLength + minLength) / 2;

        long long sum = 0;
        for(int i=0; i<v.size(); i++){
            sum += (v[i] / mid);

            if(sum >= N) 
                break;

        }

        if(sum>=N) {
            answer = mid;
            minLength = mid +1;
        }
        else {
            maxLength = mid -1;
        }
        
    }
    printf("%lld", answer);

}