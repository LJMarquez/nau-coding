# Write a function named banish that accepts two lists of integers a1 and a2 as parameters and removes all occurrences of a2's values from a1. An element is "removed" by shifting all subsequent elements one index to the left to cover it up, placing a 0 into the last index. The original relative ordering of a1's elements should be retained.

# For example, suppose the following two lists are declared and the following call is made:

# a1 = [42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1]
# a2 = [42, 2222, 9]
# banish(a1, a2)
# After the call has finished, the contents of a1 should become:

# [3, 0, 17, 8, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# Notice that all occurrences of the values 42, 2222, and 9 have been removed and replaced by 0s at the end of the list, and the remaining values have shifted left to compensate.

# Do not make any assumptions about the length of the lists or the ranges of values each might contain. For example, each list might contain no elements or just one element, or very many elements. (If a2 is an empty list that contains no elements, a1 should not be modified by the call to your function.) You may assume that the lists passed are not None. You may assume that the values stored in a2 are unique and that a2 does not contain the value 0.

# You may not use any temporary lists to help you solve this problem. (But you may declare as many simple variables as you like, such as ints.) You also may not use any other data structures or complex types such as Strings, or other data structures such as the list class.

def banish(a1, a2):
    list_len = len(a1)
    count = 0
    while count < list_len - 1:
        if a1[count] in a2:
            print(a1.pop(count))
            a1.append(0)
            count -= 1
        count += 1

# a1 = [42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1]
a1 = [42, 3, 9, 42, 42, 8]
a2 = [42, 2222, 9]
banish(a1, a2)
print(a1)

# a1 = [42, 3, 9, 42, 42, 8]
# 0 [42, 3, 9, 42, 42, 8] => [3, 9, 42, 42, 8, 0]
# 0 [3, 9, 42, 42, 8, 0] => [3, 9, 42, 42, 8, 0]
# 1 [3, 9, 42, 42, 8, 0] => [3, 42, 42, 8, 0, 0]
# 1 [3, 42, 42, 8, 0, 0] => [3, 42, 8, 0, 0, 0]
# 1 [3, 42, 8, 0, 0, 0] => [3, 8, 0, 0, 0, 0]
# 1 [3, 8, 0, 0, 0, 0] => [3, 8, 0, 0, 0, 0]
# 2 [3, 8, 0, 0, 0, 0] => [3, 8, 0, 0, 0, 0]
# 3 [3, 8, 0, 0, 0, 0] => [3, 8, 0, 0, 0, 0]
# 4 [3, 8, 0, 0, 0, 0] => [3, 8, 0, 0, 0, 0]
# 5 [3, 8, 0, 0, 0, 0] => [3, 8, 0, 0, 0, 0]