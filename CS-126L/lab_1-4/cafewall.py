import turtle
import Lab2_functions # Import your custom module
# set mortar joints between rows
MORTAR = 2

def main():
    turtle.setworldcoordinates(0, 400, 650, 0)
    turtle.clear()
    turtle.shape('turtle')
    turtle.bgcolor('grey')

    turtle.speed(0)

    #### YOUR CODE GOES HERE #################
    # Example usage of a function from the Lab2_functions module

    def draw_row( starting_x, starting_y, number_of_pairs, size ):
        turtle.goto(starting_x, starting_y)
        turtle.setheading(0)
        turtle.backward(size)
        for box in range(number_of_pairs):
            Lab2_functions.draw_rect(turtle.xcor() + size, starting_y, size, size, 'black')
            Lab2_functions.draw_line(turtle.xcor(), starting_y, turtle.xcor() + size, turtle.ycor() + size, 'medium blue')
            Lab2_functions.draw_line(turtle.xcor(), starting_y, turtle.xcor() - size, turtle.ycor(), 'medium blue')
            Lab2_functions.draw_rect(turtle.xcor() + size, starting_y, size, size, 'white')

    def draw_grid( starting_x, starting_y, row_count, row_length, box_size, offset ):
        for row in range(row_count):
            row_counter = row + 1
            row_starting_x = starting_x
            row_starting_y = starting_y + (row * (box_size + MORTAR))
            if row_counter % 2 == 0:
                row_starting_x = starting_x + offset
            draw_row( row_starting_x, row_starting_y, row_length, box_size)

    turtle.penup()

    draw_row(0, 0, 4, 20)

    draw_row(50, 70, 5, 30)

    draw_grid(10, 150, 8, 4, 25, 0)

    draw_grid(250, 200, 6, 3, 25, 10)

    draw_grid(425, 180, 10, 5, 20, 10)

    draw_grid(400, 20, 4, 2, 35, 35)

    turtle.hideturtle()

    ##########################################

if __name__ == "__main__":
    main()
    turtle.done() # Finish drawing (optional)
