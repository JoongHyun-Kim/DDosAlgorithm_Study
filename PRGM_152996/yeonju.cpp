#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
set<int> st;
map<int, long long> mp;
int visited[1010][1010];

long long solution(vector<int> weights) {
    memset(visited, false, sizeof(visited));
    long long answer = 0;
    for (int weight : weights) {
        mp[weight]++; // 각 몸무게 별 인원수 저장
        st.insert(weight); // 무게를 오름차순으로 정렬해서 저장
    }
    for (auto w : st) { // w: 현재 몸무게
//         몸무게가 똑같은 사람들끼리의 경우의 수(Combination)
        answer += (mp[w] * (mp[w]-1)) / 2;
        for (int i=2; i<=4; i++) {
            for (int j=2; j<=4; j++) {
//                 몸무게가 똑같은 경우는 이미 고려했으므로 패스
                if (i == j) continue;
//                 반대편에 앉을 수 있는 몸무게가 존재하지 않는 경우
//                 나누어 떨어지지 않으므로 1:2, 2:3, 3:4와 같은 비율로 앉을 수 없음
                if ((w * i) % j) continue;
                
//                 존재하는 몸무게면서 이전에는 고려해주지 않는 몸무게 쌍
                if (mp[w*i/j] != 0 && !visited[w*i/j][w]) {
                    visited[w*i/j][w] = 1;
                    visited[w][w*i/j] = 1;
//                     경우의 수(Permutation)
                    answer += mp[w] * mp[w*i/j];
                }
            }
        }
    }
    return answer;
}

// https://jojaeng2.tistory.com/62
// 벡터 중복 제거 https://kkaeruk.tistory.com/19
// Set https://hwan-shell.tistory.com/130
