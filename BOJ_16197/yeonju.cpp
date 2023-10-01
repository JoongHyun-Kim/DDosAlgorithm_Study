// 위치 이동 선택 방법 
// - 10번 이하로 움직일 수 있다.
// - 상하좌우로 움직일 수 있다.
// - 나란히 있다면 떨어지는 방향(수직 이동)으로는 움직이지 않는다.
    // - 떨어지지 않는 방향으로 움직이거나 
    // - 나란한 방향으로만 움직인다.

    // 단순 BFS 호출하면 4^10 = 2^20 = 2^10^2 = 1024^2 = 1000000 번 함수 호출

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using pii = pair<int,int> ;
int N, M, answer=11;
string board[20];
int visited[20][20][20][20];
vector<pii> btn;
int dirR[4] = {1,-1,0,0}, dirC[4] = {0,0,-1,1};

struct Coin {
int r1,c1,r2,c2;
int cnt;
};

bool isBtnFall(pii btn){
  if(btn.first < 0 || btn.first >= N || btn.second < 0 || btn.second >=M){
    return true;
  }
  return false;
}

int moveBtn(pii btn1, pii btn2){
  queue<Coin> q;
  q.push({btn1.first,btn1.second, btn2.first,btn2.second,0});

  while(!q.empty()){
    Coin cur = q.front();
    q.pop();
    visited[cur.r1][cur.c1][cur.r2][cur.c2] = 1;

    for(int i=0;i<4;i++){
      int nextBtn1R = cur.r1 + dirR[i];
      int nextBtn1C = cur.c1 + dirC[i];
      int nextBtn2R = cur.r2 + dirR[i];
      int nextBtn2C = cur.c2 + dirC[i];
      int nextCnt = cur.cnt+1;

      if(nextCnt > 11) return -1;

      bool isBtn1Fall = isBtnFall({nextBtn1R,nextBtn1C});
      bool isBtn2Fall = isBtnFall({nextBtn2R,nextBtn2C});

      // 둘 다 떨어진다면 종료
      if(isBtn1Fall&&isBtn2Fall) continue;

      // 한 쪽만 떨어뜨리는 데에 성공한 경우
      else if((isBtn1Fall&&!isBtn2Fall) || (!isBtn1Fall&&isBtn2Fall)){
        return nextCnt;
      }
      else{
        // 벽에 막혀서 못가는 경우
        if(board[nextBtn1R][nextBtn1C] == '#'){
          nextBtn1R = cur.r1;
          nextBtn1C = cur.c1;
        }
        if(board[nextBtn2R][nextBtn2C] == '#'){
          nextBtn2R = cur.r2;
          nextBtn2C = cur.c2;
        }
        // 둘 중 하나라도 이동한 적이 없는 위치면 이동한다
        if(!visited[nextBtn1R][nextBtn1C][nextBtn2R][nextBtn2C]){
          q.push({nextBtn1R, nextBtn1C, nextBtn2R, nextBtn2C, nextCnt});    
        }
      }
    }
    
  }
  return -1;
}

int main(){
    // 입력 받기
    cin >> N >> M;
    for(int i=0;i<N;i++){
      cin >> board[i];
        for(int j=0;j<M;j++){
            
            if(board[i][j] == 'o'){
                btn.push_back({i,j});
            }
        }
    }


  answer = moveBtn(btn.at(0),btn.at(1));
  if(answer == 11) cout << -1;
  else cout << answer;
}

// [NOTE] 큐 안에 한 묶음으로 저장해야할 정보가 많을 때는 '구조체'를 활용하면 좋다!
// [NOTE] 처음에 BFS로 알고리즘 선택 잘했다!
// [NOTE] 변수명이 비슷할 땐 헷갈리지 않도록 주의하자ㅜㅜ

// [POINT] 위치별 cnt(이동횟수)를 개별로 관리해줘야했다
// [POINT] 방문 배열을 한꺼번에 관리해줘야했다
