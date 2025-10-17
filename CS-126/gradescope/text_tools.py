# Create a constant for all the vowels we're checking for
VOWELS = "aeiou"

# define the is vowel function that accepts one parameter
def is_vowel( string ):
    # lowercase the string we passed through
    string = string.lower()
    # check if the first letter of the string is in the vowels string
    if string[0] in VOWELS:
        # we return true if it is a vowel
        return True
    # if the statement return false run this code
    else:
        # we return false if it is not a vowel
        return False