#a) Write a Python program to store roll numbers of student in array who attended
# training program in random order. Write function for searching whether particular
# student attended training program or not, using Linear search and Sentinel search.
# b) Write a Python program to store roll numbers of student array who attended
# training program in sorted order. Write function for searching whether particular
# student attended training program or not, using Binary search and Fibonacci search

class Search:
    def __init__(self,list,size):
        self.list=list
        self.size=size

    def linearSearch(self,key):
        count=0
        for i in range(self.size):
            if(self.list[i]==key):
                print("Element found at index : ",i)
                count=1
                break
        if(count==0):
            print("Element not found !")

    def binarySearch(self,key):
        self.list.sort()
        print("Sorted List = ",self.list)
        count=0
        start=0
        end=self.size-1
        while(start<=end):
            mid=(start+end)//2
            if(self.list[mid]==key):
                count=1
                break
            elif(key<self.list[mid]):
                end=mid-1
            else:
                start=mid+1
        if(count==0):
            print("Element not found !")
        else:
            print("Element found at index ",mid)

    def sentinalSearch(self,key):
        last=self.list[self.size-1]
        self.list[self.size-1]=key
        i=0
        while(self.list[i]!=key):
            i+=1;
        self.list[self.size-1]=last
        if(last==key or i<self.size-1):
            print("Element found at index ",i)
        else:
            print("Element not found !")

    def fibonacciSearch(self,key):
        self.list.sort()
        fib2=0
        fib1=1
        fib=fib2+fib1
        while(fib<self.size):
            fib2=fib1
            fib1=fib
            fib=fib2+fib1
        offset=-1
        while(fib>1):
            i=min(offset+fib2,self.size-1)
            if(key>self.list[i]):
                fib=fib1
                fib1=fib2
                fib2=fib-fib1
                offset=i
            elif(key<self.list[i]):
                fib=fib2
                fib1=fib1-fib2
                fib2=fib-fib1
            else:
                return i;
        if(fib1==1 and self.list[offset+1]==key):
            return offset+1
        return -1;


list=[]
size=int(input("Enter the number of elements you want to enter : "))
for i in range(size):
    list.append(int(input("Enter the element : ")))
obj=Search(list,size)

print("**********************MENU***********************")
print("1.Search by Linear Search")
print("2.Search by Binary Search")
print("3.Search by Sentinal Search")
print("4.Search by Fibonacci Search")
print("5.Exit")
print("*************************************************")
choice = int(input("Enter your choice : "))
if (choice == 1):
    key = int(input("Enter the element you want to search : "))
    obj.linearSearch(key)
elif (choice == 2):
    key = int(input("Enter the element you want to search : "))
    obj.binarySearch(key)
elif (choice == 3):
    key = int(input("Enter the element you want to search : "))
    obj.sentinalSearch(key)
elif (choice == 4):
    key = int(input("Enter the element you want to search : "))
    ans = obj.fibonacciSearch(key)
    if (ans!=-1):
        print("Element found at index ", ans)
    else:
        print("Element not found !")
elif (choice == 5):
    print("Exiting...")
    exit(1)
else:
    print("Invalid Choice !")