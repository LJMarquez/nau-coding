# my_list = ["text", 2, [3, 4, 5]]

# print(my_list[2][1])
# print(my_list[0][1:3])

# tuple is like a list but immutable
my_tuple = (10, 20, 30, 40)
# print(my_tuple[0:2])

def most_frequent_digit( number ):
    tally_list = [0] * 10
    stringified_number = str(number)
    for value in stringified_number:
        tally_list[int(value)] += 1

    number_count = max(tally_list)
    most_frequent_number = tally_list.index(number_count)

    return ( most_frequent_number, number_count )

# print(most_frequent_digit(32578323822))

def most_frequent_letter( string ):
    tally_list = [0] * 4
    key = "AGCT"

    for value in string:
        letter_index = key.index(value)
        tally_list[letter_index] += 1

    letter_count = max(tally_list)
    most_frequent_letter = key[tally_list.index(letter_count)]

    return ( most_frequent_letter, letter_count )

print(most_frequent_letter("AAGTCACAA"))