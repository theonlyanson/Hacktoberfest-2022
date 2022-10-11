import random


def guess(x):
    randomNum = random.randint(1, x)

    guess = 0
    while guess != randomNum:
        guess = int(input(f"Guess a number btw 1 and {x}: "))
        if guess > randomNum:
            print("Guessed number is too large")
        elif guess < randomNum:
            print("Guessed number is too small")
    print("righttt. you guessed ",randomNum)


guess(10)
