line1 = open("test.bin", "rb").readline()
line2 = open("mem.bin", "rb").readline()

assert (len(line1) == len(line2))

for i in range(len(line1)):
    assert(line1[i] == line2[i])
