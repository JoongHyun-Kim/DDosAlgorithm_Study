#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int Anum;
int Bnum;
int Cnum;
char arr[50];
// idx 수 a 수 b 수 c 수
//  prev와 pprev은 1=A, 2=B, 3=C 
int cache[50][50][50][50][4][4];

// idx: 문자 입력할 위치
// a,b,c : A,B,C 별 가용 수
// prev: 전 알파벳
// pprev: 전전 알파벳
bool findLog(int idx, int a, int b, int c, char prev, char pprev) {
  // 모두 다 사용한 경우
  if (a == 0 && b == 0 && c == 0) {
    return true;
  }
  // 해당 조합이 불가능할 경우
  if (cache[idx][a][b][c][prev % 4][pprev % 4])
    return false;


  cache[idx][a][b][c][prev % 4][pprev % 4] = 1;

  if (a > 0) {
    arr[idx] = 'A';
    if (findLog(idx + 1, a - 1, b, c, 'A', prev))
      return true;
  }

  if (b > 0 && prev != 'B') {
    arr[idx] = 'B';
    if (findLog(idx + 1, a, b - 1, c, 'B', prev))
      return true;
  }
  if (c > 0 && prev != 'C' && pprev != 'C') {
    arr[idx] = 'C';
    if (findLog(idx + 1, a, b, c - 1, 'C', prev))
      return true;
  }
  return false;
}

int main() {

  string S;
  cin >> S;

  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'A')
      Anum++;
    else if (S[i] == 'B')
      Bnum++;
    else if (S[i] == 'C')
      Cnum++;
  }

  if (findLog(0, Anum, Bnum, Cnum, ' ', ' ')) {
    for (int i = 0; i < S.size(); ++i)
      cout << arr[i];
  } else
    cout << -1 << "\n";

  return 0;
}
