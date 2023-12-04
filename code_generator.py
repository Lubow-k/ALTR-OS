# for i in range(256):
#     print(f"tramplins[{i}] = tramplin_{hex(i).upper()[2:]};")
# s = "static void* tramplins = {"
# for i in range(256):
#     s += "tramplin_" + str(hex(i))[2:].upper() + ", "

# print(s)

D = {"0" : "0",
     "1" : "0",
     "2" : "0",
     "3" : "0",
     "4" : "0",
     "5" : "0",
     "6" : "0",
     "7" : "0",
     "8" : "1",
     "9" : "0",
     "10" : "1",
     "11" : "1",
     "12" : "1",
     "13" : "1",
     "14" : "1",
     "15" : "0",
     "16" : "0",
     "17" : "1",
     "18" : "0",
     "19" : "0",
     "20" : "0",
     "21" : "1",
     "22" : "0",
     "23" : "0",
     "24" : "0",
     "25" : "0",
     "26" : "0",
     "27" : "0",
     "28" : "0",
     "29" : "1",
     "30" : "1",
     "31" : "0",
     }

for key, val in D.items():
    print()
    if val == "0":
        print("tramplin_" + str(hex(int(key))))
        print("    " + "push 0xDEAD")
        print("    " + "push " + str(hex(int(key))))
        print("    " + "jmp collect_context")
    else:
        print("tramplin_" + str(hex(int(key))))
        print("    " + "push " + str(hex(int(key))))
        print("    " + "jmp collect_context")
