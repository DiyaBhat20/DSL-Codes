#Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
#a) Selection Sort 
#b) Bubble sort and display top five scores.
#Write a Python program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using 
#a) Insertion sort 
#b) Shell Sort and display top five scores

class Sorting:
    def __init__(self):
        self.arr = []

    def input(self):
        self.size = int(input("Enter total number of students : "))
        if self.size <= 0:
            print("Invalid input try again")
            return
        else:
            for i in range(self.size):
                ans = float(input("Enter percentage of student :"))
                self.arr.append(ans)
            return self.arr

    def bubble_sort(self):
        for i in range(self.size):
            for j in range(self.size-i-1):
                if (self.arr[j] > self.arr[j + 1]):
                    temp = self.arr[j]
                    self.arr[j] = self.arr[j + 1]
                    self.arr[j + 1] = temp
        return self.arr

    def selection_sort(self):
        for i in range(self.size):
            min_index=i
            for j in range(i + 1, self.size):
                if (self.arr[j] < self.arr[min_index]):
                    min_index=j
            self.arr[i], self.arr[min_index] = self.arr[min_index], self.arr[i]
            print(self.arr)
        return self.arr

    def insertion_sort(self):
        for i in range(1,self.size):
            temp = self.arr[i]
            j = i - 1
            while j >= 0 and temp < self.arr[j]:
                self.arr[j + 1] = self.arr[j]
                j = j - 1
            self.arr[j + 1] = temp
        return self.arr

    def shell_sort(self):
        gap = self.size // 2
        while gap > 0:
            for i in range(gap, self.size):
                temp = self.arr[i]
                j = i
                while j >= gap and temp < self.arr[j - gap]:
                    self.arr[j] = self.arr[j - gap]
                    j = j - gap
                self.arr[j] = temp
            gap = gap // 2
        return self.arr

    def top_five(self):
        answer = []
        print("Top five scorers are : ")
        for i in range(-5,0):
            print(self.arr[i],end=" ")
        print()   


s = Sorting()
while (True):
    print("-----------MENU------------")
    print("1.Enter student percentages")
    print("2.Perform bubble sort")
    print("3.Perform selection sort")
    print("4.Perform insertion sort")
    print("5.Perform shell sort")
    print("6.Display top five percentages")
    print("0.Exit")
    print("---------------------------")
    print(">>>")
    ch = int(input())
    if ch == 1:
        s.input()
    elif ch == 2:
        ans1 = s.bubble_sort()
        print("Sorted percentages :", ans1)
    elif ch == 3:
        ans2 = s.selection_sort()
        print("Sorted percentages :", ans2)
    elif ch == 4:
        ans3 = s.insertion_sort()
        print("Sorted percentages :", ans3)
    elif ch == 5:
        ans4 = s.shell_sort()
        print("Sorted percentages :", ans4)
    elif ch == 6:
        if not sorted:
            print("Sort first!!")
        else:
            s.top_five()
    elif ch == 0:
        break
    else:
        print("Inavlid Input!!")