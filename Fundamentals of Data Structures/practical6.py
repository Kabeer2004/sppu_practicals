arr = [65.3, 54.7, 76.3, 45.4, 88.6, 65.7, 99.2, 90.6]

def quick_sort(arr):
    for i in arr:
        pivot = i
        left = []
        right = []
        for j in arr:
            if j<=i:
                left.append(j)
            else:
                right.append(j)
        arr = left+right
    return arr

print ("Array sorted by quick sort: ",quick_sort(arr))

print ("Top 5 scores: ", quick_sort(arr)[len(arr)-1:len(arr)-6:-1])