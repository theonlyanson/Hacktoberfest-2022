def passgen(passlen):
    import random
    a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#)$%^&*("
    p = "".join(random.sample(a,passlen))
    print(p)


passgen(input("Enter the number of characters u need in your password"))