# Building Python Programs
# Programming Assignment Chapter 4 Gradanator Template
#
# Calculates a student's course grade based on exam and homework scores.

ATTENDANCE_PTS = 3 # points earned per section
SECTION_MAX = 34 # maximum possible section points

def main():
    print_intro()
    midterm_score = get_exam_score("Midterm 1")
    midterm_score2 = get_exam_score("Midterm 2")
    final_score = get_exam_score("Final")
    hw_score = get_homework_score()
    # quizzes = get_quizzes_or_homework_score("Quizzes")
    # daily_hw = get_quizzes_or_homework_score("Daily homework")
    # report_grade(midterm_score + midterm_score2 + final_score + hw_score + quizzes + daily_hw)
    report_grade(midterm_score + midterm_score2 + final_score + hw_score)

# Prints information about the program's behavior.
def print_intro():
    print("This program reads exam/homework scores")
    print("and reports your overall course grade.")
    print()

# Prompts for exam score and shift. Returns a weighted
# score.
def get_exam_score(exam):

    # YOUR CODE here

    print(f"{exam}:")
    weight = 101
    while weight < 0 or weight > 100:
        weight = float(input("Weight (0-100)? "))
        if weight < 0 or weight > 100:
            print("Please enter a number between 0-100")
    weight = round(weight, 1)

    score = 101
    while score < 0 or score > 100:
        score = float(input("Score earned? "))
        if score < 0 or score > 100:
            print("Please enter a score between 0-100")
    score = round(score, 1)


    shift = int(input("Were scores shifted (1=yes, 2=no)? "))
    if shift == 1:
            shift = 101
            while shift < 0 or shift > 100:
                shift = int(input("Shift amount? "))
                if shift < 0 or shift > 100:
                    print("Please enter a shift between 0-100")
                else:
                    score += shift
    if score > 100:
        score = 100

    print(f"Total points = {score} / 100")

    return get_weighted_score(score, 100, weight)

# Prompts for homework scores and section attendance. Calculates and returns
# weighted homework score.
def get_homework_score():
    # YOUR CODE here

    print("Homework:")

    weight = 101
    while weight < 0 or weight > 100:
        weight = float(input("Weight (0-100)? "))
        if weight < 0 or weight > 100:
            print("Please enter a number between 0-100")
    weight = round(weight, 1)

    num_of_assignments = int(input("Number of assignments? "))

    hw_earned = 0
    hw_total = 0

    for assignment in range(1, num_of_assignments + 1):
        assignment_score = float(input(f"Assignment {assignment} score? "))
        hw_earned += assignment_score
        assignment_max = int(input(f"Assignment {assignment} max? "))
        hw_total += assignment_max

    num_sections_attended = int(input("How many sections did you attend? "))

    section_points = num_sections_attended * ATTENDANCE_PTS
    if section_points > SECTION_MAX:
        section_points = SECTION_MAX
        

    return get_weighted_score(section_points + hw_earned, hw_total + SECTION_MAX, weight)

# Calculates, prints and returns the weighted score for a category.
def get_weighted_score(earned, total, weight):
    # YOUR CODE HERE

    weighted = round2((earned / total) * weight, 1)
    weighted_total = int(weight)
    print(f"Weighted score = {weighted} / {weighted_total}")
    print()

    return weighted
    # return str(f"{weighted} / {weighted_total}")

# Reports a minimum guaranteed GPA and a message about the total score earned.
def report_grade(total):

        # YOUR CODE HERE
        rounded_total = round2(total, 1)
        message = ""
        grade = ""

        if rounded_total >= 90:
            message = "Keep up the great work!"
            grade = "A"
        elif rounded_total >= 80:
            message = "Nice work!"
            grade = "B"
        elif rounded_total >= 70:
            message = "You can do better!"
            grade = "C"
        elif rounded_total >= 60:
            message = "Work harder!"
            grade = "D"
        else:
            message = "See the instructor for help."
            grade = "F"

        print(f"You earned a total of {rounded_total}%.")
        print(f"You will receive at least a {grade} in the course.")
        print(message)
    # pass

# Rounds a value to a given number of digits.
def round2(value, digits):
    return round(value * pow(10, digits)) / pow(10, digits)

# Function that need to be used for Quizzes and Daily Homework
def get_quizzes_or_homework_score(item):

    # YOUR CODE HERE
    return get_weighted_score(min(points, points_possible), points_possible, weight)


main()