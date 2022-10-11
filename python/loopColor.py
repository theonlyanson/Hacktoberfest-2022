import random
colors=["blue","green","yellow","pink","red","black"]

while True:
      color=colors[random.randint(0,len(colors)-1)]
      guess=input("Im thinking abt a clr, can you guess it?")
      
      while True:
           if(color==guess):
           	break
           else:
               guess=input("nope,try again: ")
      print("thats right")
      
      playagain=input("lets play again,,,type no to quit: ")
      if playagain.lower()=="no":
         break
         
print("thanks for playing")
