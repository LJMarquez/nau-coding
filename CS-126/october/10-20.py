# A function which reads a book, keeps track of vocabulary
# provides back a count of all unique words and total words count

# Input example of text:
# "This text has more than one word of a same kind. Actually
#  this text has quite a few repeats"

# Output example:
# There are 19 words total and 15 unique words

def word_counter( filename ):
    # unique_words_list = []
    total_words = 0
    unique_words = 0
    # unique_words_set = set()
    unique_words_dict = {}

    with open(filename, encoding="utf-8") as data_stream:
        raw_text = data_stream.read()

    sanitized_text = sanitize(raw_text)
    print(sanitized_text)
    all_words_list = sanitized_text.split()

    for word in all_words_list:
        word = word.lower()
        # # if not word in unique_words_list:
        # if not word in unique_words_set:
        #     # unique_words_list.append(word)
        #     unique_words_set.add(word)
        
        if not word in unique_words_dict:
            unique_words_dict[word] = 1
        else:
            unique_words_dict[word] += 1
    
    # unique_words = len(unique_words_set)
    unique_words = len(unique_words_dict)
    total_words = len(all_words_list)
    
    print(f"There are {total_words} words total", end=" ")
    print(f"and {unique_words} unique words")

    return unique_words_dict

# word_counter("moby_dick.txt")

def sanitize( string ):
    # new_string = ""
    sanitized_string_list = []

    for letter_index in range(len(string)):
        letter = string[letter_index]
        # letter.isalpha()
        if "a" <= letter.lower() <= "z" or letter in [" ", "\n"]:
            # new_string += letter
            sanitized_string_list.append(letter)

    return "".join(sanitized_string_list)

def main():
    sentinel = 'q'
    input_prompt = f"Provide a word or {sentinel} to exit: "

    results_dict = word_counter("moby_dick.txt")
    
    user_input = input(input_prompt)
    while user_input != sentinel:
        count = results_dict[user_input]
        print(f"There are a total of {count} occurrences of the word {user_input}")
        user_input = input(input_prompt)

main()