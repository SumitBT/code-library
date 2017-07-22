from math import factorial

def lexicographic_index(p):
    result = 0
    for j in range(len(p)):
        k = sum(1 for i in p[j + 1:] if i < p[j])
        result += k * factorial(len(p) - j - 1)
    return result+1

def lexicographic_followers(p):
    return factorial(len(p)) - lexicographic_index(p) - 1


t=int(input())
ans=1
for i in range(t):
    ans=ans*lexicographic_index(input())
print(ans%23456)