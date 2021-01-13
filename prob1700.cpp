#include <iostream>

using namespace std;

int main() {
    int multitapnum;
    int devicenumber;

    cin >> multitapnum >> devicenumber;

    int* devicename = new int[devicenumber]; 
    int* multitap = new int[multitapnum];
    bool isplugged[101]={false,};

    int cnt=0;

    for(int i=0; i<devicenumber ; i++){
        cin >> devicename[i];
    }
    int index=0;
    for(int i=0; i<devicenumber; i++){

        if(isplugged[devicename[i]]) {// 이미꽂혀있는 경우
           // cout << "1:"<< devicename[i] << endl;
             continue;
        }

        if(index < multitapnum) { // 멀티탭이 꽉차지 않았을 때 
            multitap[index] = devicename[i];
            isplugged[devicename[i]] = true;
            index++;
        //    cout << "2:"<< devicename[i] << endl;
        }
        else { // find which multitap plug out, 멀티탭 꽉참
            int plugindex=0;
            int deviceindex=0;
           
            int flag=0;
           for(int j=0 ; j<multitapnum ; j++) {
               int tempindex=0;
               flag =0;
               for(int k= i+1; k<devicenumber; k++) {
                   if(multitap[j] == devicename[k]) {
                       tempindex = k;
                       flag =1;
                       break;
                   }
               }
               if(flag == 0 ) { // 사용할 장치 목록에 없음 => 콘센트 제거 대상 1순위
                    plugindex= j;
                    break;
               }
               else if(deviceindex < tempindex){
                   plugindex= j;
                   deviceindex = tempindex;
               }
           }
          
            isplugged[multitap[plugindex]] = false;
            multitap[plugindex] = devicename[i];
            isplugged[devicename[i]] = true;


           cnt++;
          //cout << multitap[0] << " " << multitap[1] << endl;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}