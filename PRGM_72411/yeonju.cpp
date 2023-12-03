// 코스 요리: 
// - 가장 많이 함께 주문한 단품 메뉴, 
// - 2가지 이상의 단품 메뉴, 
// - 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합

// 나온 문자를 가지고 가능한 모든 조합을 저장한다. 
// 해당 조합이 각 주문에 있는지 그 개수를 헤아린다. // 이게 2개 이상이어야 추가할 수 있다.

// 모두 추가한 뒤에는 사전순으로 저장한다.

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> combination;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

// 각 order에 대해 조합의 수가 len인 단품메뉴 조합의 주문 개수 카운트
void dfs(string order, int len, string tmp, int idx) {
    if (tmp.length() == len) {
        combination[tmp]++; // 해당 조합의 주문 수++
        return;
    }
    
    for (int i=idx; i<order.length(); i++) {
        dfs(order, len, tmp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<course.size();i++){
        for(int j=0;j<orders.size();j++){
            sort(orders[j].begin(), orders[j].end());
            dfs(orders[j], course[i], "", 0);
        }
        
        int maxCnt = 0;
        for(auto iter : combination) {
            maxCnt = max(maxCnt, iter.second);
        }
        
        for(auto iter: combination){
            if(maxCnt < 2) break;
            else if(combination[iter.first] == maxCnt){
                answer.push_back(iter.first);
            } 
        }
        combination.clear(); // 다음 단품 메뉴 개수의 연산을 위해 초기화
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
