#Write a Python program to store first year percentage of students in array.
# Write function for sorting array of floating point numbers in ascending order
# using quick sort and display top five scores.

class Sort:
    def __init__(self,arr):
        self.arr=arr

    def quicksort(self, left, right):
        if left < right:
            pivot_position = self.partition(left, right)
            self.quicksort(left, pivot_position - 1)
            self.quicksort(pivot_position + 1, right)

    def partition(self, left, right):
        i = left
        j = right - 1
        pivot = self.arr[right]

        while i < j:
            while i < right and self.arr[i] < pivot:
                i += 1

            while j > left and self.arr[j] >= pivot:
                j -= 1

            if i < j:
                self.arr[i], self.arr[j] = self.arr[j], self.arr[i]

        if arr[i] > pivot:
            self.arr[i], self.arr[right] = self.arr[right], self.arr[i]

        return i;

    def display(self):
        print("Top five scores = [",end=" ")
        for i in range(-5,0):
            print(self.arr[i])
        
arr=[]
size=int(input("Enter the number of elements you want to enter : "))
for i in range(size):
    arr.append(float(input("Enter the percentage : ")))
obj=Sort(arr)
print("Unsorted array : ",obj.arr)
obj.quicksort(0,size-1)
print("Sorted array : ",obj.arr)
obj.display()
