# Write a function named random_walk that simulates a 1-dimensional "random walk" algorithm. A random walk is where an integer value is repeatedly increased or decreased by 1 randomly many times until it hits some threshold. Your function should accept the integer threshold as a parameter, then start an integer at 0 and adjust it by +1 or -1 repeatedly until its value reaches positive or negative threshold. For example, if the call of random_walk(3) is made, your function would randomly walk until it hits 3 or -3. Each time the value is adjusted, it is printed in the format shown. When you have reached the threshold, report the number of steps that were taken from the starting poof 0, as well as the maximum position that was reached during the walk. (If the walk ever reaches positive threshold, that is the maximum position.)

# The log below shows the output from an example call of random_walk(3) . You should match the output format below exactly, though the numbers are randomly generated. Use random or randint to give an equal chance of moving by +1 and -1 on each step. If the threshold parameter passed to your function is not greater than 0, your function should produce no output.

# Position = 0
# Position = 1
# Position = 0
# Position = -1
# Position = -2
# Position = -1
# Position = -2
# Position = -3
# Finished after 7 step(s)
# Max position = 1
# (Because this problem uses random numbers, our test cases check only the general format of your output. You must still examine the output yourself to make sure the answer is correct.)

import random

def random_walk( threshold ):
    steps = 0
    step_array = [0]
    position = 0
    while position != threshold and position != -threshold:
        print(f"Position = {position}")
        step_direction = random.randint(0, 1)
        if step_direction == 0:
            position -= 1
        else:
            position += 1
        steps += 1
        step_array.append(position)
    
    print(f"Position = {position}")
    print(f"Finished after {steps} steps(s)")

    step_array.sort()
    max_position = step_array[-1]

    print(f"Max position = {max_position}")

# random_walk(3)

# Write a function named smallest_largest that asks the user to enter numbers, then prints the smallest and largest of all the numbers typed in by the user. You may assume the user enters a valid number greater than 0 for the number of numbers to read. Here is an example dialogue:

# How many numbers do you want to enter? 4
# Number 1: 5
# Number 2: 11
# Number 3: -2
# Number 4: 3
# Smallest = -2
# Largest = 11

def smallest_largest():
    number_of_numbers = int(input("How many numbers do you want to enter? "))
    num_array = []

    for number_count in range(1, number_of_numbers + 1):
        number_value = int(input(f"Number {number_count}: "))
        num_array.append(number_value)
    
    num_array.sort()
    print("Smallest =", num_array[0])
    print("Largest =", num_array[-1])

# smallest_largest()