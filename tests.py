from random import randint
print("_________")
print("TESTS:")


f = open("input.txt", "w")
n = randint(3, 12)
f.write(str(n) + "\n")
print(n)
values = []
for _ in range(n):
    a = randint(-50, 50)
    b = randint(a, 50)
    a /= 10
    b /= 10
    values += [[a, b]]
    f.write(str(a) + " " + str(b) + "\n")
f.close()
values.sort(key=lambda x: x[0])
[print(*elem) for elem in values]
print("_________")


