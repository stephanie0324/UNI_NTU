import random
fp = open("new_map" , 'w')
#a is a dynamic array 50*50

n = 50
m = 50
a = [0]*n



for i in range(n):
    a[i] = [0]*m

for i in range(len(a)):
    if(i == 0 or i == len(a)-1):
        for j in range(len(a[i])):
            a[i][j] = -1
    else:
        for j in range(len(a[i])):
            if(j == 0 or j==len(a[i])-1):
                a[i][j] = -1
            else:
                a[i][j] = 0

#random targets
num_t = random.randint(1,50)
for i in range(num_t):
    c = random.randint(1,48)
    b = random.randint(1,48)
    score_t = random.randint(1,50)
    a[b][c]= score_t


#random obstacles
num_o =  random.randint(1,50)
for i in range(num_o):
    c = random.randint(1,48)
    b = random.randint(1,48)
    a[b][c]= -1
    

    #write file
fp.write('{')
for i in range(len(a)):
    fp.write('{')
    for j in range(len(a[i])):
        fp.write('%d'% a[i][j])
        if(j != len(a[i])-1):
            fp.write(',')
    fp.write('}')
    if(i != len(a)-1):
        fp.write(',')
fp.write('}')
fp.close()
print('\n')
