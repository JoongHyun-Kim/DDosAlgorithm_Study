#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K, W[105], V[105];
  int backpack[101][100001]; // N번째 물건까지 고려하고, 가방 무게가 K일 때의 총 가치

  // 입력 받기
  cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

  for(int i=1;i<=N;i++){
    for(int j=1;j<=K;j++){
      // i번째 물건의 무게가 가방 무게 j보다 크다면 
      // 물건 추가 없이 이전 결과 유지
      if(W[i] > j){
        backpack[i][j] = backpack[i-1][j];
      }
      // i번째 물건이 가방에 들어갈 수 있다면
      // 기존 가방 유지하거나
      // i번째 물건 + i번째 물건 무게 만큼 뺀 가방
      else {
        backpack[i][j] = max(backpack[i-1][j], backpack[i-1][j-W[i]]+V[i]);
      }
    }
  }
	cout << backpack[N][K]; 
}

// [NOTE] DP를 쓸 땐 최종 결과 출력이 배열의 가장 좌측 아래가 될 수 있도록 전략을 짜보자
