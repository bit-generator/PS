T = int(input())
for i in range(0, T):
    N = int(input())
    schools = {}
    
    for j in range(0, N):
        str, n = input().split()
        n = int(n)
        schools[n] = str
    
    sortSch = sorted(schools.items(), reverse=True)
    print(sortSch[0][1])
        
        
        