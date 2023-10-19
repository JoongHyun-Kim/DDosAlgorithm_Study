#include <string>
#include <vector>
#include <stack>

using namespace std;

// 2중 for문은 시간초과 발생
// 뒤에서부터 살피자
// 가장 맨 뒤는 그냥 -1을 집어넣는다
// 비교 대상 값

// (반복문 전)-1 push, 비교대상 = 2
// 현재(6)와 바로 뒤 비교. -1 push, 비교대상 = 6
//     현재가 비교대상보다 더 크다면 비교대상 = 현재
// 현재(3)과 바로 뒤 비교. 
// [ 반례 ]
// 9 1 0 5 6
// -1 5 5 6 -1

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> nums;
    
    for(int i=numbers.size()-1;i>=0;i--){
        int cur = numbers[i];
        while(!nums.empty()){
            int top = nums.top();
            if(cur < top){
                // answer.insert(answer.begin(), top);
                answer[i] = top;
                nums.push(cur);
                break;
            }
            nums.pop();
        }
        if(nums.empty()){
            // answer.insert(answer.begin(), -1);
            answer[i] = -1;
            nums.push(cur);
        }
    }
    
    return answer;
}

// [NOTE] 가장 가까이에 있는 큰 수 -> Stack
// [POINT] insert 함수 때문에 시간초과가 발생했다.
// 웬만하면 insert같은 함수 말고 배열로서의 접근/malloc/new를 활용하자...
// (malloc, new)https://seulgit.tistory.com/81
