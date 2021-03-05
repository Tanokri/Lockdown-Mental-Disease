# This program helps create a customised Boba tea for a customer based on their budget and preferences


print("""Welcome to Cha Literally Means Tea! We strive to provide you with the best
boba cha in the entire plaza located on Figueroa where Yoshinoya is!\n""")

budget = float(input("What's your budget for the order in USD? "))

print("""\n
Got it. Let’s build your boba cha!\n
--\n
What would you like as a base?\n
    A. 4.00 - Red Ruby Prem. Black Milk Tea w/ Brown Sugar
    B. 4.50 - Red Ruby Prem. Black Milk Tea w/ Pearls
    C. 4.00 - Jasmine Green Milk Tea
    D. 4.00 - Light Roast Oolong Milk Tea
    E. 4.00 - Full Roast Oolong Milk Tea
    F. 4.00 - Golden Phoenix High Mtn. Milk Tea
    G. 4.25 - Mango Green Milk Tea\n""")

a = ["Red Ruby Prem. Black Milk Tea w/ Brown Sugar", "Red Ruby Prem. Black Milk Tea w/ Pearls",
     "Red Ruby Prem. Black Milk Tea w/ Pearls", "Jasmine Green Milk Tea", "Light Roast Oolong Milk Tea",
     "Full Roast Oolong Milk Tea", "Golden Phoenix High Mtn. Milk Tea", "Mango Green Milk Tea"]
b = ["A", "B", "C", "D", "E", "F", "G"]
c = [4.00, 4.50, 4.00, 4.00, 4.00, 4.00, 4.25]

balance = 0.0

choice = input("Your Choice: ")
choice = choice.upper()

for i in b:
    if choice in b:
        print("\nGreat choice!", a[b.index(choice)], "is our best seller!\n")
        balance += c[b.index(choice)]
        balance = "{:.2f}".format(balance)
        print(f"Your current balance is ${balance}.\n")
        break
else:
    print("Inavlid Option. You have to start again. Please select from the list of above teas! Thank You!\n")
    exit()

print("""Time to choose some toppings! Enter how many portions of each addon you’d
like to add to your base tea =) The price shown below is per portion.""")

balance = float(balance)

topping1 = int(input("\n0.50 - Pearls: "))
if topping1 > 0:
    balance += topping1 * 0.50
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping2 = int(input("\n0.50 - Mini Pearls: "))
if topping2 > 0:
    balance += topping2 * 0.50
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping3 = int(input("\n0.50 - Pudding: "))
if topping3 > 0:
    balance += topping3 * 0.50
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping4 = int(input("\n0.50 - Aloe Vera: "))
if topping4 > 0:
    balance += topping4 * 0.50
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping5 = int(input("\n0.75 - Tiramisu Creama: "))
if topping5 > 0:
    balance += topping5 * 0.75
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping6 = int(input("\n0.50 - Salty Cheese Creama: "))
if topping6 > 0:
    balance += topping6 * 0.50
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

topping7 = int(input("\n66.88 - Edible Gold Flakes: "))
if topping7 > 0:
    balance += topping7 * 66.88
    balance = "{:.2f}".format(balance)
    print("\nYour current balance is ${}.".format(balance))
    balance = float(balance)

print("\n\nYour order is complete! The total is ${}.".format(balance), "\n\n")
balance = float(balance)

if balance <= budget:
    print("Enjoy your boba tea!")

else:
    print("Oops, looks like you didn't bring enough money! You would have to start over.")