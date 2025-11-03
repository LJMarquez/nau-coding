# lists are mutable

# my_list = [10, 50, "string", 2.1, "bob"]

# data_stream = open("data.txt")
# data_stream.close()

# file_location = r"C:\\Users\\marqu\Documents\data.txt"
# with open(file_location) as data_stream:
#     data = data_stream.read()

# print(data)

# with open('new_data.txt', mode = 'w') as data_stream:
#     data_stream.write("hello good sir today")

# def main():
    
#     # filename = "weather.txt"
#     # differences = []

#     # with open(filename) as weather_data:
#     #     numbers_string = weather_data.read()

#     # list_of_string_numbers = numbers_string.split()

#     # for current_element_index in range(0, len(list_of_string_numbers) - 1):
#     #     current_element = float(list_of_string_numbers[current_element_index])
#     #     next_element = float(list_of_string_numbers[current_element_index + 1])

#     #     differences.append(next_element - current_element)


#     # print(differences)

    
#     total = 0

#     filename = "weather.txt"

#     with open(filename) as weather_data:
#         numbers_string = weather_data.read()

#     list_of_string_numbers = numbers_string.split()

#     for current_element_index in range(0, len(list_of_string_numbers)):
#         current_element = float(list_of_string_numbers[current_element_index])
#         print(current_element)
#         total += current_element
    
#     average = total / len(list_of_string_numbers)

#     print(total)

# main()

# Write a function named pig_latin that accepts as a parameter a string representing an input file name. Your function should, preserving line breaks, prout the input file's text in a simplified version of Pig Latin, a silly English variant where the first letter of each word is moved to the end. The rules for translating a word to Pig Latin are as follows:

# If the word starts with a vowel (aeiou), simply append "yay". For example, "elephant" becomes "elephantyay".
# If the word starts with a consonant, move the consonant to the end, and append "ay". For example, "welcome" becomes "elcomeway".
# As an overall example, if the input file lincoln.txt contains the following text:

# four score and
# seven years ago our
# fathers brought forth on this continent a new nation
# The call of pig_latin("lincoln.txt") should produce the following output:

# ourfay coresay andyay
# evensay earsyay agoyay ouryay
# athersfay roughtbay orthfay onyay histay ontinentcay ayay ewnay ationnay

def pig_latin( filename ):
    with open(filename) as input_file:
        text = input_file.read()

    new_lines = []
    lines = text.split("\n")

    for line in lines:
        new_words = []
        words = line.split(" ")
        
        for word in words:
            if word[0].lower() in "aeiou":
                new_word = word + "yay"
            else:
                new_word = word[1:] + word[0] + "ay"
            
            new_words.append(new_word)
        
        new_line = " ".join(new_words)
        new_lines.append(new_line)

    return "\n".join(new_lines)

# print(pig_latin("piglatin.txt"))

# Write a console program that reads an input file of temperatures, with numbers representing daily high temperatures such as:

# 16.2   23.2
#    19.2 7.7  22.9

# 18.4  -1.6 14.6
# Your program should prompt for the file name to read, then read its data and print the change in temperature between each pair of neighboring days.

# Input file? weather.txt 
# 16.2 to 23.2, change = 7.0
# 23.2 to 19.2, change = -4.0
# 19.2 to 7.7, change = -11.5
# 7.7 to 22.9, change = 15.2
# 22.9 to 18.4, change = -4.5
# 18.4 to -1.6, change = -20.0
# -1.6 to 14.6, change = 16.2
# If there are any non-numeric tokens of input in the file, your program should skip over them and ignore them. You may assume that the user types the name of a file that exists and is readable.


# def main():
#     filename = input("Input file? ")
#     with open(filename) as input_file:
#         data = input_file.read()
    
#     data_list = data.split()

#     temperatures = []
#     for temp in data_list:
#         try:
#             temperatures.append(float(temp))
#         except ValueError:
#             pass      

#     for index in range(len(temperatures) - 1):
#         current_temp = temperatures[index]
#         next_temp = temperatures[index + 1]
#         difference = round(next_temp - current_temp, 1)
#         print(f"{current_temp} to {next_temp}, change = {difference}")


# Write a function named get_file_name that repeatedly prompts the user for a file name until the user types the name of a file that exists on the system. Once you get a good file name, return that file name as a string. Here is a sample dialogue from one call to your function, assuming that the file good.txt does exist and the others do not:

# Type a file name: bad.txt
# Type a file name: not_here.txt
# Type a file name: good.txt

def get_file_name():
    filename = input("Type a file name: ")
    while True:
        try:
            with open(filename) as input_file:
                data = input_file.read()
            return filename
        except FileNotFoundError:
            filename = input("Type a file name: ")