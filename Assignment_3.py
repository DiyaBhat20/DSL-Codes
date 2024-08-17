#Write a Python program to compute following computation on matrix:
# a) Addition of two matrices
# B) Subtraction of two matrices
# c) Multiplication of two matrices
# d) Transpose of a matrix

class Matrix:

    def add(self, m1, m2):
        print(len(m1))
        m3 = [[0,0,0],[0,0,0],[0,0,0]]
        for i in range(0, len(m1)):
            for j in range(0, len(m1[0])):
                m3[i][j] = m1[i][j] + m2[i][j]
        print("Addition of two matrices = ",m3)

    def sub(self, m1, m2):
        m3 = [[0,0,0],[0,0,0],[0,0,0]]
        for i in range(0, len(m1)):
            for j in range(0, len(m1[0])):
                m3[i][j] = m1[i][j] - m2[i][j]
        print("Subtraction of two matrices = ",m3)

    def mult(self, m1, m2):
        m3 = [[0,0,0],[0,0,0],[0,0,0]]
        for i in range(0, len(m1[0])):
            for j in range(0, len(m2[0])):
                for k in range(0, len(m2[0])):
                    m3[i][j]=m3[i][j]+(m1[i][k]*m2[k][j])
        print("Multiplication of two matrices = ",m3)

    def transpose(self,m):
        trans=[[0,0,0],[0,0,0],[0,0,0]]
        for i in range(0, len(m)):
            for j in range(0, len(m[0])):
                trans[i][j] = m[j][i]
        print("Transpose of matrix = ",trans)


m1=[[0,0,0],[0,0,0],[0,0,0]]
m2=[[0,0,0],[0,0,0],[0,0,0]]
print("Enter 3*3 matrix ")
print("Enter first matrix : ")
for i in range(0,3):
    for j in range(0,3):
        print("Enter data for m1[",i,"][",j,"] = ")
        num=int(input())
        m1[i][j]=num
print("Enter second matrix : ")
for i in range(0,3):
    for j in range(0,3):
        print("Enter data for m2[",i,"][",j,"] = ")
        num=int(input())
        m2[i][j]=num
print(m1)        
print(m2)
object=Matrix()
while(1):
    print("*******************************MENU*********************************")
    print("1.Addition of two matrices ")
    print("2.Subtraction of two matrices")
    print("3.Multiplication of two matrices")
    print("4.Transpose of a matrix")
    print("5.Exit")
    print("********************************************************************")
    choice = int(input("Enter your choice:"))
    if choice == 1:
        object.add(m1, m2)
    elif choice == 2:
        object.sub(m1, m2)
    elif choice == 3:
        object.mult(m1, m2)
    elif choice == 4:
        while(1):
            print("********************************")
            print("1.Transpose of first matrix")
            print("2.Transpose of second matrix")
            print("3.Exit")
            print("********************************")
            ch=int(input("Enter your choice : "))
            if (ch==1):
                object.transpose(m1)
            elif (ch==2):
                object.transpose(m2)
            elif (ch==3):
                break
            else:
                print("Invalid Choice !")
    elif choice==5:
        print("Exiting...")
        exit(1)
    else:
        print("Invalid choice !")