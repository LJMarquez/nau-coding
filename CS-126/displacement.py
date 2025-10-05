# define displacement function
    # parameters: velocity, acc, time
def displacement(velocity, acc, time):
    # calculate displacement
        # formula: velocity * time + 1/2 * acc * time^2
    return velocity * time + (acc/2) * time ** 2

