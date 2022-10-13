'''This code creates a pattern such that based on the number of levels it will create a right-pyramid'''
'''eg. consider number of levels as 5, therefore the right pyramid will be:
   1
   2 3
   4 5 6
   7 8 9 10
   11 12 13 14 15
'''
'''Try out yourself'''
i=j=1
n=int(input("Enter no. of levels"))
while(i<=n*(n+1)//2):
    print(i,end=" ")
    if i==(j*(j+1)//2):
        print("\r")
        j+=1
    i+=1
lst = list(map(int, input().split()))
ans = 0
length = len(lst)
for i in range(len(lst)):
    ans += ((((i + 1) * (length - i) + 1) // 2) * lst[i])
print(ans)
"""Code provided by Akshaj Vishwanathan"""
