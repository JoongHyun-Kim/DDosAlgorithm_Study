#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

// 1의 총 개수와 0의 총개수로 경우의 수 구하기_DFS
// 2진수로 변환했을 때 n보다 작으면 그냥 return
// n보다 크면
// 기존 정답보다 작은 수면 정답 갱신

int calcNum1(int n){
    int num1=0;
  while(1){
      if(n%2 == 1) num1++;
      n/=2;
      if(n == 0) break;
    }  
    
    return num1;
}

int solution(int n) {
    int num1=calcNum1(n);
    int cur = n+1;
    while(1){
        if(calcNum1(cur) == num1){
            answer = cur;
            break;
        }
        cur++;
    }
    
    return answer;
}
