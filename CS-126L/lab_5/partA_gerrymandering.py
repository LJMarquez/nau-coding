# Building Python Programs
# Programming Project Chapter 6 Gerrymandering

# This program prompts the user for a state name and then outputs a chart
# displaying the population of democrats and republicans in each district in
# the state and whether or not that district is gerrymandered. If the user
# types in a state name that doesn't exist the program outputs a not found
# message.

import turtle
from Lab5_functions import draw_line, draw_rect

WIDTH = 500
HEIGHT = 500

def main():

    # setworldcoordinates(0, HEIGHT, WIDTH, 0)
    # clear()
    # shape('turtle')
    # pencolor('olive drab')
    # fillcolor('sienna')
    # bgcolor('grey')

    print_intro_message()

    #### YOUR CODE GOES HERE #################
    #### Note - YOU CAN USE THE BELOW TEMPLATE or
    #### YOU CAN WRITE YOU OWN CUSTOM FUNCTIONS ######
    
    with open("districts.txt", 'r') as districts_file:
        districts_data = districts_file.read()
    
    districts_list = districts_data.split("\n")
    for state_index in range(len(districts_list)):
        districts_list[state_index] = districts_list[state_index].split(",")
    
    with open("eligible_voters.txt", 'r') as voters_file:
        voters_data = voters_file.read()
    
    voters_list = voters_data.split("\n")
    # for state in range(len(voters_list)):
    #     voters_list[state] = voters_list[state].split(",")

    print(districts_list)
    # print(voters_list)

    # # take state input
    state_input = input("Which state do you want to look up? ")

    # check if state exists or not
    if state_input in voters_data:
        # if exists, gather the total counts of dem,
        # gop votes of all districts of the states
        print("state exists")
        for state_index in range(len(districts_list)):
            if state_input in districts_list[state_index]:
                state_index = districts_list.index(state_input)
                state = districts_list[state_index]
                print(state)
                

    else:
        # if not, print state not found
        print("State not found")


# and prints out a message if the state is gerrymandered.
# If it is, prints out who has gerrymandered it
def is_gerrymandered(dem_votes, gop_votes):
    pass

# takes the total number of dem votes and total number of gop
# votes as parameters and calculates and returns the
# total wasted dem votes and total wasted gop votes
def calculate_wastage(dem, gop):
    pass

    ##########################################

main()