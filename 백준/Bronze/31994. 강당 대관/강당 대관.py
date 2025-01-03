maxN = 0
maxStr = ""

for i in range(7):
    str, n = input().split()
    if maxN < int(n):
        maxStr = str
        maxN = int(n)

print(maxStr)