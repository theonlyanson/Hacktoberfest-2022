a = ['string','hello','haii','python']
c = {}
for i in a:
    h = 0
    for j in i:
        if j in 'AEIOUaeiou':
            h+=1
    c[i] = h
print(c)
