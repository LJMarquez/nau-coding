# Takes two sides of a right traingle and finds the hypotenuse

def get_hypotenuse( side_a, side_b ):
# Precess Data Block
    # Calculate hypotenuse squared
    side_c_sqrd = side_a * side_a + side_b * side_b

    # Calculate final hypotenuse
    side_c = side_c_sqrd**0.5
    # ** is how you raise something to an exponent

# Display Data Block
    #Display hypotenuse
    print( side_c );
    
