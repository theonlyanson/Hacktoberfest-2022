Name = "Indian Institute Technology"
AStart = Name.split()
AFinal = ''

for string in AStart:
    if string[0].isupper():
        AFinal += string[0] + '.'
print(AFinal)