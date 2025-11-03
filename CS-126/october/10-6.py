VOWELS = "aeiou"

def is_vowel( string ):
    if string:
        return string[0].lower() in list(VOWELS)
    else:
        return False

# print(is_vowel(""))
# print(is_vowel("test"))
# print(is_vowel("apple"))

def mystery(x, a):
    x = x * 2
    if x > 6:
        a[2] = 14
        a[1] = 9
    else:
        a[0] = 9
        a[3] = 14
    print(x, a)

def list_mystery2(a):
    for i in range(1, len(a) - 1):
        a[i] = a[i - 1] - a[i] + a[i + 1]

a5 = [6, 0, -1, 3, 5, 0, -3]
list_mystery2(a5)
print(a5)

# Write a function is_palindrome that accepts a list of strings as its argument and returns True if that list is a palindrome (if it reads the same forwards as backwards) and False if not. For example, the list ["alpha", "beta", "gamma", "delta", "gamma", "beta", "alpha"] is a palindrome, so passing that list to your function would return True. Lists with zero or one element are considered to be palindromes.

def is_palindrome(lst):
    return lst == lst[::-1]