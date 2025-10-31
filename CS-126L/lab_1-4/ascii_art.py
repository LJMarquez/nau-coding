# print ears and top of head function
def print_top_of_head():
    # use a for loop for the space between top of body and ears
    for space in range(16):
        print(" ", end="");
    # use print function to print first ear
    print("[)", end="");
    # use a for loop to print the top of the head
    for space in range(5):
        print("_", end="");
    # use a print function to print the second ear
    print("(]");
# print top of body and face function
def print_head_and_body():
    # print function to print out the body
    print(" " * 4 + "_" * 12, end="");
    # use print function to print the face
    print("( ° • ° )");
# print body function
def print_body():
    # use a print function to print the bottom of the body
    print("`~-(" + "_" * 12 + ")", end="");
    # use print function to print the collar
    print("/" + "=" * 6);
# print legs function
def print_legs():
    # use a print function to print the first leg
    print(" " * 4 + "/_", end="");
    # use a print function to print the spaces between the legs
    print(" " * 10, end="");
    # use a print function to print the second leg
    print("\\_");

# define main function
def main():
    # call print ears function
    print_top_of_head();
    # call print head function
    print_head_and_body();
    # call print body function
    print_body();
    # call print legs function
    print_legs();

# call main function
main();
