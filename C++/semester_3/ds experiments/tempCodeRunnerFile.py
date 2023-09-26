
        for i in range(length):
            for j in range(i+1, length):
                if(arr[i] > arr[j]):
                    arr[i], arr[j] = arr[j], arr[i]