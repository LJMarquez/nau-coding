# a function which accepts a string and a list of characters
# proceeds to split string on all characters mentioned in
# the list, returns back a list of words from the original
# string without discarded characters

def super_split( string, delimiters_list ):
    splitted_string_list = []
    string_len = len(string)
    start = 0

    for letter_index in range(0, string_len):
        character = string[letter_index]
        if character in delimiters_list:
            sliced_string = string(start:letter_index)
            splitted_string_list.append(sliced_string)
            start = letter_index + 1

        # start = start + 1
        print(start)
        print(string_len)