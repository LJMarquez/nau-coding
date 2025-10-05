def print_cactus_top( size ):
    length = size * 2
    print(" " + "x" * size + " " * (size + 1) + "x" * (size * 2))
    for line in range(1, length):
        print("X" + "-" * size + "X" + " " * (size - 1), end="")
        print("X" + "/" * line + "-" * (length - line) + "X")
    print(" " + "x" * length + "X" + "~" * length + "X", end="")
    print(" " * size + "x" * size)

def print_cactus_middle( size ):
    length = size * 2
    for line in range(1, length):
        print(" " * (length + 1), end="")
        print("X" + "-" * (length - line) + "\\" * line + "X", end="")
        print(" " * (size - 1) + "X" + "-" * size + "X")
    print(" " * (length + 1) + "X" + "~" * length + "X" + "x" * length)

def print_cactus_bottom( size ):
    length = size * 2
    for line in range(length):
        print(" " * (length + 1) + "X" + "~" * length + "X")

def main():
    cactus_size = int(input("Enter cactus size 2-5: "))
    if cactus_size < 2 or cactus_size > 5:
        print(f"{cactus_size} is not between 2 and 5")
        main()
    else:
        print("")
        print_cactus_top( cactus_size )
        print_cactus_middle( cactus_size )
        print_cactus_bottom( cactus_size )
        print("")

main()