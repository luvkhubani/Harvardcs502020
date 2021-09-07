from cs50 import get_string, get_int, get_float
import math

sentences, words = 0.0, 1.0

text = get_string("Text: ")

for word in text:  # to iterate over each word in text
    for char in word:  # to iterate over each char of the word and check for the desired details
        if char in [".", "!", "?"]:
            sentences += 1
        if char in [" "]:
            words += 1

n = len(text)  # to get the length of text
ch = n - (words + sentences)  # to get no. of characters
L = (ch / words) * 100  # L is the average number of letters per 100 words in the text
S = (sentences / words) * 100  # S is the average number of sentences per 100 words in the text
index = (0.0588 * L) - (0.296 * S) - 15.8  # formula to get grade

if (index >= 4 and index < 5):  # to print out grades in accordance with the result index.
    print("Grade 5")
elif (index >= 1 and index < 16):
    print(f"Grade {int(index)}")
elif (index < 1):
    print("Before Grade 1")
else:
    print("Grade 16+")