def f(nums):
    n = len(nums)
    sum = n*(n+1)/2
    for i in nums:
        sum-=i
        print("removed: ", i, "sum: ", sum)

    return sum

print(f([3,0,1]))