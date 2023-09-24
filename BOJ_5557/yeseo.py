import sys
input = sys.stdin.readline

N = int(input())
num = list(map(int, input().split()))
num.reverse()
dp = [[0 for _ in range(20+1)] for _ in range(2)]
dp[0][num[0]]= 1

for i in range(1, N-1):
    dp[i%2] = [0 for _ in range(20+1)] # 현재 만들어 줄 dp를 초기화
    for j in range(20+1):
        if dp[(i+1)%2][j] != 0:
            # print(j+num[i], j-num[i])
            if 0 <= j + num[i] <= 20: dp[i%2][j+num[i]] += dp[(i+1)%2][j]
            if 0 <= j - num[i] <= 20: dp[i%2][j-num[i]] += dp[(i+1)%2][j]

print(dp[N%2][num[-1]])