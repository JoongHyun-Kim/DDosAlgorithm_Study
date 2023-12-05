// 보조 컨베이어 벨트는 stack이다.
// 현재 상자의 번호와 order[i] 혹은 stack.top()과 일치하는지 확인한다
// 일치한다면 집어넣는다.
// 일치하지 않는다면, 현재 필요한 상자의 번호가 order[i]와 다르고, stack.top()보다 숫자가 작다면 정지하고,
// stack.top()보다 숫자가 크거나 stack이 비었다면 우선 stack에 넣어둔다.

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int orderIdx= 0;
    int cur = 1;
    
    while(1){
        if(orderIdx >= order.size()) break;
        if(cur == order[orderIdx]){
            answer++;
            orderIdx++;
            cur++;
        }
        else if(!s.empty() && s.top() == order[orderIdx]){
            s.pop();
            answer++;
            orderIdx++;
        }
        else {
            if(s.empty() || (!s.empty() && order[orderIdx] > s.top()) ){
                s.push(cur);
                cur++;
            }
            else if(order[orderIdx] < s.top()){
                break;
            }
        }
    }
    
    return answer;
}
