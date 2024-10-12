def dectobin(n): # 5  2 
    if n > 1:
        dectobin(n//2) # 5//2 = 2 2//2 = 1 1//2 = 1
    print(n % 2, end='')  # 1  0  1 


def swapbits(n, i, j):
    if (n >> i) & 1 != (n >> j) & 1:
        n ^= (1 << i) | (1 << j)
    return n

def bitat(n, i):
    return (n >> i) & 1

def poweroftwobit(n):
    return n and not (n & (n - 1))

def poweroftwo(n):
    if n == 0:
        return False
    
    val = 1
    for i in range(n):
        if val > n:
            break

        if val == n:
            return True
        
        val *= 2
    
    return False

def poweroftwo1(n):
    if n == 1:
        return True

    while n>1:
        if n==2:
            return True
        n /= 2
    return False

# print(poweroftwo1(16))
# print(poweroftwo1(6))
# print(poweroftwo1(1))
# print(poweroftwo1(0))

def factorial(n):
    fact = 1
    for i in range(1, n+1):
        fact = fact * i

    return fact

# print(factorial(3))

def dectobin(n):
    if n > 1:
        dectobin(n >> 1)
    print(n & 1, end='')


def binarysearch(arr, x):
    f = 0
    l = len(arr) - 1
    m = (f + l) // 2
    while f<=l:
        if arr[m] == x:
            return m
        elif arr[m] < x:
            f = m + 1
        else:
            l = m - 1
            m = (f + l) // 2
    
    return -1


# print(binarysearch([1, 2, 3, 4, 5, 6, 7, 8, 9], 3))

def matrixmul(a, b):
    c = [[0]*len(b[0]) for _ in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            c[i][j] = 0
            for k in range(len(b)):
                c[i][j] += a[i][k] * b[k][j]
    return c



# print(matrixmul([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[1, 2, 3], [4, 5, 6], [7, 8, 9]]))




def add(a, b):
    while b:
        carry = a & b
        a ^= b
        b = carry << 1
    return a

# print(add(5, 3))

def add1(a,b):
    while(a):
        b += 1
        a -= 1
    return b


