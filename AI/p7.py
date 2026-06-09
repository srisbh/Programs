facts={"hair","live young","feathers","fly"}
rules=[
    ("hair","mammal"),
    ("live young","mammal"),
    ("feathers","bird"),
    ("fly","bird")
]
changed=True
while changed:
    changed=False
    for p,q in rules:
        if p in facts and q not in facts:
            facts.add(q)
            changed=True
if "mammal" in facts:
    print("The cat is classified as a mammal")
else:
    print("The cat is not classified as a mammal")
if "bird" in facts:
    print("The piegon is classified as bird")
else:
    print("The piegon is classified as bird")