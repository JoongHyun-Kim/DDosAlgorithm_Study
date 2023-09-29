// 1. X-1
// 2. X+1
// 3. 2*X
// 위 세 가지 방법으로 N에서 K까지 갈 수 있는 최단 시간과 방법의 개수를 계산하자

#include <iostream>
#include <queue>
using namespace std;

int N, K;
int answerTime = 0, answerWay =0;
int visited[100005];

void findSister(int location) {
  queue<pair<int, int>> q;
  q.push({location, 0});

  while (!q.empty()) {
    int curLocation = q.front().first;
    int curTime = q.front().second;
    visited[curLocation] = 1;
    visited[K] = 0;
    q.pop();

    if(answerTime == 0 && curLocation == K){
      answerTime = curTime;
      answerWay++;
      continue;
    }

    if(answerTime !=0 && curLocation == K && answerTime == curTime){
      answerWay++;
      continue;
    }
    
    if(0 <= curLocation-1 && visited[curLocation-1] == 0){
      q.push({curLocation-1,curTime+1});
    }
    if(curLocation+1 <= K && visited[curLocation+1] == 0){
      q.push({curLocation+1,curTime+1});
    }
    if(2*curLocation <= K+1 && visited[2*curLocation] == 0){
      q.push({curLocation*2,curTime+1});
    }
    
  }
}

int main() {
  // 입력받기
  cin >> N >> K;
  
  findSister(N);
  
  cout << answerTime << '\n' << answerWay;
}

// [NOTE] BFS는 너비탐색 -> 최단 위치에서 갈 수 있는 범위 탐색

// [GOOD] 처음부터 위치가 같은 경우 고려 했다!
// [NOTE] 백트래킹으로 했더니 메모리초과
// [NOTE] N > K인 경우를 고려하지 못해서 틀렸다.
