##
<center> [Z] </center>

---

- 풀이날짜: 2021-03-21 
- 작성자: 유호성
- 문제번호: 1074

 \* 메모 \*

    - 풀었던 문제
    - 풀었던 문제도 난 헤매.

 \* 핵심 아이디어 \*  
 
    1. 처음에는 분할-재귀를 이용해서 2^N * 2^N 배열 값을 모두 채웠음 => 공간복잡도 초과
    2. 분할-재귀를 이용해서 배열 값을 사용하지 않고 모든 값을 카운트하여 row, col 일치 시 종료하도록 함 => 시간 복잡도 초과
    3. 정답 row, col이 어느 사분면에 속했는지에 따라 count 계산값을 생략하는 법을 사용해야 함. 한 사분면 당 4^N-1 의 skip을 할 수 있다. 

    

\* 소스 코드 \*
```c++
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, row, col;

    cin >> N >> row >> col;

    int standX = pow(2, N) / 2;
    int standY = standX;
    int ans=0;

    for(int i=N-1; i>=0 ; i--){
        int diff = pow(2, i) / 2;
        int skip = pow(4, i);

        if(row < standY && col < standX) { // 1사분면
            standY -= diff;
            standX -= diff;
            //cout << "1사분면:" << ans << endl;
        } 
        else if(row < standY && col >= standX) { //2사분면
            standY -= diff;
            standX += diff;
            ans += skip;
           // cout << "2사분면:" << ans << endl;
        }
        else if(row >= standY && col <standX) { //3사분면
            standY += diff;
            standX -= diff;
            ans += skip * 2;
            //cout << "3사분면:" << ans << endl;
        }
        else { //4사분면
            standY += diff;
            standX += diff;
            ans += skip * 3;
           // cout << "4사분면:" << ans << endl;
        }

    }

    cout << ans << endl;

}

```