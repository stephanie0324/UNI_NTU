f = open("allmaps",'w')

for i in range(1,101):
    cnt = 0;
    if(i < 10):
        filepath = '/Users/stephanie/Desktop/maps/map_00'+ str(i)
    elif(i < 100):
        filepath = '/Users/stephanie/Desktop/maps/map_0'+str(i)

    f.write('vector<vector<int>>v'+str(i)+ '=')
    f.write('{')

    with open(filepath) as fp:
        line = fp.readline()
        while line:
            cnt+=1
            f.write('{')
            for i in line:
                if(i == ' '):
                    f.write(',')
                else:
                    f.write(i)
            if(cnt < 50):
                f.write('},')
            else:
                f.write('}')
            line = fp.readline()

    f.write('};')

f.close()
