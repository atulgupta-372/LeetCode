k=int(input())
list1=[]
for _ in range(k):
    val=input()
    list1.append(val)

minCost=80
i=0
def fun(leg1,leg2,count,i):
    global minCost
    if i==k:
        if minCost>count:
            minCost=count
            return
    if i<k:
        if list1[i]==leg1 or list1[i]==leg2:
            i=i+1
        else:
            fun(leg1,list1[i],count+1,i+1)
            fun(list1[i],leg2,count+1,i+1)

first=list1[0]
second=list1[1]
idx=1
while idx<len(list1):
    if first!=list1[idx]:
        second=list1[idx]
    idx+=1

fun(first,second,0,idx)
print(minCost)