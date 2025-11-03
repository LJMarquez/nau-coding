my_string = "Dragon ate a table"
# print(my_string.find("ate"))
# print(my_string.find("test"))
# print(my_string[7:10])
# print(my_string[10:])

# def calculate_total():
#     patrons = int(input("How many people ate today? "))
#     total_cost = 0

#     for patron in range(patrons):
#         current_cost = float(input("How much did you spend today? $"))
#         total_cost += current_cost
#     print(f"Your total group cost is: ${total_cost}")

# calculate_total()

# import random
# print(random.seed(100))
# print(random.randint(1, 10))
# print(random.randint(1, 10))
# print(random.randint(1, 10))

# print(int(100 * random.random() // 1))

# def number_to_letter_grade(score):
#     if score >= 90:
#         return "A"
#     elif score >= 80:
#         return "B"
#     elif score >= 70:
#         return "C"
#     elif score >= 60:
#         return "D"
#     else:
#         return "F"

# def main():
#     score = float(input("Enter your score: "))
#     letter_grade = number_to_letter_grade(score)
#     print(f"Your letter grade is: {letter_grade}")

# main()

# import turtle
# import random
# odin = turtle.Turtle()
# odin.shape("turtle")
# odin.color("pink")

# loki = turtle.Turtle()
# loki.shape("square")
# loki.stamp()
# loki.goto(-50, -50)

# odin.goto(50, 0)
# odin.circle(random.randint(10, 100))

# turtle.done()

import turtle
import random

def main():
    odin = turtle.Turtle()
    odin.color("darkred")

    move_turtle(odin)

def move_turtle(a_turtle):
    speed = random.randint(0, 100)
    number_of_moves = 10000000000

    for current_move in range(number_of_moves):
        user_input = input("Where to move? ")
        user_input = user_input.upper()
        if user_input == "W":
            a_turtle.goto(a_turtle.xcor(), a_turtle.ycor() + speed)
        elif user_input == "S":
            a_turtle.goto(a_turtle.xcor(), a_turtle.ycor() - speed)
        elif user_input == "A":
            a_turtle.goto(a_turtle.xcor() - speed, a_turtle.ycor())
        elif user_input == "D":
            a_turtle.goto(a_turtle.xcor() + speed, a_turtle.ycor())
        else:
            print("Invalid input, please use W, A, S, or D to move.")

    turtle.done()
    
main()