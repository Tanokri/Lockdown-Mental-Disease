
def quadraticFormula(num1, num2, num3):
    su = 0
    flag = True
    su += (num2 * num2) - (4 * num1 * num3)

    if su < 0:
        su *= -1
        flag = False

    import math
    answer = math.sqrt(su)
    roundedNum = round(answer, 2)
    t1 = (num2 * -1) / (2 * num1)
    t2 = answer / (2 * num1)
    t1 = round(t1, 2)
    t2 = round(t2, 2)
    new1 = 0
    new2 = 0
    positive = ""
    nagtive = ""

    if flag:
        new1 += t1 + t2
        new2 += t1 - t2
        new1 = round(new1, 2)
        new2 = round(new2, 2)
        positive = new1
        negative = new2
    else:
        t1 = str(t1)
        t2 = str(t2)
        positive = t1 + " + " + t2 + "i"
        negative = t1 + " - " + t2 + "i"

    return positive, negative


def getValue(value):
    a = input("Enter " + value + ": ")
    a = float(a)
    return a


def printSolutions(num1, num2, num3, solutionsList1, solutionsList2):
    num1 = str(num1)
    num2 = str(num2)
    num3 = str(num3)
    print("The solutions to the equation " + num1 + "x^2 + " + num2 + "x + " + num3 + " are " + solutionsList1 + " and " + solutionsList2)


def main():

    print("This program finds solutions to the equation ax^2 + bx + c = 0.")
    num1 = getValue("a")
    num2 = getValue("b")
    num3 = getValue("c")
    solutionsList = quadraticFormula(num1, num2, num3)
    solutionsList1 = str(solutionsList[0])
    solutionsList2 = str(solutionsList[1])
    printSolutions(num1, num2, num3, solutionsList1, solutionsList2)


main()