#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 경우의 수 계산을 통해 출력한다
// index i의 전체 경우의 수는 (i-1)! 이다. // i는 1부터 시작해야 한다.
// 경우의 수의 합이 k를 넘는다면, 해당 자리수의 값은 i가 된다.

long long factorial(int n){
    long long fact = 1;
    for(int i=2;i<=n;i++){
        fact*=i;
    }
    return fact;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    bool isVisited[25];
    long long cnt = 0;
    
//     방문 배열 초기화
    for(int i=0;i<25;i++){
        isVisited[i] = false;
    }
    
    for(int i=1;i<=n;i++){ // 자릿수
        long long fact = factorial(n-i);
        for(int j=1;j<=n;j++){ // 사람 번호
            if(isVisited[j] == true) continue;
            if(cnt + fact >= k){
                answer.push_back(j);
                isVisited[j] = true;
                
                break; // break가 없으면 자릿수를 추가하고 계속 같은 자릿수에 대해 팩토리얼을 계산하는 문제가 발생한다 (반례: 4, 6, [1, 4, 3, 2])
            }
            else {
                cnt+=fact;
            }
        }
    }
    
    
    
    return answer;
}
