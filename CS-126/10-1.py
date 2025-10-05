# lists are mutable

# my_list = [10, 50, "string", 2.1, "bob"]

# data_stream = open("data.txt")
# data_stream.close()

# file_location = r"C:\\Users\\marqu\Documents\data.txt"
# with open(file_location) as data_stream:
#     data = data_stream.read()

# print(data)

# with open('new_data.txt', mode = 'w') as data_stream:
#     data_stream.write("hello good sir today")

def main():
    
    filename = "weather.txt"
    differences = []

    with open(filename) as weather_data:
        numbers_string = weather_data.read()

    list_of_string_numbers = numbers_string.split()

    for current_element_index in range(0, len(list_of_string_numbers) - 1):
        current_element = float(list_of_string_numbers[current_element_index])
        next_element = float(list_of_string_numbers[current_element_index + 1])

        differences.append(next_element - current_element)


    print(differences)

main()