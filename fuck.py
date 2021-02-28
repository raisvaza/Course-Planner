f = open("Test.txt", 'r')
mfile = f.readline()
for i in range (len(mfile)):
    mfile.split(",")
for i in range (len(mfile)):
    for j in (range(len(mfile[i]))):
        print(mfile[i][j])