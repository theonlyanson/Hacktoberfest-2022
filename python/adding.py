n = int(input())
def add1(n):
    a = []
    for i in range(1,n):
        if n%i == 0:
            a+=[i]
    sum1 = 0
    for i in  a:
        sum1+=i
    if sum1 == n:
        print('true')
    else:
        print('false')
add1(n)
