# imported libraries
import random

# Constants
MAX_NUMBER = 100

# The main program
# ----------------
def main():

    # A sentinel loop to keep playing after each game is done
    print("A haiku for you:")
    print("Hidden numbers wait,")
    print("Guess with logic and some luck,")
    print("Will you guess it right?")

    total_games = 0
    guess_list = []
    play_again = "yes"

    while play_again.startswith("y"):
        total_games += 1
        guess_list.append(start_game())
        play_again = input("Do you want to play again? ")
        play_again = play_again.lower()
        print()

    total_guesses = sum(guess_list)

    print_results( total_games, total_guesses, guess_list )

    pass

# Supporting functions (in alphabetical order)
# --------------------------------------------

# A function that plays one game
def start_game():
    # Required input (parameters): none
    # Required return: number of guesses
    # Device input: number guesses
    # Device output: prompts and number of guesses required

    random_number = random.randint(1, MAX_NUMBER)
    user_guess = 0
    number_of_guesses = 0
    print(f"I'm thinking of a number between 1 and {MAX_NUMBER}...")

    while user_guess != random_number:

        while user_guess < 1 or user_guess > 100:
            try:
                user_guess = int(input("Your guess? "))
                if user_guess < 1 or user_guess > 100:
                    print("Please enter a number between 1-100")
            except ValueError:
                print("Please enter a number between 1-100")
            

        number_of_guesses += 1
        if user_guess == random_number:
            print(f"You got it right in {number_of_guesses} guesses!")
            return number_of_guesses

        elif user_guess > random_number:
            print("It's lower.")
        else:
            print("It's higher.")

        user_guess = 0
            
# A function that displays
def print_results(total_games, total_guesses, guess_list):
    # Required input (parameters): game tallies
    # Required return: none
    # Device input: none
    # Device output: overall results table

    guesses_per_game = round(total_guesses / total_games, 1)
    guess_list.sort()

    print("Overall results:")
    print(f"Total Games = {total_games}")
    print(f"Total Guesses = {total_guesses}")
    print(f"Guesses/Game = {guesses_per_game}")
    print(f"Best Game = {guess_list[0]} guesses")

main()
