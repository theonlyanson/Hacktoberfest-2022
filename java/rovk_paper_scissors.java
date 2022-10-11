import random

comp_wins=0
player_wins=0

def chooseOption():
    user_choice=input("Choose Rock, Paper or Scissor: ")
    if user_choice in ["Rock","rock","r","R"]:
        user_choice="r"
    elif user_choice in ["Paper","paper","p","P"]:
        user_choice="p"
    elif user_choice in ["Scissor","scissor","s","S"]:
        user_choice="s"
    else:
        print("I don't understand, try again")
    return user_choice

def CompOption():
    comp_choice=random.randint(1,3)
    if comp_choice == 1:
        comp_choice="r"
    elif comp_choice==2:
        comp_choice="p"
    else:
        comp_choice="s"
    return comp_choice

while True:
    print("")
    user_choice=chooseOption()
    comp_choice=CompOption()
    print("")

    if user_choice=="r":
        if comp_choice=="r":
            print("Tie!")
        elif comp_choice=="p":
            print("You lose!\nYou=Rock, Computer=Paper")
            comp_wins+=1
        elif comp_choice=="s":
            print("You win!\nYou=Rock, Computer=Scissor")
            player_wins+=1
    elif user_choice=="p":
        if comp_choice=="p":
            print("Tie!")
        elif comp_choice=="r":
            print("You win!\nYou=paper, Computer=Rock")
            player_wins+=1
        elif comp_choice=="s":
            print("You lose!\nYou=Paper, Computer=Scissor")
            comp_wins+=1
    elif user_choice=="s":
        if comp_choice=="s":
            print("Tie!")
        elif comp_choice=="p":
            print("You win!\nYou=Scissor, Computer=Paper")
            player_wins+=1
        elif comp_choice=="r":
            print("You lose!\nYou=Scissor, Computer=Rock")
            comp_wins+=1
    print("")
    print("Player wins: "+str(player_wins))
    print("Computer wins: "+str(comp_wins))
    print("")

    user_choice=input("Do you want to play again? (y/n) ")
    if user_choice in ["y","Y","yes","Yes"]:
        pass
    elif user_choice in ["n","N","no","No"]:
        break
    else:
        break


    
