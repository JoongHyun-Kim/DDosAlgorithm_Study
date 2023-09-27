import sys
input = sys.stdin.readline

from collections import deque

max_route = 10**8
N, K = map(int, input().split())
time = [max_route for _ in range(max(N, K) * 2 + 1)] # 최소 시간 저장
visit = [0 for _ in range(max(N, K) * 2 + 1)]
time[N] = 0
ans, min_time = 0, max_route # 찾는 방법의 수를 리스트에 저장하는 게 아니라 ans에 도달하면 추가

q = deque([[N, 1]])
if N == K: q, ans = [], 1

while (q):
    curr, count = q.popleft() # 현재 위치, 현재 걸린 시간
    walk = [curr + 1, curr - 1, curr * 2]

    # if visit[curr]: continue
    for w in walk:
        if w > max(N, K)*2 or w < 0: continue
        if time[w] < count: continue # 이미 최소 시간보다 크면 더 판정해 줄 이유 X
        else: time[w] = count
        if w == K: 
            if min_time != count: ans = 0
            min_time = count
            ans += 1
            continue
        if not visit[w]: q.append([w, count+1])
    visit[curr] = 1

# print(time)
print(time[K])
print(ans)