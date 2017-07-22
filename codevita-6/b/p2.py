from math import factorial

def rank(p):
    result = 0
    for j in range(len(p)):
        k=sum(1 for i in p[j + 1:] if i<p[j])
        result+=k*factorial(len(p)-j-1)
    return result+1

t=int(input())
ans=1
for i in range(t):
    ans=ans*rank(input())
print(ans%23456)
