a, b, c = map(int, input().split())

if a > b:
    a, b = b, a

if b > c:
    b, c = c, b

if a > b:
    a, b = b, a
    
s = input()
for i in s:
    if i == "A":
        print(a, end=' ')
    elif i == "B":
        print(b, end=' ')
    else:
        print(c, end=' ')