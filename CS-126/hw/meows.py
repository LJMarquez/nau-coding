def main():
    preffered_num_of_meows = 3;
    too_many_meows = 15;
    
    print("This is the preffered number of meows");
    print_meows(preffered_num_of_meows);
    print("\n"*1, "This is too many meows", sep="");
    print_meows(too_many_meows);
    
def print_meows( meow_count ):
    print("Here are", meow_count, "meows:")
    print("meow\t" * int(meow_count));

main();