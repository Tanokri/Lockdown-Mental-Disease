import random

while (True):
    a = int(input("Enter the lower bound: "))
    b = int(input("Enter the upper bound: "))
    if a >= b:
        print("The upper bound must be larger than the lower bound.")
        continue

    print("I'm thinking of a number between", a, "and", b)

    num = random.randint(a, b)


    while (True):
        guess = int(input("Guess a number: "))
        if guess > b or guess < a:
            print(guess, "is outside the range of possible values.")
            continue
        elif guess == num:
            print("You guessed it!")
            break
        elif guess > num:
            print(guess, "is too high.")
        elif guess < num:
            print(guess, "is too low.")


    retry = input("Do you want to play again? ")
    retry = retry.upper()
    if (retry == "NO"):
        print("Thank you for playing!")
        break
    elif (retry == "YES"):
        print(" ")
        continue
    else:
        print("Incorrect Input... Please try again!")
        exit()