# a program that reads in a data file with movie reviews,
# based on feedback calculates a numerical score for each word in text
# and provides user to provide a word and give back numeric score

def main():
    # Initialize variables
    training_data_file_name = "training.txt"
    
    # Get input
        # Open data file connection
    with open(training_data_file_name) as file_object:
        # Read in the data as a list of lines
            # function: <file>.readlines()
        list_of_lines = file_object.readlines()

    # Process data
        # Train the model
            # function: train(list_of_lines)
        trained_model = train(list_of_lines)
    
    # Provide results
        # Run user interface
            # function: display_menu(trained_model)
        display_menu(trained_model)
    
def train(list_of_lines):
    # Initialize variables
    score_dict = {}
    total_score_dict = {}
    count_dict = {}

    # Process data

    # Loop over each line
    for line in list_of_lines:
        # Split the line into list of elements
        list_of_elements = line.split()
        # pop first element and store it as a score
        score = int(list_of_elements.pop(0))
        # Loop over words
        for word in list_of_elements:
            # Check if not word in either dictionary
            if not word in total_score_dict:
                # add word to count dictionary
                count_dict[word] = 1
                # add word to total score dictionary with a given score
                total_score_dict[word] = score
            # Otherwise
            else:
                # Update count dictionary
                count_dict[word] += 1
                # Update score dictionary
                total_score_dict[word] += score

    # Loop over all words
    for word, count in count_dict.items():
        total_score = total_score_dict[word]
        # Calculate final sentiment score for each word
        average_score = total_score / count
        # Store final score the dictionary
        score_dict[word] = average_score

    return score_dict

def display_menu(traind_model):
    # Initialize variables
    sentinel = "q"
    input_prompt = f"Provide a word (or \'{sentinel}\' to exit): "
    user_input = input(input_prompt)

    while user_input != sentinel:
        if user_input in traind_model:
            score = traind_model[user_input]
            print(f"Word \'{user_input}\' has sentiment value of {score}")
        else:
            print("Such a word is beyond my scope of training...")
        user_input = input(input_prompt)
    
    print("Machines will take over, HF")
    print()

main()