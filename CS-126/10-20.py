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
    unique_words_set = set()

    with open(filename, encoding="utf-8") as data_stream:
        raw_text = data_stream.read()

    all_words_list = raw_text.split()

    for word in all_words_list:
        word = word.lower()
        # if not word in unique_words_list:
        if not word in unique_words_set:
            # unique_words_list.append(word)
            unique_words_set.add(word)
    
    unique_words = len(unique_words_set)
    total_words = len(all_words_list)
    
    print(f"There are {total_words} words total", end=" ")
    print(f"and {unique_words} unique words")

word_counter("moby_dick.txt")