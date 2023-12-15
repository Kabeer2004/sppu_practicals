unsorted_arr = [60, 70, 40, 20, 15, 95, 60, 22, 34]
sorted_arr = [10, 17, 22, 27, 38, 36, 40]

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            print (target, "found at", i)

def sentinel_search(arr, target):
  arr.append(target)
  found = False
  i = 0
  while arr[i] != target:
    i += 1
  if i < len(arr) - 1:
    found = True
  arr.pop()
  return i if found else -1

def binary_search (arr, target):
    n = len(arr)
    left = 0
    right = n - 1
    while (left<right):
        mid = int((left + right)/2)
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            right = mid-1
        elif arr[mid] < target:
            left = mid+1

def fibonacci_search(arr, x):
    n = len(arr)

    # Initialize Fibonacci numbers
    fib_m_minus_2 = 0
    fib_m_minus_1 = 1
    fib = fib_m_minus_1 + fib_m_minus_2

    # Find the smallest Fibonacci number greater than or equal to n
    while (fib < n):
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib
        fib = fib_m_minus_1 + fib_m_minus_2

    offset = -1

    while (fib > 1):
        i = min(offset + fib_m_minus_2, n - 1)

        if (arr[i] < x):
            fib = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib - fib_m_minus_1
            offset = i

        elif (arr[i] > x):
            fib = fib_m_minus_2
            fib_m_minus_1 = fib_m_minus_1 - fib_m_minus_2
            fib_m_minus_2 = fib - fib_m_minus_1

        else:
            return i  # Element found at index i

    if (fib_m_minus_1 and arr[offset + 1] == x):
        return offset + 1  # Element found at index offset + 1
    '''
    The overall condition (fib_m_minus_1 and arr[offset + 1] == x) checks both conditions together. 
    If fib_m_minus_1 is non-zero (i.e., True in a boolean context) and the element at offset + 1 is equal to x,
    then the condition is True, indicating that the element is found at index offset + 1.
    '''

    return -1  # Element not found

linear_search(unsorted_arr, 20)
print (60,"found at",sentinel_search(unsorted_arr, 60))
print (17,"found at",binary_search(sorted_arr, 17))
print (27,"found at",fibonacci_search(sorted_arr,27))