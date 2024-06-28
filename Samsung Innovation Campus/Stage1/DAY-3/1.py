input = [100, 200, 300, 400, 500]
compared_input = [500, 200, 400]
output = []
for i in range (len(input)):
    if input[i] in compared_input:
        input[i] = 0
print(input)