# Write a function named symmetric_set_difference that accepts two sets as parameters and returns a new set containing their symmetric set difference (that is, the set of elements contained in either of the two sets but not in both). For example, the symmetric difference between the sets {1, 4, 7, 9} and {2, 4, 5, 6, 7} is {1, 2, 5, 6, 9}. Do not call the set's symmetric_difference function in your solution.

# def symmetric_set_difference( set_1, set_2 ):
def symmetric_set_difference( set_1, set_2 ):
    result = set()
    
    for item in set_1:
        if item not in set_2:
            result.add(item)
    
    for item in set_2:
        if item not in set_1:
            result.add(item)
    
    return result


            

# print(symmetric_set_difference({1, 4, 7, 9}, {2, 4, 5, 6, 7}))

data = set()
data.add(74)
data.add(12)
data.add(18274)
data.add(9074)
data.add(43)
data.remove(74)
data.remove(43)
data.add(32)
data.add(18212)
data.add(9)
data.add(29999)
print(data)