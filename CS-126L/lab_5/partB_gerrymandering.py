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

    turtle.setworldcoordinates(0, HEIGHT, WIDTH, 0)
    turtle.clear()
    turtle.speed(0)
    # shape('turtle')
    # pencolor('olive drab')
    # fillcolor('sienna')
    turtle.bgcolor('white')

    print_intro_message()

    #### YOUR CODE GOES HERE #################
    #### Note - YOU CAN USE THE BELOW TEMPLATE or
    #### YOU CAN WRITE YOU OWN CUSTOM FUNCTIONS ######
    
    with open("districts.txt", 'r') as districts_file:
        districts_data = districts_file.read()
    
    districts_data = districts_data.lower()
    
    districts_list = districts_data.split("\n")
    for state_index in range(len(districts_list)):
        districts_list[state_index] = districts_list[state_index].split(",")
    
    with open("eligible_voters.txt", 'r') as voters_file:
        voters_data = voters_file.read()
    
    voters_data = voters_data.lower()
    voters_list = voters_data.split("\n")
    for state in range(len(voters_list)):
        voters_list[state] = voters_list[state].split(",")

    # print(districts_list)
    # print(voters_list)

    # take state input
    # state_input = input("Which state do you want to look up? ").lower()
    state_input = "arizona"

    state_data = get_state_details(districts_list, state_input)
    if state_data:
        eligible_voters = 0
        # check if state exists or not
        # if state_input in voters_data:

        # add total eligible voters from eligible_voters.txt to
        # state_data because that info wasn't originally there
        for state_index in range(len(voters_list)):
            if state_input in voters_list[state_index]:
                eligible_voters = voters_list[state_index][1]
                state_data.append(eligible_voters)

        process_state_details(state_data)
        state_name = state_data[0]
        draw_intro_graphics(state_name, eligible_voters)
        draw_district_graphics(0, 0, 0)
    else:
        # if not, print state not found
        print("State not found")


# function to output the introduction message to console.
def print_intro_message():
    print("This program allows you to search through")
    print("data about congressional voting districts")
    print("and determine whehter a particular state is")
    print("gerrymandered.")
    print()

# function to print state name, eligible voters and
# horizontal and vertical lines to panel
def draw_intro_graphics(state_name, eligible_voters):
    state_name_list = state_name.split()
    for word in range(len(state_name_list)):
        state_name_list[word] = state_name_list[word].capitalize()
    state_name = " ".join(state_name_list)

    turtle.penup()
    turtle.goto(0, 7)
    turtle.write(f"{state_name}")
    turtle.goto(500, 7)
    turtle.write(f"{eligible_voters} eligible voters", align="right")
    turtle.goto(-10, 10)
    turtle.pendown()
    turtle.goto(510, 10)
    turtle.penup()
    turtle.goto(250, -10)
    turtle.pendown()
    turtle.goto(250, 510)
    turtle.penup()
    turtle.goto(0, 15)

# function to check whether state exists or not
# if exits, returns the state details line
def get_state_details(state_list, state_name):
    for state_index in range(len(state_list)):
        if state_name in state_list[state_index]:
            return state_list[state_index]


# function to process the state details in the format:
# <state>,<district1>,<dem votes>,<gop votes>,<district2>,<dem votes>,<gop votes>,...
# calculate and return total dem and gop votes
# also prints the district graphics to the panel
def process_state_details(state_details):
    state_districts = []
    # if exists, gather the total counts of dem,
    # gop votes of all districts of the states

    total_eligible_voters = state_details.pop()

    for i in range(1, len(state_details), 3):
        state_districts.append(state_details[i:i + 3])
    
    print(state_districts)

    wasted_dem_votes = 0
    wasted_gop_votes = 0

    for district_index in range(len(state_districts)):
        dem_votes = int(state_districts[district_index][1])
        gop_votes = int(state_districts[district_index][2])

        wasted_votes = calculate_wastage(dem_votes, gop_votes)
        wasted_dem_votes += wasted_votes[0]
        wasted_gop_votes += wasted_votes[1]

    favored_party = is_gerrymandered(wasted_dem_votes, wasted_gop_votes)
    
    print(f"Total Wasted Democratic votes: {wasted_dem_votes}")
    print(f"Total Wasted Republican votes: {wasted_gop_votes}")
    if favored_party:
        print(f"Gerrymandered benefiting the {favored_party}")
    print(f"{total_eligible_voters} eligible voters")

# function which caluculate the width of dem_votes and gop_votes
# and print the rectangles to the panel using the y_index as starting point
def draw_district_graphics(dem_votes, gop_votes, y_index):



    turtle.done()

# function to check whether the votes are gerrymandered or not
# and prints out a message if the state is gerrymandered.
# If it is, prints out who has gerrymandered it
def is_gerrymandered(dem_votes, gop_votes):
    difference = abs(dem_votes - gop_votes)
    total_wasted_votes = (dem_votes + gop_votes)
    percent_difference = (difference / total_wasted_votes) * 100
    if percent_difference > 6:
        if dem_votes < gop_votes:
            return "Democrats"
        else:
            return "Republicans"

# takes the total number of dem votes and total number of gop
# votes as parameters and calculates and returns the
# total wasted dem votes and total wasted gop votes
def calculate_wastage(dem, gop):
    half_votes = (dem + gop) // 2
    if dem > gop:
        wasted_gop_votes = gop
        wasted_dem_votes = (dem - (half_votes + 1))
        return [wasted_dem_votes, wasted_gop_votes]
    else:
        wasted_dem_votes = dem
        wasted_gop_votes = (gop - (half_votes + 1))
        return [wasted_dem_votes, wasted_gop_votes]

    ##########################################

main()