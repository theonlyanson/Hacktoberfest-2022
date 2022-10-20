a = ['python','programming','is','easy']
b = {}
c = []
for i in a:
    if i[0] in b:
        b[i[0]]+=[i]
    else:
        b[i[0]] = [i,]
print(b)
