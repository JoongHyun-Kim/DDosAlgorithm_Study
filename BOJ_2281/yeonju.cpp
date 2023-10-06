#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
int n, m;
int name[1005];
int DP[1005]; // i번째 이름을 처음으로 쓸 경우의 공백의 최솟값
int paper;

int writeName(int idx) { 
  // 계산한 적이 있다면 그걸 리턴
    if (DP[idx] < INT_MAX){
        return DP[idx];
    }
    
    int blank = m - name[idx]; //잔여 칸수

    for (int i = idx + 1; i <= n && blank >= 0; i++) { 
      // 마지막 이름은 더이상 빈칸 계산 필요 X
        if (i == n) { 
            DP[idx] = 0;
            break;
        }
      
      // 이어 쓴 경우와 내려 쓴 경우 중 최소
        DP[idx] = min(DP[idx], blank * blank + writeName(i));
        blank -= name[i] + 1; //종이를 이어붙인 경우용
    }
    return DP[idx];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  // 입력 받기
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> name[i];
    }

  // 공백 결과 DP 초기화
    for(int i=0;i<n-1;i++){
      DP[i] = INT_MAX;
    }
    DP[n-1] = 0; //마지막 줄은 공백 계산 필요 X
  
    cout<<writeName(0)<<endl;
}
