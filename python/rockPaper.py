import random

def game():

    user = input('Enter "r" for rock, "p" for paper and "s" for sciccors: ')
    comp = random.choice(['r', 'p','s'])

    if user == comp:
        print("Once more")
    elif user != comp:
        if comp == 'r' and user == 'p':
            print("Computer won")
        elif comp == 'p' and user == 's':
            print("User won")
        elif comp == 's' and user == 'r':
            print("User won")
        else:
            print("Computer won")

game() 