#In second year computer engineering class, group A student’s play cricket,
# group B students play badminton and group C students play football. Write
# a Python program using functions to compute following: -
# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)

class SetOperations:
    
    def both_cricket_badminton(self,c,b):
        k=[]
        for i in c:
            for j in b:
                if (i==j):
                    k.append(i)
        print("Students who play both cricket and badminton : ",k)

    def either_cricket_badminton(self,c,b):
        l=[]
        for i in c:
            for j in b:
                if (i==j):
                    l.append(i)
        k=[]
        for i in c:
            k.append(i)
        for i in b:
            flag = 0
            for j in c:
                if (i == j):
                    flag = 1
                    break
            if (flag == 0):
                k.append(i)

        for i in k:
            for j in l:
                if(i==j):
                    k.remove(j)
        print("Students who play either cricket or badminton but not both : ",k)

    def neither_cri_badm(self,d,c,b):
        k=[]
        for i in c:
            k.append(i)
        for i in b:
            flag = 0
            for j in c:
                if (i == j):
                    flag = 1
                    break
            if (flag == 0):
                k.append(i)
        print(k)

        for i in k:
            for j in d:
                if(i==j):
                    d.remove(i)
        print("Students who play neither cricket nor badminton : ",d)
        print("Number of students who play neither cricket nor badminton : ",len(d))


    def cri_foot_notbadm(self,c,b,f):
        k=[]                    
        for i in c:
            for j in f:
                if (i==j):
                    k.append(i)

        for i in b:
            for j in k:
                if(i==j):
                    k.remove(i)
        print("Students who play cricket and football but not badminton : ",k)
        print("Number of students who play cricket and football but not badminton : ", len(k))

div=[]
cric=[]
badm=[]
foot=[]
d=int(input("Enter strength of class : "))
i=0
while(i<d):
    s=int(input("Enter roll number : "))
    if s in div:
        print("Invalid number....Enter a new one")
        i-=1
    else:
         div.append(s)
    i+=1
print(div)

c=int(input("Enter strength of cricket players : "))
i=0
while (i<c):
    rc=int(input("Enter roll number : "))
    if rc in cric or rc not in div:
        print("Invalid number....Enter a new one")
        i-=1
    else:
        cric.append(rc)
    i+=1
print(cric)

b=int(input("Enter strength of badminton players"))
i=0
while i<b:
    rb=int(input("Enter roll number : "))
    if rb in badm or rb not in div:
        print("Invalid number....Enter a new one")
        i-=1
    else:
        badm.append(rb)
    i+=1
print(badm)

f=int(input("Enter strength of football players"))
i=0
while i<f:
    rf=int(input("Enter roll number : "))
    if rf in foot or rf not in div:
        print("Invalid number....Enter a new one")
        i-=1
    else:
        foot.append(rf)
    i+=1
print(foot)

print("class = ",div)
print("cricket = ",cric)
print("badminton = ",badm)
print("football = ",foot)

object=SetOperations()
while(1):
    print("*******************************MENU*********************************")
    print("1.List of students who play both cricket and badminton")
    print("2.List of students who play either cricket or badminton but not both")
    print("3.Number of students who play neither cricket nor badminton")
    print("4.Number of students who play cricket and football but not badminton")
    print("5.EXIT")
    print("********************************************************************")
    choice = int(input("Enter your choice : "))
    if (choice == 1):
        object.both_cricket_badminton(cric, badm)
    elif (choice == 2):
        object.either_cricket_badminton(cric, badm)
    elif (choice == 3):
        object.neither_cri_badm(div, cric, badm)
    elif (choice == 4):
        object.cri_foot_notbadm(cric, badm, foot)
    elif (choice==5):
        print("Exiting...")
        exit(1)
    else:
        print("Invalid Choice !")