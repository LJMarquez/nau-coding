def is_vowel( letter ):
    lower_letter = letter.lower()
    if lower_letter == "a" or lower_letter == "e" or lower_letter == "i" or lower_letter == "o" or lower_letter == "u":
        return True
    else:
        return False

# print(is_vowel("a"))
# print(is_vowel("b"))

def print_letter(word):
    for letter_index in range(0, len(word) - 1):
        print(word[letter_index] + ", ", end="")
    last = len(word) - 1
    print(word[last])

# print_letter("alskfdj")

def is_palindrome( word ):
    reversed_word = word[::-1].lower()
    return word.lower() == reversed_word
    
# print(is_palindrome("racecar"))
# print(is_palindrome("raCecAr"))
# print(is_palindrome("not"))

def stutter( phrase ):
    for letter in range(len(phrase)):
        print(phrase[letter] * 2, end="")

# stutter("hello")

def add_numbers_while():
    total_sum = 0.0
    sentinel = "q"
    input_prompt = f"Provide a nunmber to add (or {sentinel} to exit): "

    user_input = input(input_prompt)
    
    while user_input != sentinel:
        try:
            total_sum += float(user_input)
        except ValueError:
            print("Oops, something went wrong")

        # if floatable(user_input):
        #     total_sum += float(user_input)
        # else:
        #     print("Oops, something went wrong")

        print(f"Your current total is: {total_sum}")

        user_input = input(input_prompt)
    
    print(f"Your final total sum is: {total_sum}")

def floatable( string ):

    one_dot_present = False
    string_length = len(string)
    letter_index = 0

    if ("-" <= letter <= "9") and letter != "/":
        if letter == ".":
            one_dot_present = True
        letter_index += 1

        while letter_index < string_length:
            letter = string[letter_index]
            if "0" <= letter <= "9" or (letter == ".") and one_dot_present:
                return False

        # if not "0" <= letter <= "9":
        #     if letter_index == 0 and (letter != "-" or letter != "."):
        #         return False
        #     elif letter == "." and one_dot_present:
        #         return False
        # else:
        #     return False
            

        letter_index += 1

    return True

# add_numbers_while()

def stutter( phrase ):
    stutter_phrase = ""
    for letter in range(len(phrase)):
        stutter_phrase += phrase[letter] * 2
    return stutter_phrase

# print(stutter("hello"))


import random

# def start_piglet():
#     print("Welcome to Piglet!")
#     score = 0

#     user_input = "y"

#     dice_roll = random.randint(1, 6)
#     while user_input == "yes" or user_input == "y" and dice_roll != 1:
#         print(f"You rolled a {dice_roll}")
#         if dice_roll == 1:
#             print("You got 0 points.")
#         else:
#             score += dice_roll
#             user_input = input("Roll again? ").lower()
#         dice_roll = random.randint(1, 6)

def start_piglet():
    print("Welcome to Piglet!")
    score = 0

    user_input = "y"

    dice_roll = random.randint(1, 6)
    while user_input == "yes" or user_input == "y":
        print(f"You rolled a {dice_roll}")
        if dice_roll == 1:
            print("You got 0 points.")
            user_input = "n"
        else:
            score += dice_roll
            user_input = input("Roll again? ").lower()
            while user_input != "yes" and user_input != "y" and user_input != "no" and user_input != "n":
                user_input = input("Please answer yes or no: ").lower()
            if user_input == "no" or user_input == "n":
                print(f"Your final score is: {score}")
            else:
                dice_roll = random.randint(1, 6)

# start_piglet()


print("Welcome to Piglet!")
score = 0

user_input = "y"

dice_roll = random.randint(1, 6)
while user_input == "yes" or user_input == "y":
    print(f"You rolled a {dice_roll}")
    if dice_roll == 1:
        print("You got 0 points.")
        user_input = "n"
    else:
        score += dice_roll
        user_input = input("Roll again? ").lower()
        while user_input != "yes" and user_input != "y" and user_input != "no" and user_input != "n":
            user_input = input("Please answer yes or no: ").lower()
        if user_input == "no" or user_input == "n":
            print(f"Your final score is: {score}")
        else:
            dice_roll = random.randint(1, 6)
    