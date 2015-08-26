num = int(raw_input())

def factorial(n) :
    ans = 1
    while n != 1:
        ans *= n
        n = n-1
        
    return ans

print factorial(num)