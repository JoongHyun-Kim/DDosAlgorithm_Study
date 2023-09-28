#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> answer;
int numList[6] = {1,2,3,5,7,9};

bool checkPrimeNumber(int num){
  bool answer = true;
  if(num == 0 || num == 1) return false;
  if(num == 2 ) return true;
  
  for(int i=2;i<num;i++){
      if(num%i == 0){
        answer = false;
        break;
      }
  }
  return answer;
}

void findWonderfulPrime(int num, int depth){

  // 소수 여부를 확인한다
  bool isPrimeNumber = checkPrimeNumber(num);

  // num이 소수가 아니라면
  // 그대로 return해서 종료
  if(isPrimeNumber == false){
    return;
  }
  
  // 원하는 길이가 됐으면 답에 추가
  if(depth == N-1){
    answer.push_back(num);
    return;
  }
  
  // num이 소수라면 
  // 새로운 수를 뒤에 붙여서 함수 호출
  for(int i=0;i<6;i++){
    findWonderfulPrime(num*10 + numList[i], depth+1);
  }  
  
}

int main(){
  // 1. 입력 받기
  cin >> N;

  // 2. 가능성 있는 숫자로 소수 탐색
  for(int i=0;i<6;i++){
    findWonderfulPrime(numList[i], 0);
  }

  // 3. 결과 출력
  sort(answer.begin(), answer.end());
  for(int i=0;i<answer.size();i++){
    cout << answer.at(i)<<'\n';
  }
  
}

// [NOTE] 1MB 당 저장할 수 있는 int 개수는 262,144 개.
// 그래서 DP처럼 소수 여부를 저장해두고 빨리 판단하려다 메모리 초과가 자주 났다.

// [NOTE] 소수 판단 알고리즘으로 효과적인 건 "에라토스테네스의 체 알고리즘"
// 소수의 배수들을 제해 가는 방법

// 사실 이 문제는 정렬을 안해도 오름차순으로 출력된다
