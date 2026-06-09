def dfs(c,v,j1,j2,t):
    if t in c:
        print("Jug",1 if c[0]==t else 2,"now has",t,"litres.")
        return 1
    v.add(c)
    a,b=c
    ops=[
        ("Fill Jug 1",(j1,b)),
        ("Fill Jug 2",(a,j2)),
        ("Empty Jug 1",(0,b)),
        ("Empty Jug 2",(a,0)),
        ("Pour Jug 1 to Jug 2",(max(0,a+b-j2),min(j2,a+b))),
        ("Pour Jug 2 to Jug 1",(min(j1,a+b),max(0,a+b-j1)))
    ]
    for x,n in ops:
        if n not in v:
            print("Trying:",x,"=>",n)
            if dfs(n,v,j1,j2,t):
                return 1
j1=int(input("Enter the capacity of jug 1:"))
j2=int(input("Enter the capacity of jug 2:"))
t=int(input("Enter Target Volume:"))
print("Solving Water Jug Problem with capacities",(j1,j2),"to measure",t,"liters.")
print("Solution found!" if dfs((0,0),set(),j1,j2,t) else "Solution not found.")

    