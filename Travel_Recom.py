import random

print("Welcome to the travel recommendation program.\n")

List = ["New York", "London", "Beijing", "Sydney"]

while (True):
    print("""1. Add potential cities to the list.
2. View the potential cities.
3. Remove a city from the list.
4. Make a recommendation where to go.
5. Exit""")

    n = input("What would you like to do? ")

    if n.isnumeric() == False:
        print("Choice must be numeric.")
        print("\n")
    else:
        n = int(n)
        if n > 5 or n < 0:
            print("This is not a valid option.")
            print("\n")

    if n == 1:
        name = input("Which city would you like to add? ")
        name = name.title()
        if name in List:
            print("That's a great city, but it's already in our list.")
            print("\n")
        else:
            List.append(name)
            print(name, "was added to the list.")
            print("\n")

    if n == 2:
        converted_list = [str(element) for element in List]
        joined_string = ", ".join(converted_list)
        print("The cities currently in the list are", joined_string+".")
        print("\n")

    if n == 3:
        remo = input("What city would you like to remove? ")
        remo = remo.title()
        if remo in List:
            List.remove(remo)
            print(remo, "was removed from the list.")
            print("\n")
        else:
            print(remo, "is not in the list.")
            print("\n")

    if n == 4:
        print("Pack your bags. We're going to", random.choice(List)+".")
        print("\n")

    if n == 5:
        print("Thank you for using my travel recommendation program.")
        print("\n")