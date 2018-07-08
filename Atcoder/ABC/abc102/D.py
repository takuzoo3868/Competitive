N = int(input())
A = list(map(int, input().split()))

ans=sum(A)
for a in range(3,N):
    for b in range(2,a):
        for c in range(1,b):
            sum1=sum(A[:c])
            sum2=sum(A[c:b])
            sum3=sum(A[b:a])
            sum4=sum(A[a:])
            dif=max(sum1,sum2,sum3,sum4)-min(sum1,sum2,sum3,sum4)
            if dif<ans:
                ans=dif
                if sum2<=sum1:
                    break
    if min(sum1,sum2,sum3)==sum3:
        break
  if min(sum1,sum2,sum3,sum4)==sum4:
      break

print(ans)
