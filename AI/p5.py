def safe(b,r,c):
    for i in range(r):
        if b[i][c]:
            return 0
    i,j=r,c
    while i>=0 and j>=0:
        if b[i][j]:
            return 0
        i-=1
        j-=1
    i,j=r,c
    while i>=0 and j<8:
        if b[i][j]:
            return 0
        i-=1
        j+=1
    return 1
def queen(b,r):
    if r==8:
        return 1
    for c in range(8):
        if safe(b,r,c):
            b[r][c]=1
            if queen(b,r+1):
                return 1
            b[r][c]=0
b=[[0]*8 for i in range(8)]
if queen(b,0):
    print("Solution found:")
    for i in b:
        print(*i)
else:
    print("No solution exists.")