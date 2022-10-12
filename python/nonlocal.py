a=12
def h():
    b=403
    def k():
        nonlocal b
        b=405
        print(b)
    print(b)
    b=420
    print(b)
    k()
    print(b)
h()
print(a)
