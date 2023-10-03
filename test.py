import os


def generate_test_bin():
    size = 393216 - 512    #393216 is 384K
    f = open("test.bin", "wb")
    line = os.urandom(size)
    f.write(line)
    count_sum = sum(line)


# generate_test_bin()


count_sum = 0
with open("out.bin", "rb") as file:
    number = list(file.read())
    count_sum += sum(number)

with open("test.bin", "rb") as file:
    number = list(file.read())
    count_sum += sum(number)

print(hex(count_sum % (2 ** 8)))




