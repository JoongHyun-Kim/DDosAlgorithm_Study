// 노드로 들어오는 노드가 없을 경우 Strahler는 1

// 1. 우선 그래프 연결을 입력 받는다.
// Graph[B] = A ; A에서 B로 물이 흐른다 ; B로 A가 흘러들어온다
// *Strahler 수는 별개의 배열에 따로 저장하자
// 2. 1번 노드부터 차례대로 순회하면서
// 2-1. 연결된 게 없으면 Strahler를 1로 저장하고 다음 노드로 넘어간다
// 2-2. 연결된 게 있으면 그걸로 dfs를 호출한다
// 2-2-a. Strahler 배열에 저장된 게 있으면 그걸 리턴한다
// 2-2-b. 없으면 dfs를 호출한다

#include <iostream>
#include <vector>
using namespace std;

int T, K, M, P;
vector<int> graph[1005];
int strahler[1005];

void initiateGraph(){
  for(int i=0;i<1005;i++){
    graph[i].clear();
  }
}

void initiateStrahler(){
  for(int i=0;i<1005;i++){
    strahler[i] =0;
  }
}

int findStrahler(int num){
  if(strahler[num] != 0){
    return strahler[num];
  }
  if(graph[num].size() == 0){
    return 1;
  }

  int max=0;
  int maxCnt = 0;
  for(int i=0;i<graph[num].size();i++){
    int temp = findStrahler(graph[num].at(i));
    if(temp > max){
      max = temp;
      maxCnt = 1;
    }
    else if(temp == max){
      maxCnt++;
    }
  }
  
  return maxCnt==1 ? max : max+1;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> T;
  for(int i=0;i<T;i++){
    cin >> K >> M >> P;
    // 테스트 케이스 번호 출력
    cout << K<<' ';

    // 그래프와 Strahler 배열 초기화
    initiateGraph();
    initiateStrahler();

    for(int j=0;j<P;j++){
      int A, B;
      cin >> A >> B;
      graph[B].push_back(A);
    }

    for(int j=1;j<=M;j++){
      strahler[j] = findStrahler(j);
    }
    cout << strahler[M]<<'\n';
  }
  
}
