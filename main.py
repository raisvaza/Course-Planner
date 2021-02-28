def isInDaftar(namaMatkul, daftarMatkul):
    found = False
    for i in range(len(daftarMatkul)):
        for j in range(len(daftarMatkul[i])):
            if daftarMatkul[i][j] == namaMatkul:
                found = True
    return found

def addToDaftar(namaMatkul, daftarMatkul):
    i = 0
    while daftarMatkul[i][0] != "":
        i = i + 1
    daftarMatkul[i] == (namaMatkul, 1)

def indeksMatkul(namaMatkul, daftarMatkul):
    for i in range(len(daftarMatkul)):
        if daftarMatkul[i][0] == namaMatkul:
            return i

def hapusMatkul(namaMatkul, daftarMatkul, baris, nMatkul, semester):
    if daftarMatkul[indeksMatkul(namaMatkul,daftarMatkul)][1] == 1:
        print("Semester " + semester + ": " + namaMatkul)
        daftarMatkul[indeksMatkul(namaMatkul,daftarMatkul)].pop()
        nMatkul -= 1
        for i in baris:
            if baris[i][0] == namaMatkul:
                if len(baris[i]) > 1:
                    for j in range(1, len(baris[i]), 1):
                        daftarMatkul[indeksMatkul(baris[i][j], daftarMatkul)][1] -= 1
                        if daftarMatkul[indeksMatkul(baris[i][j], daftarMatkul)][1] == 1:
                            hapusMatkul(baris[i][j], daftarMatkul, baris, nMatkul, semester + 1)


# Mengubah file masukan menjadi array of array
f = open("Test.txt", 'r')
lines = f.readlines()
baris = ["" for i in range(len(lines))]
for i in range(len(lines)):
    baris[i] = lines[i].replace(".","")
    baris[i] = baris[i].replace("\n","")
    baris[i] = baris[i].split(",")

# inisialisasi daftar matkul
daftarMatkul = [("",0) for i in range(100)] # Daftar mata kuliah dengan jumlah kemunculannya
nMatkul = 0

# Mendaftar semua matkul
for i in range(len(baris)):
    for j in range(len(baris[i])):
        if (not(isInDaftar(baris[i][j],daftarMatkul))):
            addToDaftar(baris[i][j],daftarMatkul)
            nMatkul = nMatkul + 1
        else:
            daftarMatkul[indeksMatkul(baris[i][j], daftarMatkul)][1] += 1

# TOPOLOGICAL SORT
# Mencari matkul dengan kemunculan paling sedikit
i = 0
semester = 1
while nMatkul != 0:
    hapusMatkul(daftarMatkul[i][0], daftarMatkul, baris, nMatkul, semester)
    i += 1