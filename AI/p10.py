import wikipedi
while 1:
    q=input("Ask me anything(or type 'exit'):")
    if q.lower()=='exit':
        print("Thank you!")
        break
    try:
        print("Answer:",wikipedia.summary(q,sentences=2))
    except:
        print("Information not found")