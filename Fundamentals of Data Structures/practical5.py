arr = [65.3, 54.7, 76.3, 45.4, 88.6, 65.7, 99.2, 90.6]

def selection_sort(arr):
    for i in range(len(arr)):
        mini = i
        for j in range(i+1, len(arr)):
            if arr[j]<arr[mini]:
                mini = j
        temp = arr[i]
        arr[i] = arr[mini]
        arr[mini] = temp
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr

print ("Array sorted by selection sort: ",selection_sort(arr))
print ("Array sorted by bubble sort: ",bubble_sort(arr))

print ("Top 5 scores: ", bubble_sort(arr)[len(arr)-1:len(arr)-6:-1])