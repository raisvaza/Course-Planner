def addToDaftar(namaMatkul, daftarMatkul):
    i = 0
    while daftarMatkul[i][0] != "":
        i = i + 1
    temp = list(daftarMatkul[i])
    temp[0] = namaMatkul
    temp[1] = 0
    temp[2] = False
    daftarMatkul[i] = tuple((temp[0],int(temp[1]),temp[2]))

def konversiAngka(angka):
    if angka == 1:
        return "I"
    elif angka == 2:
        return "II"
    elif angka == 3:
        return "III"
    elif angka == 4:
        return "IV"
    elif angka == 5:
        return "V"
    elif angka == 6:
        return "VI"
    elif angka == 7:
        return "VII"
    elif angka == 8:
        return "VIII"

def hapusMatkul(i,daftarMatkul, baris, semester):
    if daftarMatkul[i][1] == 0:
            for j in range(len(baris)):
                for k in range(1,len(baris[j]),1):
                    if daftarMatkul[i][0] == baris[j][k]:
                        temp = list(daftarMatkul[j])
                        temp[1] -= 1
                        daftarMatkul[j] = tuple(temp)
                        hapusMatkul(j,daftarMatkul,baris,semester+1)
            temp = list(daftarMatkul[i])
            temp[2] = True
            print("Semester " + konversiAngka(semester) + ": " + daftarMatkul[i][0])

# Mengubah file masukan menjadi array of array
f = open("Test.txt", 'r')
lines = f.readlines()
baris = ["" for i in range(len(lines))]
for i in range(len(lines)):
    baris[i] = lines[i].replace(".","")
    baris[i] = baris[i].replace("\n","")
    baris[i] = baris[i].split(",")

# inisialisasi daftar matkul
daftarMatkul = [("",0,False) for i in range(len(baris))] # Daftar mata kuliah dengan derajat masuknya
nMatkul = 0

# Mendaftar semua matkul
for i in range(len(baris)):
    addToDaftar(baris[i][0], daftarMatkul)
    nMatkul += 1

# Mencatat derajat masuk
for i in range(len(baris)):
    derajatMasuk = 0
    for j in range(1,len(baris[i]),1):
        derajatMasuk += 1
        daftarMatkul[i] = tuple((daftarMatkul[i][0],derajatMasuk, False))

semester = 1
for i in range(len(daftarMatkul)):
    if daftarMatkul[i][2] == False:
        hapusMatkul(i,daftarMatkul,baris,semester)
