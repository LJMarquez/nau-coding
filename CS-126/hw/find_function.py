string = "Hello, World!"
print(string.find("o"))
print(string[:string.find(" ")])

for i in range(len(string)):
    print(f"{i} {string[i]}")

def median_of_3(a, b, c):
    if (a <= b <= c) or (c <= b <= a):
        print(b)
        return b
    elif (b <= a <= c) or (c <= a <= b):
        print(a)
        return a
    else:
        print(c)
        return c

median_of_3(3, 4, 1)        
median_of_3(7, 2, 45)       
median_of_3(8, 5, 1)        
median_of_3(-1000, -55, -23)
median_of_3(-6, 817, -2)    
median_of_3(42, 42, 42)     
median_of_3(10, 1000, 300)  
median_of_3(100, 1000, 10)