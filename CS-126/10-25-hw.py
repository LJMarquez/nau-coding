def username_count():
    username_dict = {}
    user_input = input("Enter name: ")

    while user_input != "":
        if user_input not in username_dict:
            username_dict[user_input] = 1 
        else:
            username_dict[user_input] = username_dict[user_input] + 1 
        user_input = input("Enter name: ")
        
    for user in username_dict:
        print(f"Entry [{user}] has count {username_dict[user]}")

def is_unique( dict ):
    unique_word_list = []
    for item in dict:
        if dict[item] not in unique_word_list:
            unique_word_list.append(dict[item])
        else:
            return False
    return True

def collection_mystery3(q):
    s = []
    size = len(q)
    for i in range(size):
        n = q.pop(0)
        if n % 2 == 0:
            s.append(n)
        else:
            q.append(n)
    print("q=" + str(q))
    print("s=" + str(s))

collection_mystery3([30, 20, 10, 60, 50, 40, 3, 0])