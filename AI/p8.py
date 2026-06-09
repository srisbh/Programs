clause1={"A","B"}
clause2={"~A"}
resolved=clause1.union(clause2)
for x in list(clause1):
    if "~"+x in clause2:
        resolved.remove(x)
        resolved.remove("~"+x)
if resolved:
    print("Query can be proved using resolution")
    print("Resolved clause:",resolved)
else:
    print("Query cannot be proved")