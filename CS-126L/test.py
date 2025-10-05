# import turtle library
# import lab 2 functions module
# declare and initialize MORTAR constant

# define main function
    # set up window for the turtle graphics to 400 by 650
    # set background color to grey

    # define draw row function with parameters for starting x and y, number of pairs of squares, and square size
        # make turtle go to starting point
        # declare a for loop that repeats for the number of times of the pairs parameter we passed through
            # use the lab functions module and call the draw square function to draw a black square using the parameters for the x and y location as well as size
            # use the lab functions module and call the draw line function to draw a blue line using the parameters for the x and y location as well as size
            # use the lab functions module and call the draw line function to draw the other blue line using the parameters for the x and y location as well as size
            # use the lab functions module and call the draw square function to draw a white square using the parameters for the x and y location as well as size

    # define a draw grid function with the parameters for starting x and y, the number of rows in the grid, the length of each row within the grid, the size of the boxes in the rows, and the offset
        # declare a for loop that repeats for the number of times of the pairs parameter we passed through
            # add the mortar to the starting y every time a new row is created
            # add the offset for every other row in the grid using an if statement
            # call the draw row function we defined earlier and pass through the variables
    
    # call the draw row function to draw the upper left row

    # call the draw row function to draw the mid left row

    # call the draw grid function to draw the lower left grid

    # call the draw grid function to draw the lower middle grid

    # call the draw grid function to draw the lower right grid

    # call the draw grid function to draw the upper right grid

    # hide the turtle when we're done

# call the main function