from cs50 import get_string, get_int, get_float
import math

while True:
    change = get_float("Change owed: ") * 100
    if(change > 0):
        break

coins = 0

changeleft = change  # to keep track of change which is left

coins += math.floor(change/25)  # add the coins
changeleft = round(change % 25)  # updates the change which is left.

coins += math.floor(changeleft/10)
changeleft = round(changeleft % 10)

coins += math.floor(changeleft/5)
changeleft = round(changeleft % 5)

coins += math.floor(changeleft/1)
changeleft = round(changeleft % 1)

print(f"{coins}")

