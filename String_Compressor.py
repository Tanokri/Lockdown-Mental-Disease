# This program will input a string from the user and then check it for certain given parameters

user = input("Enter the input: ")
a = "\\"
a.rstrip()
b= "n"
t= "t"
d = a + b
user = user + " "
c = 1
w = 0
for i in range(0, len(user)-1 ):
    if user[i] == a and user [i+1] == b:
        c+=1
    if user[i] == " " or (user[i] == a and user[i+1] == t):
        w+=1
h=user.count("for")
j= user.count("while")
h= h+j
print("- Number of lines:",c)
print("\n")
print("- Number of words:", w)
print("\n")
print("- Number of loops:", h)
print("\n")

if h == 1:
    print("- Rating: Could be worse")
    print("\n")
elif h == 0:
    print("- Rating: Perfection")
    print("\n")
elif h >= 2:
    print("- Dumpster gas fire")
    print("\n")

print("- Decompressed source:")
print("\n")

nstr = ""
nstr = nstr + user[0]
for i in range(1, len(user)-1 ):
    if user[i] == a and user [i+1] == b:
        nstr = nstr + "\n"
    elif user[i] == a and user[i+1] == t:
        nstr = nstr + "\t"
    elif user[i] == b and user[i-1]==a:
        user[i].replace("n","")
    elif user[i] == t and user[i-1] == a:
        user[i].replace("t","")
    else:
        nstr = nstr + user[i]


print(nstr)