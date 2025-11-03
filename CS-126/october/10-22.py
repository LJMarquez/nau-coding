my_dict = {}
my_dict[0] = 10
my_dict[1] = 20
my_dict["lol"] = 420

# print(my_dict)
# print(my_dict.keys())

def collection_mystery1(map):
    result = {}
    for k in map.keys():
        v = map[k]
        if k[0] <= v[0]:
            result[k] = v
        else:
            result[v] = k
    print(result)

collection_mystery1({'skate': 'board', 'drive': 'car', 'program': 'computer', 'play': 'computer'})