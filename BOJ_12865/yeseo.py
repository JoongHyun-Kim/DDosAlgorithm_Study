import sys
input = sys.stdin.readline

# 2차원 배열로 풀어 주어야 하는 이유 - 한 아이템은 하나밖에 없으므로 중복으로 들어가면 안 됨
# 처음에는 V가 가장 큰 것만 넣어 주자고 생각했는데 그러면 안 됨 그 이유는 위와 마찬가지
N, K = map(int, input().split())
items = [[0, 0]] # dp의 첫 열, 첫 행을 0으로 초기화시키기 위해 일부러 0 투입
for _ in range(N):
    W, V = map(int, input().split())
    items.append([W, V])

# dp는 2차원 배열, x축이 W이고 y축이 item index
# 아래로 갈수록 최댓값만 저장하므로 최댓값을 판정하기 위해서는 그냥 바로 직전 index의 weight만 보아도 됨
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1, N+1):
    # item index
    for j in range(1, K+1):
        # current max weight
        # i번째 이하의 items만 존재한다고 생각
        if items[i][0] > j: dp[i][j] = dp[i-1][j]
        else:
        # if items[i][0] <= j and K:
            # value: items[i][1]
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i][0]] + items[i][1], dp[i][j-1])

# print(dp)
print(dp[-1][-1])