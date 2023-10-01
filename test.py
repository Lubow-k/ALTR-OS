import os

size = 393216
f = open("test.bin", "wb")
line = os.urandom(size)
f.write(line)
count_sum = sum(line)
print(count_sum)
