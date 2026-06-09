cost=[
    [0,10,15,20],
    [10,0,35,25],
    [15,35,0,30],
    [20,25,30,0]
]
n=len(cost)
visited=[False]*n
path=[0]
visited[0]=True
current=0
total=0
for i in range(n-1):
    min_cost=9999
    nearest=-1
    for city in range(n):
        if visited[city]==False and cost[current][city]<min_cost:
            min_cost=cost[current][city]
            nearest=city
    path.append(nearest)
    visited[nearest]=True
    total +=min_cost
    current=nearest
path.append(0)
total+=cost[current][0]
print("Nearest Neighbor TSP Tour:",path)
print("Total Distances:",total)