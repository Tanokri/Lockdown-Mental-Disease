# Gordon Ramsay's Bank Balance is an exciting reward based MCQ quiz where you get the opportunity to prove your mettle and earn money. For each correct answer in the quiz you are rewarded with $6000 and for each wrong answer a deduction of $3000.


print("Welcome to Gordon Ramsay’s Bank Balance! The show where hero and zero can be\ndown to one simple question...\n\n\n-----\n")

balance = 0;

print("""Question 1:\n
What is objectively the best type of party during COVID?\n
A. Sneaking past the guards into University Gateway at night.\n
B. “If I get it, I get it” party in Tuscany garage.\n
C. No mask YOLO party on Figueroa Street with signs to block traffic.\n
D. The best party during COVID is one that never takes place.\n""")

while (True):
    ans = input("Your answer is: ")
    ans = ans.upper()
    if (ans == "D"):
        balance += 6000
        bal = str(balance)
        print("\nCorrect! Your balance is now $" + bal + ".\n")
        break

    else:
        balance -= 3000
        bal = str(balance)
        print("\nWrong! Your balance is now $" + bal + ".\n")
        continue

print("""\n-----\n\nQuestion 2:\n
What class is this program for?\n
A. ITP-116\n
B. CSCI-201\n
C. ITP-256\n
D. I believe I am a self-driven learner and a great fit for your company. I\n
wrote this entirely out of my overwhelming desire and thirst for knowledge.\n
As Steve Jobs once said, “stay hungry, stay foolish.” Wait, it wasn’t “stay thirsty”?\n""")

while (True):
    ans = input("Your answer is: ")
    ans = ans.upper()
    if (ans == "A"):
        balance += 6000
        bal = str(balance)
        print("\nCorrect! Your balance is now $" + bal + ".\n")
        break

    else:
        balance -= 3000
        bal = str(balance)
        print("\nWrong! Your balance is now $" + bal + ".\n")
        continue

print("""\n-----\n\nQuestion 3 [INSTANT DEATH!]:\n
What is considered a “pro-gamer move” in the software engineering world?\n
A. Force pushing into a shared repository every single time.\n
B. Killing the entire terminal when you accidentally open Vim because
Control+C doesn’t make it quit.\n
C. Resist using any IDEs because Sublime Text (UNREGISTERED) is superior.\n
D. All of the above.\n""")

while (True):
    ans = input("Your answer is: ")
    ans = ans.upper()
    if (ans == "D"):
        balance += 6000
        bal = str(balance)
        print("\nCorrect! Your balance is now $" + bal + ".\n")
        break

    else:
        balance =0
        bal = str(balance)
        print("\nWrong! Your balance is now $" + bal + ".\n")
        break
print("\n-----\n\n")

if (balance > 0):
    print("""Finally, a good flipping contestant. You don’t come into cooking to get rich,
but you come into this show to get rich and you did it. Congratulations!""")

elif (balance == 0):
    print("You came with nothing and you are leaving with nothing.")

else:
    print("""Hey hey hey you, hey you, come here... You do seriously surprise me... With
how bad you are!""")