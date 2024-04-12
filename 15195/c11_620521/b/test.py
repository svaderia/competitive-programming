import random 

t = 1
n = 100

print(t)
print(n)

arr = [i for i in range(n)]
random.shuffle(arr)

ans = 0;
for i in arr:
    for j in arr:
        ans = max(ans, i ^ j)

while True:
    x =  input().split()
    if(x[0] == '!'):
        with open('test', 'w') as f:
            f.write(str(ans) + '\n')
            f.write(" ".join([str(y) for y in arr]) + '\n')
            f.write(" ".join([str(arr[int(i)]) for i in x[1:]]))
        break
    else:
        x = [0] + [int(y) for y in x[1:]]
        xx = arr[x[1]] | arr[x[2]]
        yy = arr[x[3]] | arr[x[4]]
        if( xx > yy):
            print('>')
        elif(xx < yy):
            print('<')
        else:
            print('=')


