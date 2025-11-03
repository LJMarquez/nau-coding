import turtle
import keyboard
import sys

SPEED = 2

def main():
    screen_width = 1000
    screen_height = 1000
    if len(sys.argv) > 1:
        screen_width = int(sys.argv[1])
        if len(sys.argv) > 2:
            screen_height = int(sys.argv[2])

    turtle.Screen()
    turtle.setup(width=screen_width, height=screen_height)
    turtle.shape("turtle")
    turtle.color("black")
    turtle.home = turtle.Screen()
    turtle.penup()

    play_game(screen_width, screen_height)


def play_game(screen_width, screen_height):
    key_pressed = False
    is_pen_down = False
    while not keyboard.is_pressed("q"):
        if keyboard.is_pressed("w"):
            turtle.setheading(90)
            key_pressed = True
            
        if keyboard.is_pressed("a"):
            turtle.setheading(180)
            key_pressed = True

        if keyboard.is_pressed("s"):
            turtle.setheading(270)
            key_pressed = True

        if keyboard.is_pressed("d"):
            turtle.setheading(0)
            key_pressed = True

        if keyboard.is_pressed("p"):
            if is_pen_down:
                turtle.penup()
                is_pen_down = False
            else:
                turtle.pendown()
                is_pen_down = True

        if key_pressed:
            turtle.forward(SPEED)
        
        if turtle.xcor() > screen_width / 2:
            turtle.speed(0)
            turtle.penup()
            turtle.goto(screen_width/-2, turtle.ycor())
            if is_pen_down:
                turtle.pendown()
        if turtle.xcor() < screen_width / -2:
            turtle.speed(0)
            turtle.penup()
            turtle.goto(screen_width/2, turtle.ycor())
            if is_pen_down:
                turtle.pendown()

        if turtle.ycor() > screen_height / 2:
            turtle.speed(0)
            turtle.penup()
            turtle.goto(turtle.xcor(), screen_height/-2)
            if is_pen_down:
                turtle.pendown()
        if turtle.ycor() < screen_height / -2:
            turtle.speed(0)
            turtle.penup()
            turtle.goto(turtle.xcor(), screen_height/2)
            if is_pen_down:
                turtle.pendown()

main()