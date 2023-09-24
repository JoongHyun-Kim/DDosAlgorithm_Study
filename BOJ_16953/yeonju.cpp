#include <iostream>
using namespace std;

int A,B,answer = 0;

// 1. B가 짝수면 2로 나눈다
// 2. 끝자리가 1로 끝나면 끝의 1자리를 뗸다
// 3. 더이상 할 수 있는 게 없으면 -1을 출력한다

int modifyAToB (int num){
    if(num == A){
        return answer+1;
    }
    else if( num < A ){
        return -1;
    }
    if(num %2 == 0){
        answer++;
        return modifyAToB(num/2);
    }
    if(num%10 == 1){
        answer++;
        return modifyAToB(num/10);
    }
    return -1;
}

int main() {
    cin >> A >> B;
    
    cout << modifyAToB(B);

}

// https://velog.io/@kados22/C-BOJ-16953-A-B
