filepath = '/Users/stephanie/Desktop/maps/map_001'
f = open("map_try",'w')
f.write('vector<vector<int>>v1 = ')
f.write('{')
with open(filepath) as fp:
    line = fp.readline()
    while line:
        f.write('{')
        for i in line:
            if(i == ' '):
                f.write(',')
            else:
                f.write(i)
        f.write('},')
        line = fp.readline()
        
f.write('}')
f.close()

