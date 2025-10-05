def number_square( min, max ):
    for j in range(max - min + 1):
        for i in range(min, max + 1):
            num = i + j
            if num > max:
                num = num - max + min - 1
            print(num, end="")
        print("")


number_square(1, 5)
number_square(3, 9)