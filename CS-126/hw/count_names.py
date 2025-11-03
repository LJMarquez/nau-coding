# Write a complete console program that asks the user for a list of names (one per line) until the user enters a blank line (i.e., just presses Enter when asked for a name). At that point, the program should print out how many times each name in the list was entered. A sample run of this program is shown below.

# Enter name: Alice
# Enter name: Bob
# Enter name: Alice
# Enter name: Chelsea
# Enter name: Bob
# Enter name: Alice
# Enter name:
# Entry [Alice] has count 3
# Entry [Bob] has count 2
# Entry [Chelsea] has count 1

names_dict = {}
user_input = input("Enter name: ")
while user_input != "":
    user_input = input("Enter name: ")
    names_dict[user_input] = user_input

print(names_dict)

