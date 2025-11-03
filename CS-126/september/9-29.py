list = [10, 24, "hello", 3.14, True, ["apple", "banana", 20]]



# Write a complete console program that implements a Caesar cipher or rotation cipher, which is a crude system of encoding strings by shifting every letter forward by a given number. Your program should prompt the user to type a message and an encoding "key" (number of places to shift each character) and display the shifted message. For example, if the shift amount is 3, then the letter A becomes D, and B becomes E, and so on. Letters near the end of the alphabet wrap around for a shift of 3, X becomes A, and Y becomes B, and Z becomes C. Here are two example dialogues:

# Your message? Attack zerg at dawn
# Encoding key? 3
# DWWDFN CHUJ DW GDZQ

# Your message? DWWDFN CHUJ DW GDZQ
# Encoding key? -3
# ATTACK ZERG AT DAWN

ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def caesar_cipher():
    user_input = input("Your message? ")
    encoding_key = int(input("Encoding key? "))

    user_input = user_input.upper()
    new_message = ""
    for character_index in range(len(user_input)):
        character = user_input[character_index]
        # if character == " ":
        #     new_message += character
        # else:
        #     current_index = ALPHABET.find(character)
        #     new_index = current_index + encoding_key
        #     if new_index > len(ALPHABET) - 1:
        #         new_index = new_index - len(ALPHABET) 
        #     new_character = ALPHABET[new_index]
        #     new_message += new_character

        if "A" <= character <= "Z":
            current_index = ALPHABET.find(character)
            new_index = current_index + encoding_key
            if new_index > len(ALPHABET) - 1:
                new_index = new_index - len(ALPHABET) 
            new_character = ALPHABET[new_index]
            new_message += new_character
        else:
            new_message += character

    print(new_message)

caesar_cipher()


def calculate_days_above_average():
    daily_temperatures = []
    days_above_average = 0
    days = 0
    
    while not days:
        try:
            days = int(input("How many days\' temperatures? "))
        except ValueError:
            print("Please enter an integer")

    for day in range(1, days + 1):
        day_temperature = float(input(f"Day {day}'s high temp: "))
        try:
            daily_temperatures.append(day_temperature)
        except ValueError:
            print("Can't float!")

    average = sum(daily_temperatures)/len(daily_temperatures)
    
    for current_temperature in daily_temperatures:
        if current_temperature > average:
            days_above_average += 1
    
    print(f"Average temp = {average}")
    print(f"{days_above_average} days were above average.")

# calculate_days_above_average()