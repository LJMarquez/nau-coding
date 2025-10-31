import turtle

def main():
    # set up turtle environment
    turtle.setworldcoordinates(0, 600, 600, 0)
    turtle.clear()
    turtle.speed(0)
    turtle.bgcolor('blue2')
    turtle.pencolor('black')
    turtle.fillcolor('white')
    turtle.penup()

    # Draw the ground
    turtle.goto(0, 0)
    turtle.goto(0, 500)
    turtle.begin_fill()
    turtle.pendown()
    turtle.goto(600, 500)
    turtle.goto(600, 600)
    turtle.goto(-10, 600)
    turtle.goto(-10, 500)
    turtle.goto(300, 500)
    turtle.end_fill()
    turtle.penup()

    # Draw first circle
    turtle.left(180)
    turtle.pendown()
    turtle.begin_fill()
    turtle.circle(70)
    turtle.end_fill()
    turtle.penup()

    # Draw second circle
    turtle.goto(300, 360)
    turtle.pendown()
    turtle.begin_fill()
    turtle.circle(60)
    turtle.end_fill()
    turtle.penup()

    # Draw third circle
    turtle.goto(300, 240)
    turtle.pendown()
    turtle.begin_fill()
    turtle.circle(50)
    turtle.end_fill()
    turtle.penup()

    # Draw bottom of hat
    turtle.goto(300, 140)
    turtle.fillcolor('black')
    turtle.pendown()
    turtle.begin_fill()
    turtle.goto(250, 140)
    turtle.goto(250, 120)
    turtle.goto(350, 120)
    turtle.goto(350, 140)
    turtle.goto(350, 140)
    turtle.end_fill()
    turtle.penup()

    # Draw top of hat
    turtle.goto(280, 120)
    turtle.pendown()
    turtle.begin_fill()
    turtle.goto(280, 60)
    turtle.goto(320, 60)
    turtle.goto(320, 125)
    turtle.goto(280, 125)
    turtle.goto(300, 125)
    turtle.end_fill()
    turtle.penup()

    # Draw nose
    turtle.goto(280, 200)
    turtle.fillcolor('orange')
    turtle.pendown()
    turtle.begin_fill()
    turtle.goto(350, 190)
    turtle.goto(280, 180)
    turtle.goto(280, 200)
    turtle.end_fill()
    turtle.penup()

    turtle.hideturtle()


if __name__ == "__main__":
    main()
    turtle.done() 