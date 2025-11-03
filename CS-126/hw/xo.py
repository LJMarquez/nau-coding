def xo(size):
    if size % 2 == 0:
        for row in range(1, (size // 2) + 1):
            print("o" * (row - 1) + "x" + "o" * (size - (row * 2)) + "x" + "o" * (row - 1))
        for row in range(1, (size // 2) + 1):
            print("o" * ((size // 2) - row) + "x" + "o" * ((row - 1) * 2) + "x" + "o" * ((size // 2) - row))
    else:
        for row in range(1, (size // 2) + 1):
            print("o" * (row - 1) + "x" + "o" * (size - (row * 2)) + "x" + "o" * (row - 1))
        print("o" * (size // 2) + "x" + "o" * (size // 2))
        for row in range(size // 2):
            print("o" * ((size // 2) - (row + 1)) + "x" + "o" * (1 + (2 * row)) + "x" + "o" * ((size // 2) - (row + 1)))

# xo(8)

max = 0
min = 10
max = 17 - 4 // 10
max = max + 6
min = max -  min
print(max * 2) 
print(max + min)
print(max)
print(min)