#AC
#BOJ 9237 ?댁λ 珥? 
#https://www.acmicpc.net/problem/9237
n = int(input())
arr = []
arr = list(map(int,input().split()))
arr.sort(reverse=True)
for i in range(n):
    arr[i] += i+1

arr.sort(reverse=True)
print(arr[0]+1)
