// A의 카드에 적힌 숫자를 모두 나눌 수 있고, B의 카드에 적힌 숫자를 모두 나눌 수 없는 양의 정수
// *카드에는 서로 중복된 원소가 있을 수 있다.

// 양의 정수는 A 카드 중 가장 작은 수보다 작거나 같다.

// 1. A 카드 중 가장 작은 수부터 시작해서 A 전체를 나눠본다.
// 2. A 전체를 나누는 데에 성공한다면, 해당 수로 B의 숫자를 나눠본다.
// 2-1a. B 전체를 나누는 데에 실패한다면, 해당 수를 answer에 넣는다.
// 2-1b. B 전체를 나누는 데에 성공한다면, 1 줄여서 다시 1로 돌아간다.
// 3. A 전체를 나누는 데에 실패한다면, 1 줄여서 1로 돌아간다.

// 이걸 양쪽에 시행해서 max 함수로 최댓값을 찾는다.

#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int findNumber(vector<int> A, vector<int> B){
    int num = INT_MAX;
    for(int i=0;i<A.size();i++){
        num = min(num, A.at(i));
    }
    
    num++;
    while(num > 1){
        num--;
        bool isAllDivided = true;
        for(int i=0;i<A.size();i++){
            if(A.at(i)%num != 0){
                isAllDivided = false;
                break;
            }
        }
        if(isAllDivided == false) continue;
        
        bool isDivided = false;
        for(int i=0;i<B.size();i++){
            if(B.at(i)%num == 0){
                isDivided = true;
                break;
            }
        }
        if(isDivided == true) continue;
        return num;
    }
    return -1;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    answer = max(answer, findNumber(arrayA, arrayB));
    answer = max(answer, findNumber(arrayB, arrayA));
    
    return answer;
}
