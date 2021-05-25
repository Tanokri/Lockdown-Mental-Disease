import math

myCityList = []
myCoordinateList = []
loc1 = 0
loc2 = 0


def userinput():
    myCityList = []
    myCoordinateList = []
    while (True):
        n = input("What’s the name of the location? ")
        check = n.title()
        if (check == "End"):
            return myCityList, myCoordinateList
        else:
            myCityList.append(n)

        while (True):
            cord = input("What are the X and Y coordinates? ")
            x = cord.split(" ")

            flag = False
            for i in x:
                try:
                    float(i)
                    flag = True
                    continue
                except ValueError:
                    flag = False

                if (i.isnumeric()):
                    flag = True
                else:
                    flag = False
                    break

            if (flag == False):
                print("Please only enter numeric values for the X and Y coordinates.")
                continue
            elif (len(x) != 2):
                print("Please enter two numeric values for the X and Y coordinates.")
            else:
                myCoordinateList.append(cord)
                print("Saved!")
                break


myCityList, myCoordinateList = userinput()


def step2():
    print("--------")
    print("Available locations: ")
    c = 1
    for i in myCityList:
        print("\t" + str(c) + ". " + i)
        c += 1
    while (True):
        loc1 = input("Please pick the first location: ")
        temp = loc1.upper()
        if (temp == "EXIT"):
            print("Goodbye friend!")
            exit()
        if loc1.isnumeric() == False:
            print(loc1, "is not a valid location.")
            continue
        elif (int(loc1) > len(myCityList) or int(loc1) < 1):
            print(loc1, "is not a valid location.")
            continue
        else:
            break

    while (True):
        loc2 = input("Please pick the second location: ")
        if loc2.isnumeric() == False:
            print(loc2, "is not a valid location.")
            continue
        elif (int(loc2) > len(myCityList) or int(loc2) < 1):
            print(loc2, "is not a valid location.")
            continue
        else:
            break
    return loc1, loc2


loc1, loc2 = step2()


def step3():

    cit1 = myCoordinateList[int(loc1) - 1]
    cit2 = myCoordinateList[int(loc2) - 1]
    cit1 = cit1.split(" ")
    cit2 = cit2.split(" ")

    x1 = cit1[0]
    x1 = float(x1)
    y1 = cit1[1]
    y1 = float(y1)

    x2 = cit2[0]
    x2 = float(x2)
    y2 = cit2[1]
    y2 = float(y2)

    euc = math.sqrt((math.pow((y2 - y1), 2)) + (math.pow((x2 - x1), 2)))

    man = abs(y2 - y1) + abs(x2 - x1)

    return euc, man


def step4():
    euc, man = step3()
    temp1 = int(loc1)
    temp2 = int(loc2)

    print("The Euclidean distance between " + (myCityList[temp1 - 1]) + " and " + str(
        myCityList[temp2 - 1]) + " is " + str(euc))
    print("The Manhattan distance between " + (myCityList[temp1 - 1]) + " and " + str(
        myCityList[temp2 - 1]) + " is " + str(man))

    while (True):
        step2()
        step3()
        step4()


def main():
    step4()

main()