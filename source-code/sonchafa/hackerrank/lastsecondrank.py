records = [["Sakshi", 68], ["Sakshi2", 68], [
    "Aditya", 32], ["Jaydeep", 54], ["Prajwal", 57]]

# for i in range(5):
#     name = input("Name:  ")
#     score = int(input("Score: "))
#     records.append([name, score])

records.sort(key=lambda x: x[1])
print(records)
