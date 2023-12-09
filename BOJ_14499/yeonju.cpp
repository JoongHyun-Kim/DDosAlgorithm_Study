// 주사위의 위치를 어떻게 표현하면 좋을까?
// 이중배열의 벡터_'현'동서남북'위' 순으로 저장을 해보자
// 위에 해당하는 숫자는 이동하는 방향의 반대(북이면 남, 동이면 서)에 있는 수가 된다.

// 명령의 방향에 따라 이동을 시킨다
// 이동 마다 이중배열에 저장된 상태값과 지도의 내용을 업데이트 한다.



#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int graph[25][25];
int dice[25][25][10]; // 동서남북위현
vector<int> order;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 입력 받기
  cin >> N >> M >> x >> y>> K;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> graph[i][j];
    }
  }
  for(int i=0;i<K;i++){
    int o;
    cin >> o;
    order.push_back(o);
  }

  // 주사위 배열 0으로 초기화 하기
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      for(int k =0;k<7;k++){
        dice[i][j][k] = 0;
      }
    }
  }

  // 명령에 따르기
  int dirR[4]={0,0,-1,1}; // 동서남북
  int dirC[4]={1,-1,0,0};
  int curR = x, curC = y;
  for(int i=0;i<K;i++){
    int dir = order[i]-1;
    int nextR = curR + dirR[dir];
    int nextC = curC + dirC[dir];

    // 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
    if(nextR < 0 || nextC < 0 || nextR >= N || nextC >= M)
      continue;

    // 주사위 굴리기 // 0동 1서 2남 3북 4현 5위
    // dice 위치: (굴려온 방향) 결과
    // 동: (남,북) 그대로 (동) 이동 전 위 (서) 이동 전 현재 위치
    // 서: (남,북) 그대로 (동) 이동 전 현재 위치 (서) 이동 전 위
    // 남: (남) 이동 전 위 (북) 이동 전 현재 위치 (동,서) 그대로
    // 북: (남) 이동 전 현재 위치 (북) 이동 전 위 (동,서) 그대로
    // 위: 굴리기 전 현재 위치에서 굴린 방향 반대 쪽에 있는 위치
      // 0 <-> 1, 2 <-> 3
    if(dir == 0){ // 동
      dice[nextR][nextC][0] = dice[curR][curC][5];
      dice[nextR][nextC][1] = dice[curR][curC][4];
      dice[nextR][nextC][2] = dice[curR][curC][2];
      dice[nextR][nextC][3] = dice[curR][curC][3];
      dice[nextR][nextC][5] = dice[curR][curC][1];
    }
    else if(dir == 1){ // 서
      dice[nextR][nextC][0] = dice[curR][curC][4];
      dice[nextR][nextC][1] = dice[curR][curC][5];
      dice[nextR][nextC][2] = dice[curR][curC][2];
      dice[nextR][nextC][3] = dice[curR][curC][3];
      dice[nextR][nextC][5] = dice[curR][curC][0];
    } 
    else if(dir == 2){ // 남
      dice[nextR][nextC][0] = dice[curR][curC][0];
      dice[nextR][nextC][1] = dice[curR][curC][1];
      dice[nextR][nextC][2] = dice[curR][curC][5];
      dice[nextR][nextC][3] = dice[curR][curC][4];
      dice[nextR][nextC][5] = dice[curR][curC][3];
    }
    else if(dir == 3){ // 북
      dice[nextR][nextC][0] = dice[curR][curC][0];
      dice[nextR][nextC][1] = dice[curR][curC][1];
      dice[nextR][nextC][2] = dice[curR][curC][4];
      dice[nextR][nextC][3] = dice[curR][curC][5];
      dice[nextR][nextC][5] = dice[curR][curC][2];

    }
    // 현: 굴리기 전 현재 위치에서 굴린 방향 쪽에 있는 위치
    dice[nextR][nextC][4] = dice[curR][curC][dir];

    // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
    if(graph[nextR][nextC] == 0){
      graph[nextR][nextC] = dice[nextR][nextC][4];
    }
    else {
      dice[nextR][nextC][4] = graph[nextR][nextC];
      graph[nextR][nextC] = 0;
    }
    cout << dice[nextR][nextC][5]<< '\n';

    curC = nextC;
    curR = nextR;
  }
}
