import os
import psutil
import decimal
from random import randrange
import math

total = 0
process = psutil.Process(os.getpid())
one_place = decimal.Decimal(10) ** -1

print("VANILLA\n")

used = 0
for i in range(15):
    heap = process.memory_info().rss
    used += heap
    total += used
    print("Iteration " + str(i + 1) + ": " + str(decimal.Decimal(used / 1e+6).quantize(one_place)) + " MB")

print("\n\nLOGIC STATEMENTS\n")

used = 0
for i in range(15):
    a = randrange(11)
    b = randrange(11)
    c = randrange(11)

    if a is b and a is c or a is not b or a is not c and a is b:
        heap = process.memory_info().rss
    else:
        heap = process.memory_info().rss

    used += heap
    total += used
    print("Iteration " + str(i + 1) + ": " + str(decimal.Decimal(used / 1e+6).quantize(one_place)) + " MB")

print("\n\nARITHMETIC OPERATIONS\n")

used = 0
for i in range(15):
    a = (((math.floor(randrange(11)) + 3) * 8) / 4) - (6 % math.sin(math.pi / 23))
    b = math.cos((a * -1) / math.sin(5 + 2))
    c = math.sqrt(((b % 3) + (a + 5) - b)) / math.pow(4, 3 * (2 * 9))

    heap = process.memory_info().rss
    used += heap
    total += used
    print("Iteration " + str(i + 1) + ": " + str(decimal.Decimal(used / 1e+6).quantize(one_place)) + " MB")

print("\n\nTOTAL USAGE: " + str(decimal.Decimal(total / 1e+6).quantize(one_place)) + " MB")