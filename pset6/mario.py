import cs50


while True:
    height = cs50.get_int("Height: ")
    if(height > 0 and height < 9):
        break
n = height -1
for x in range(height):
    for y in range(n,-1,-1):
        if(y <= x):
            print("#", end="") # for printing first pyramid
            if(y == 0):
                print("  ", end="")
                for b in range(x+1): # for printing second pyramid
                    print("#", end="");
        else:
            print(" ", end="") # for printing space until brick of pyramid is needed.
    print("")
