#include <iostream>
#include <queue>
#include <utility>
using namespace std;
char field[12][6];
int visited[12][6];
int answer = 0;
int dirCol[4]={0,0,-1,1}, dirRow[4]={1,-1,0,0};

  // 연쇄 조건: 뿌요가 4개가 모이면 터진다
  // 동시에 터진다
  // 동시에 터져도 1연쇄만 추가된다

void initializeIsVisited(){
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      visited[i][j] = 0;
    }
  }
}

void erasePuyo(int connected){
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      if(visited[i][j] != -1) continue;
      visited[i][j] = 1;
      if(connected >= 4){
        field[i][j] = '.';
      }
    }
  }
}

void movePuyo(){
    for(int i=0;i<6;i++){
    int drop = 0;
    for(int j = 11 ; j>=0;j--){
      if(field[j][i] == '.'){
        drop++;
        continue;
      }
      if(drop != 0){
        field[j+drop][i] = field[j][i];
        field[j][i]='.';
      }
    }
  }
}

int connectPuyo(int row, int col){
  int connected = 1;
  visited[row][col] = -1;
  queue<pair<int,int>> q;
  q.push({row,col});

  while(!q.empty()){
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int nextR = curR+dirRow[i];
      int nextC = curC+dirCol[i];

      // ! 꼭 범위 내에 있는지 확인해주기 !
      if(nextR < 0 || nextR >= 12 || nextC < 0 || nextC >=6) continue;
      // 방문하지 않은 뿌요 중에서 같은 색깔의 뿌요를 추가
      if(visited[nextR][nextC] == 0 && field[nextR][nextC] == field[row][col]){
        connected++;
        q.push({nextR,nextC});
        visited[nextR][nextC] = -1;
      }
    }
  }

  // 연결 개수를 확인하고 4개 이상이면 해당 뿌요 뭉치를 표시한다
  erasePuyo(connected);

  if(connected >= 4){
    return connected;
  }
  else{
    return 0;
  }

}

int solution(){
  // 뿌요 연결 확인하기
  int removedPuyo=0;
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      if(field[i][j] == '.') continue;
      if(visited[i][j] == 0){
        removedPuyo += connectPuyo(i,j);
      }
    }
  }

  // 지운 게 있다면 연쇄 횟수 추가
  if(removedPuyo > 0 )answer++;

  // 뿌요 위치 옮기기
  movePuyo();
  
  return removedPuyo;
}

int main(){
  // 1. 입력 받기
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      cin >> field[i][j];
    }
  }

  // 2. 더이상 터지지 않을 때까지 아래 내용을 반복한다
  while(1){
    // 방문 배열 초기화
    initializeIsVisited();
    if(solution() == 0) break;
  }
  cout << answer;
}

// [NOTE] 좌표를 옮길 땐 해당 좌표가 가능한 범위 내에 있는지 꼭 확인하기
// 처음에 틀렸습니다가 나왔다가 이 조건 하나 추가하니 맞았습니다가 나왔다

// [NOTE] 코드 작성 전 알고리즘을 상세하게 써보는 과정 무척 중요
