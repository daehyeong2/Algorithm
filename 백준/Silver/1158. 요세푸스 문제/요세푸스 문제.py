from collections import deque

n, m = map(int, input().split())
que = deque()
for i in range(1, n+1): que.append(i)

ret = []
while len(que) != 0:
    que.rotate(-(m-1))
    ret.append(str(que.popleft()))

print("<", ", ".join(ret), ">", sep="")