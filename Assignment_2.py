#Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determines the frequency of occurrence of particular character in the string
# c) To check whether given string is palindrome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string

class My_String:

    def char_freq(self,mystring):
        lowString = mystring.lower()
        myChar = input("Enter the character to be searched: ")
        lowChar = myChar.lower()
        frequency = 0
        for i in range(0, len(lowString)):
            if (lowChar == lowString[i]):
                frequency += 1
        print("Frequency is: ", frequency)

    def first_occ(self,mystring):
        substring = input("Enter the string to be searched: ")
        substring_length = len(substring)
        found_flag = False
        for i in range(0, len(mystring)):
            if substring == mystring[i: i+substring_length]:
                found_flag = True
                print(i)
                break
        if (found_flag == False):
            print("Not Found")

    def long_word(self,mystring):
        myList = mystring.split()
        #print(myList)
        max = myList[0]
        for i in myList:
            if len(i) > len(max):
                max = i
        print("Longest word = ",max)

    def palindrome(self,mystr):
        revString = mystr[::-1]
        if (revString == mystr):
            print("Yes, the string is palindrome")
        else:
            print("No, the string is not palindrome")

    def word_frequency(self,mystring):
        string_list = mystring.split()
        unique_list = []
        unique_counts = []
        for i in range(0, len(string_list)):
            word = string_list[i]
            for j in range(0, len(unique_list)):
                if word == unique_list[j]:
                    unique_counts[j] += 1
                    break
            else:
                unique_list.append(word)
                unique_counts.append(1)
        for i in range(0, len(unique_counts)):
            print(unique_list[i], ": ", unique_counts[i])

object = My_String()
mystring = input("Enter the string: ")
while(1):
    print("**************************MENU***************************")
    print("1.Display word with longest length")
    print("2.Determine the frequency of occurrence of particular character in the string")
    print("3.Check whether given string is palindrome or not ")
    print("4.Display index of first appearance of the substring")
    print("5.Count the occurrences of each word in a given string")
    print("6.Exit")
    print("*********************************************************")
    choice=int(input("Enter yor choice : "))
    if(choice==1):
        object.long_word(mystring)
    elif(choice==2):
        object.char_freq(mystring)
    elif(choice==3):
        object.palindrome(mystring)
    elif(choice==4):
        object.first_occ(mystring)
    elif(choice==5):
        object.word_frequency(mystring)
    elif(choice==6):
        print("Exiting...")
        exit(1)
    else:
        print("Invalid choice !")
