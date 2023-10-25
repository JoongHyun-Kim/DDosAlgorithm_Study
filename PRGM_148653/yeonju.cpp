#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
// 현재 자릿수를 최소 횟수로 0으로 만들기
    while (storey > 0){
        int cur = storey % 10;
        int next = (storey / 10) % 10;

//         현재 자릿수가 5 보다 크다면
        if (cur > 5){
            answer += 10 - cur; // 10에서 빼서 구하는 게 더 효율적
            storey += 10;
        }
//         현재 자릿수가 5라면
        else if (cur == 5){
            answer += 5;
//             그 앞 자리 수가 5 이상이면 올리는 게 최소 횟수로 작용
            storey += next >= 5 ? 10 : 0;
        }
//         현재 자릿수가 5 미만이라면
        else{
            answer += cur; // 그대로 1층 씩 더해서 구하는 것이 최소
        }

//         다음 층으로 이동
        storey /= 10;
    }

    return answer;
}
