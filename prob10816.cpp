#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int lower_bound(int* N, int size, int havetofind) {
    int start, end, mid;
    start = 0;
    end = size-1;
   while (end > start){
        mid = (start + end) / 2;
        if (N[mid] >= havetofind)
            end = mid;
        else start = mid + 1;
    }
    return end;


}
int upper_bound(int* N, int size,int havetofind) {
    int start, end, mid;
    start = 0;
    end = size-1;

    while (end > start) {
        mid = (start + end) / 2;
        if (N[mid] > havetofind)
            end = mid;
        else start = mid + 1;
    }
    return end;
}



int main() {
    int N, M;
    cin >> N;
    int *N_array = new int[N];

    for(int i=0; i<N ; i++){
        cin >> N_array[i];
    }

    cin >> M; 
    int *M_array = new int[M];
    int *result = new int[M];

    for(int i=0; i<M ; i++){
        cin >> M_array[i];
    }
    sort(N_array, N_array+N);

    for(int i=0; i<M; i++){
        int lower = lower_bound(N_array, N, M_array[i]);
        int upper = upper_bound(N_array, N, M_array[i]);
        if(upper == N-1 && N_array[N-1] == M_array[i])
            upper++;
        
        result[i]= upper-lower;
    }

    for(int i=0; i<M; i++)
        cout << result[i] << " ";

    cout << '\n';

    return 0;
}