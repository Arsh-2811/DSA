import math

def isPalindrome(n):    # Time Complexity : n
    if n / 10 == 0:
        return True
    solution = 0
    temp = n
    while n != 0:
        solution = solution*10 + (n % 10)
        n = n // 10
    if solution == temp:
        return True
    return False

def trailing_zeroes_in_a_factorial(n):    # Time Complexity : log(n)
    answer = 0
    while n!=0:
        answer += n // 5
        n = n //5
    return answer

def greatest_common_division(a, b):    # This is the naive approach and there is a better approack to this problem which is the euclidean algorithm
    res = min(a, b)
    while res > 0:
        if a % res == 0 and b % res == 0:
            break
        else:
            res -= 1
    return res

def euclidean_gcd(a, b):    # Euclidean Algorithm to fing GCD
    if b == 0:
        return a
    return euclidean_gcd(b, a%b)

def least_common_multiple(a, b):    # Based on the fact that " LCM * GCD = a * b "
    return a / euclidean_gcd(a, b) * b

def isPrime(n):
    if n == 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0 :
        return False
    for i in range(5, int(math.sqrt(n)), 6):
        if n % i == 0 or n % (i+2) == 0:
            return False
    return True

def printPrimeFactors(n):
    if n <= 1:
        return 0
    while n % 2 == 0:
        print(2)
        n = n/2
    while n % 3 == 0:
        print(3)
        n = n/3
    for i in range(5, int(math.sqrt(n)), 6):
        while n % i == 0:
            print(i)
            n = n / i
        while n % (i+2) == 0:
            print(i + 2)
            n = n / (i + 2)
    if n > 3:
        print(n)

def sieve_of_erastosthenes(n):    # Sieve of erastosthenes Algorithm
    '''
    This has Time Complexity : n^(3/2)
    '''
    ans = [True for i in range(n+1)]
    ans[0] = False
    ans[1] = False
    for i in range(2, int(math.sqrt(n))):
        if ans[i] == True:
            for j in range(i*i, n+1, i):
                ans[j] = False
    for i in range(2, n+1):
        if ans[i] == True:
            print(i, end=" ")

    '''
    Another implementation which print the number as we traverse with Time Complexity : n*log(logn) which is much better than the above method
    '''
    # ans = [True for i in range(n+1)]
    # ans[0] = False
    # ans[1] = False
    # for i in range(2, n+1):
    #     if ans[i] == True:
    #         print(i, end = " ")
    #         for j in range(i*i, n+1, i):
    #             ans[j] = False

def power_recursive(x, n):    # Time Complexity : logn , Auxilary Space : logn
    if n == 0:
        return 1
    temp = power_recursive(x, n//2)
    temp = temp * temp
    if n % 2 == 0:
        return temp
    else:
        return x * temp

def power_iterative(x, n):
    res = 1
    while n > 0:
        if n % 2 != 0:
            res = res * x
        x = x * x
        n = n // 2
    return res

print(power_iterative(3, 5))