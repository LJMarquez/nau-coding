# Function that accepts a string of letter and a
# number of columns and displays a theater seating map
# Input example: theater_seating_map("ABC", 3)
# Output example: A1 A2 A3
#                 B1 B2 B3
#                 C1 C2 C3

# Leo

def theater_seating_map( rows, seats_per_row ):
    for row in rows:
        for seat in range(seats_per_row):
            # print(row, seat + 1, end=" ");
            print(row, end="");
            print(seat + 1, end=" ");
            if seat + 1 == seats_per_row:
                print("");

# theater_seating_map("ABC", 3);


# Vova

def theater_seating_map( rows, seats_per_row ):
    for row in rows:
        for seat in range(1, seats_per_row + 1):
            print(row + str(seat) + " ", end="");
        print();
        
# theater_seating_map("ABCDEFGHIJKLMNOP", 20);

def main():
    x = 2
    print("x is", x)

    x = 15.2   # set x to 15.2
    print("x is now ,", x)
 
    y = 0          # set y to 1 more than x
    y = int(x + 1)
    print("x and y are " , x , "and" , y)

main()
