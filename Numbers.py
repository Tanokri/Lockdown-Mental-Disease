# Table 1
# Equation 1 - True
# Equation 2 - True
# Equation 3 - False
# Equation 4 - False
# Equation 5 - True
# Equation 6 - True
# Equation 7 - False
# Table 2
# Equation 1 - 1111
# Equation 2 - 0001
# Equation 3 - 1010
# Equation 4 - 1101
# Equation 5 - 1000
# Equation 6 - 1010
# Equation 7 - 0101

# Function to add two numbers
def add(x, y):
    return x + y


# Function to subtract two numbers
def subtract(x, y):
    return x - y


# Function to multiply two numbers
def multiply(x, y):
    return x * y


# Function to divide two numbers
def divide(x, y):
    return x / y

# Function to divide to the nearest floor number
def divide2 (x,y):
    return x//y

# Function to give the modulus of two numbers
def mod (x,y) :
    return x%y

# Function to give us the power of two numbers
def power (x,y):
    return x**y

while True:
    # input from the user
    num1 = float(input("Enter a number: "))
    choice = input("Enter an operator (+, -, x, /, //, %, **): ")
    num2 = float(input("Enter a number: "))
    print("\n")

    # check choice for operators
    if choice in ('+', '-', 'x', '/', '//', '%', '**'):


        if choice == '+':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '-':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == 'x':
            print(num1, "x", num2, "=", multiply(num1, num2))

        elif choice == '/':
            print(num1, "/", num2, "=", divide(num1, num2))

        elif choice == '//':
            print(num1, "//", num2, "=", divide2(num1, num2))

        elif choice == '%':
            print(num1, "%", num2, "=", mod(num1, num2))

        elif choice == '**':
            print(num1, "**", num2, "=", power(num1, num2))


        # breaking the while loop
        next_calculation = "no"
        if next_calculation == "no":
            break

    else:
        print("Invalid Input")