# Write a function named get_majority_last_name that accepts as its parameter a dictionary from strings to strings the keys of the dictionary represent first names and the values represent last names. If there is a single common last name that is present in more than half of the key/value pairs in the dictionary passed in (a "majority" last name), your function should return that last name. If there is no majority last name, your function should return the string "?" .

# For example, if the dictionary contains the following key/value pairs, the majority last name is "Smith" because it occurs 5 times, which is more than half of the nine pairs in the dictionary. Therefore your function would return "Smith".

# {'Hal': 'Perkins', 'Mark': 'Smith', 'Mike': 'Smith', 'Stuart': 'Reges', 'David': 'Smith',
#  'Jean': 'Reges', 'Geneva': 'Smith', 'Amie': 'Smith', 'Bruce': 'Reges'}
# The following dictionaries don't have any majority last name because no last name occurs strictly greater than half the time. Therefore when passed either of the dictionaries below, your function would return "?" .

# {'Marty': 'Stepp', 'Mehran': 'Sahami', 'Keith': 'Schwarz', 'Cynthia': 'Lee', 'Yogurt': 'Schwarz',
#  'Tywin': 'Lannister', 'Rob': 'Stark', 'Sansa': 'Stark', 'Tyrion': 'Lannister'}
# If the dictionary that contains only one key/value pair, that pair's value is the majority last name. An empty dictionary does not have any majority last name.

# Constraints: You may declare at most one auxiliary collection to help you solve this problem. Do not modify the map that is passed in to your function as a parameter.

def get_majority_last_name( dict ):
    if len(dict) == 0:
        return "?"

    name_count_dict = {}
    for name in dict:
        last_name = dict[name]
        if last_name not in name_count_dict:
            name_count_dict[last_name] = 1
        else:
            name_count_dict[last_name] = name_count_dict[last_name] + 1

    name_counts = list(name_count_dict.values())
    max_value = max(name_counts)

    if name_counts.count(max_value) > 1:
        return "?"
    else:
        name_list = list(name_count_dict.keys())
        majority_name_index = name_counts.index(max_value)
        majority_name = name_list[majority_name_index]
        return majority_name
            

import keyboard
import turtle

def main():
    player_turtle = turtle.Turtle()
    player_turtle.color("purple")
    player_turtle.shape("turtle")
    player_turtle.shapesize(3)

    player_turtle.home = turtle.Screen()
    player_turtle.home.bgcolor("darkseagreen")
    player_turtle.penup()
    
    play_game(player_turtle)


def play_game(player):
    # count = 0
    key_map = {
        "UP":"w",
        "DOWN":"s",
        "LEFT":"a",
        "RIGHT":"d",
        "EXIT": "q"
    }
    directions = {
        "UP":90,
        "DOWN":270,
        "LEFT":180,
        "RIGHT":0,
        "EXIT": "q"
    }
    x_pos = turtle.xcor()
    y_pos = turtle.ycor()
    speed = 10
    
    while not keyboard.is_pressed("q"):
        # print("I'm listening to your command")
        # count += 1
        # print(count)

        if keyboard.is_pressed(key_map["RIGHT"]) and keyboard.is_pressed(key_map["UP"]):
            print("Going RIGHT-UP")

        if keyboard.is_pressed(key_map['UP']):
            print("Going UP")
            # y_pos += speed
            player.setheading(directions["UP"])
            player.forward(speed)
            # player.goto(x_pos,y_pos + speed)

        if keyboard.is_pressed(key_map['DOWN']):
            print("Going DOWN")
            # y_pos -= speed
            player.setheading(directions["DOWN"])
            player.forward(speed)
            # player.goto(x_pos,y_pos - speed)

        if keyboard.is_pressed(key_map['LEFT']):
            print("Going LEFT")
            # x_pos -= speed
            player.setheading(directions["LEFT"])
            player.forward(speed)
            # player.goto(x_pos - speed,y_pos)

        if keyboard.is_pressed(key_map['RIGHT']):
            print("Going RIGHT")
            # x_pos += speed
            player.setheading(directions["RIGHT"])
            player.forward(speed)
            # player.goto(x_pos + speed,y_pos)

main()