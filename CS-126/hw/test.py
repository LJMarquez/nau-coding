def print_meows( meow_count ):
    print("Here are", meow_count, "meows:")
    print("meow\t" * int(meow_count));

# print_meows(5)

def test(string):
    new_string = ""
    for i in range(len(string)):
        letter = string[i]
        if letter == "A":
            new_string += "T"
        elif letter == "T":
            new_string += "A"
        elif letter == "G":
            new_string += "C"
        elif letter == "C":
            new_string += "G"
        else:
            new_string += letter
    print(new_string)

# test("GCATGGATTAATA-GAGACGACTAATAGGATAGTTACAACCCTT-CGTCACCGCCTTGA")

def reverse_word_order(s):
    word_list = s.split()
    print(word_list)
    word_list.reverse()
    print(word_list)

# reverse_word_order("hi, how are you!")

obj = {'two': 'deux', 'five': 'cinq', 'one': 'un', 'three': 'trois', 'four': 'quatre'}

print(obj[1])
