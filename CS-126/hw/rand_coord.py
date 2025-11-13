# Write a console program that plays a two-dimensional number guessing game with the user. The computer chooses a point between (1, 1) and (20, 20) inclusive. The user is repeatedly asked to guess the point. For each incorrect guess, the program will give the user one of the following three hints:

# hot (a distance = 1.5 from the correct answer)
# warm (a distance = 5.0 from the correct answer)
# cold (a distance > 5.0 away from the right answer)
# The hints about guesses being hot, warm, or cold are based on distances between points. The formula to compute the distance between two points is to take the square root of the squares of the differences in x and y between the two points. For example, if the correct point is (11, 4) and the user guesses (5, 7), their distance is the square root of ((11 - 5)2 + (4 - 7)2) or roughly 6.71, so the hint is "cold".

# The game also hints about which direction the user should go from the current guess to find the right answer:

# north (the user should increase y)
# south (the user should decrease y)
# east (the user should increase x)
# west (the user should decrease x)
# When the game ends, the program reports how many guesses were needed.

# After each game, the program asks the user if he/she would like to play again. Assume that the user will type a one-word string as the response to this question. A new game should begin if the user's response starts with a lower- or upper-case Y, such as "y", "Y", "yes", "YES", "Yes", or "yeehaw". Responses of "no", "No", "okay", "0", "certainly", and "hello" are all assumed to mean no.

# Once the user chooses not to play again, the program prints overall statistics about all games. The total number of games, total guesses made in all games, average number of guesses per game (as a number rounded to the nearest tenth), and best game (fewest guesses needed to solve any one game) are displayed.

# This program is a 2-D guessing game.
# I will think of a point somewhere
# between (1, 1) and (100, 100)
# and give hints until you guess it.

# Guess x and y: 5 7
# You're cold. Go south east 
# Guess x and y: 18 5
# You're cold. Go south west 
# Guess x and y: 15 2
# You're warm. Go north west 
# Guess x and y: 12 3
# You're hot! Go north west 
# Guess x and y: 11 4
# You got it right in 5 guesses!
# Play again? y

# Guess x and y: 10 10
# You're cold. Go south west 
# Guess x and y: 5 5
# You're warm. Go east 
# Guess x and y: 8 5
# You're hot! Go east 
# Guess x and y: 9 5
# You got it right in 4 guesses!
# Play again? YES

# Guess x and y: 18 10
# You're cold. Go south west 
# Guess x and y: 7 1
# You're cold. Go north east 
# Guess x and y: 10 3
# You're warm. Go north east 
# Guess x and y: 20 20
# You're cold. Go south west 
# Guess x and y: 12 5
# You're hot! Go north west 
# Guess x and y: 15 8
# You're warm. Go south west 
# Guess x and y: 11 6
# You got it right in 7 guesses!
# Play again? n

# Overall results:
# Games played  = 3
# Total guesses = 16
# Guesses/game  = 5.3

import random

MAX_NUMBER = 100

def print_overall_results(guess_list):
    games_played = len(guess_list)
    total_guesses = sum(guess_list)
    guesses_per_game = round(total_guesses / games_played, 1)

    print("Overall results:")
    print(f"Games played  = {games_played}")
    print(f"Total guesses = {total_guesses}")
    print(f"Guesses/game  = {guesses_per_game}")

def check_distance(current_coord, target_coord):
    distance_from_target = (((target_coord[0] - current_coord[0]) ** 2) + ((target_coord[1] - current_coord[1]) ** 2)) ** 0.5
    if distance_from_target <= 1.5:
        print("You're hot! Go ", end="")
    elif distance_from_target <= 5:
        print("You're warm. Go ", end="")
    else:
        print("You're cold. Go ", end="")
    
    if current_coord[1] > target_coord[1]:
        print("south", end=" ")
    elif current_coord[1] < target_coord[1]:
        print("north", end=" ")

    if current_coord[0] > target_coord[0]:
        print("west", end="")
    elif current_coord[0] < target_coord[0]:
        print("east", end="")
    print()

def play_game():
    rand_x_coord = random.randint(1, MAX_NUMBER)
    rand_y_coord = random.randint(1, MAX_NUMBER)
    random_coord = [rand_x_coord, rand_y_coord]
    print(random_coord)
    user_coord = []
    guesses = 0

    while user_coord != random_coord:
        guesses += 1
        user_guess = input("Guess x and y: ")
        user_coord = user_guess.split()
        if len(user_coord) == 2:
            user_coord[0] = int(user_coord[0])
            user_coord[1] = int(user_coord[1])
        if user_coord != random_coord:
            check_distance(user_coord, random_coord)

    if guesses == 1:
        print(f"You got it right in {guesses} guess!")
    else: 
        print(f"You got it right in {guesses} guesses!")

    return guesses

def main():

    print("This program is a 2-D guessing game.")
    print("I will think of a point somewhere")
    print(f"between (1, 1) and ({MAX_NUMBER}, {MAX_NUMBER})")
    print("and give hints until you guess it.")
    print()
    guess_list = []

    play_again = "yes"
    while play_again.startswith("y"):
        guess_list.append(play_game())
        play_again = input("Play again? ").lower()
        print()
    
    print_overall_results(guess_list)

main()