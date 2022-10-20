try:
    a = 10
    b= int(input())
    print(a%b)
except ZeroDivisionError:
    print('zero error handled')
except:
    print('Exception Handled')
