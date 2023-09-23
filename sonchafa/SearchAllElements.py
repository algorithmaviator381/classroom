def create_index_dict(arr):
    index_dict = {}
    
    for i in range(len(arr)):
        elem = arr[i]
        if elem not in index_dict:
            index_dict[elem] = [i]
        else:
            index_dict[elem].append(i)
    
    return index_dict

arr = [1, 2, 2, 3, 1, 4, 3]
index_dict = create_index_dict(arr)

for key, value in index_dict.items():
    print(f"{key}: {value}")

