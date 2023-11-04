# for i in range(256):
#     print("static void tramplin_"+ str(hex(i))[2:].upper() + "() { panic_handler(" + str(hex(i)).upper() + "); }")
s = "static void* tramplins = {"
for i in range(256):
    s += "tramplin_" + str(hex(i))[2:].upper() + ", "

print(s)
