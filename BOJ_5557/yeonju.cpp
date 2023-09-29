#include <iostream>
#include <vector>
using namespace std;

int N, total;
vector<int> number;
long answer[105][25]; // 행 번째 수까지 고려했을 때 합이 열이 되는 경우의 수

void makeEquation(){
  // 첫번째 수는 무조건 양수
  answer[0][number.at(0)] = 1;

  // 모든 합의 경우의 수를 저장
  for(int i=1;i<number.size();i++){
    int curNum = number.at(i);
    // 모든 합의 경우의 수를 확인하면서 // 최대 20 이라 가능
    for(int j=0;j<=20;j++){
      // 뺀 값이 0 이상이거나 더한 값이 20 이하이면
      // **해당 값이 될 수 있는 경우의 수를 추가한다**
      if(j - curNum >= 0) answer[i][j-curNum] += answer[i-1][j];
      if(j + curNum <= 20) answer[i][j+curNum] += answer[i-1][j];
    }
  }
}

int main(){
  cin >> N;
  for(int i=0;i<N-1;i++){
    int n;
    cin >> n;
    number.push_back(n);
  }
  cin >> total;

  makeEquation();

  // 모든 숫자를 고려했을 때 합이 total인 경우의 수만 출력한다
  cout << answer[N-2][total];
}

// [NOTE] DP 배열을 만들 땐 
// 범위가 한정적으로 주어진 숫자를 눈 여겨보고 활용도를 따져보자

// [NOTE] 만들 수 있는 등식의 개수가 2^63-1 이하란 점에서 
// 함수를 호출하면 시간 초과가 나는 건 당연할지도 모른다...
