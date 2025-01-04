N, M = map(int, input().split())
l = [0] * N

for i in range(M):
    a, b, c = map(int, input().split())
    
    for j in range(a, b + 1):
        l[j - 1] = c

print(' '.join(map(str, l)))