import turtle
import keyboard

def main():
    turtle.Screen()
    turtle.setup(width=500, height=500)
    turtle.shape("turtle")
    turtle.color("black")
    turtle.home = turtle.Screen()

    play_game()


def play_game():
    while True:
        if keyboard.is_pressed("w"):
            turtle.setheading(90)
            
        if keyboard.is_pressed("a"):
            turtle.setheading(180)

        if keyboard.is_pressed("s"):
            turtle.setheading(270)

        if keyboard.is_pressed("d"):
            turtle.setheading(0)

main()