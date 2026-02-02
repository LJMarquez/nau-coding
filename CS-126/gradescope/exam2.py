def chewie(word):
    word = word.lower()
    pair_list = []
    word_length = len(word)
    if word_length > 2:
        for letter_index in range(word_length):
            pair = word[letter_index:(letter_index+2)]
            if len(pair) == 2:
                pair_list.append(pair)
    return pair_list

def pair_frequencies(word_list):
    pair_count_set = {}
    for word in word_list:
        pair_list = chewie(word)
        for pair in pair_list:
            if pair in pair_count_set:
                pair_count_set[pair] += 1
            else:
                pair_count_set[pair] = 1
    pair_keys = list(pair_count_set.keys())
    pair_values = list(pair_count_set.values())

    for key_index in range(len(pair_keys)):
        print(f"{pair_keys[key_index]}: {pair_values[key_index]}")

#    return pair_count_set