# I am sure that a certain value is in a list
# List size is 5
# [*,*,*,*,*]
# On average how many checks need to happen to find value inside that list?
# Length == n
# Hypothesis is that:
# n/2 or (n+1)/2

import random

def generate_random_list(start, stop, size):
    range_size = stop - start
    if size > range_size:
        print(f"Not proper size, setting it to maximum possible {range_size}")
        size = range_size

    generated_set = set()
    while len(generated_set) < size:
        random_number = random.randint(start, stop)
        generated_set.add(random_number)

    return list(generated_set)

# Brute force method
def testing_complexity(start, stop, size, n_shuffles):
    # n_shuffles = 10000
    n_total_checks = 0

# generate a list which for sure contains a value
    random_list = generate_random_list(start,stop,size)

# choose one value to search for
    chosen_one = random.choice(random_list)
    print(chosen_one)

# for MANY... many... many TIMES
    for _ in range(n_shuffles):
        shuffle(random_list)
    # find a value in that list while tracking how many comparisons were done
        # n_checks = random_list.index(chosen_one) + 1
        n_checks = index(random_list, chosen_one) + 1
        n_total_checks += n_checks
    
    print(f"Average n checks equal to: {n_total_checks/n_shuffles}")
    print(f"Expected value is either {size/2} or {(size + 1) / 2}")

# provides index of value inside the list
def index(data_list, value_to_find):
    data_size = len(data_list)
    index = 0
    while data_list[index] != value_to_find and index != data_size:
        index += 1
        
    if index == data_size:
        return -1
    return index

    # for index, value in enumerate(data_list):
    #     if value == value_to_find:
    #         return index

    # return -1


def shuffle(data_list):
    list_size = len(data_list)
    for _ in range(list_size**2):
        data_list.append(data_list.pop(random.randint(0, list_size -1)))
    
def random_sort(data):
    counter = 0
    while not_sorted(data):
        counter += 1
        print(data)
        shuffle(data)
    print(counter)

def not_sorted(data):
    index = 0
    data_len = len(data)
    if data_len > 1:
        while index < data_len - 1:
            current_value = data[index]
            next_value = data[index + 1]
            if current_value > next_value:
                return True
            index += 1
    else:
        return False

# main()
# testing_complexity(1,5,5,10)
testing_complexity(10,20,6,1000)