# CORNER (COURSE PLANNER)
# Program Penyusunan Rencana Kuliah
# Oleh: Rais Vaza Man Tazakka (13519060)

def profil():
# Memasukkan informasi profil pengguna
# FITUR TAMBAHAN
    nama = str(input("Masukkan nama Anda: "))
    NIM = str(input("Masukkan NIM Anda: "))
    fakultas = str(input("Masukkan fakultas Anda: "))
    jurusan = str(input("Masukkan jurusan Anda: "))
    print("Nama: " + nama)
    print("NIM: " + NIM)
    print("Fakultas: " + fakultas)
    print("Jurusan: " + jurusan)

def addToDaftar(namaMatkul, daftarMatkul): 
# Menambah matkul ke daftar matkul
    i = 0
    while daftarMatkul[i][0] != "":
        i = i + 1
    temp = list(daftarMatkul[i])
    temp[0] = namaMatkul
    daftarMatkul[i] = tuple((temp[0],int(temp[1]),temp[2]))

def konversiAngka(angka): 
# Mengkonvesi angka arab menjadi angka romawi
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
# Menghapus mata kuliah
    n = semester + 1
    if daftarMatkul[i][2] == False:        
        if daftarMatkul[i][1] == 0:
            print("Semester " + konversiAngka(semester) + ": " + daftarMatkul[i][0])
            temp = list(daftarMatkul[i])
            temp[0] = daftarMatkul[i][0]
            temp[1] = daftarMatkul[i][1]
            temp[2] = True
            daftarMatkul[i] = tuple((temp[0],temp[1],temp[2]))
            
            # Mengurangi derajat masuk matkul yang memiliki daftarMatkul[i][0] sebagai prereq-nya
            for j in range(len(baris)):
                for k in range(1,len(baris[j]),1):
                    if daftarMatkul[i][0] == baris[j][k]:
                        temp = list(daftarMatkul[j])
                        temp[1] -= 1
                        daftarMatkul[j] = tuple(temp)

            # Rekursi menghapus mata kuliah           
            for j in range(len(baris)):
                for k in range(1,len(baris[j]),1):
                    if daftarMatkul[i][0] == baris[j][k]:
                        if daftarMatkul[j][1] == 0: 
                            hapusMatkul(j,daftarMatkul,baris,n)
            
        
def isVisitedAll(daftarMatkul):
# Mengecek apakah semua matkul sudah dikunjungi
    visitedAll = True
    for i in range(len(daftarMatkul)):
        visitedAll = visitedAll and daftarMatkul[i][2]
    return isVisitedAll

# Mengubah file masukan menjadi array of array
namaFile = str(input("Masukkan nama file: "))
f = open(namaFile, 'r')
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

# Mencatat derajat masuk setiap mata kuliah
for i in range(len(baris)):
    derajatMasuk = 0
    for j in range(1,len(baris[i]),1):
        derajatMasuk += 1
        daftarMatkul[i] = tuple((daftarMatkul[i][0],derajatMasuk, False))

# Menyambut pengguna
print("\n               SELAMAT DATANG DI CORNER (COURSE PLANNER)")
print("                SEBUAH PROGRAM PENYUSUNAN RENCANA KULIAH\n")
print("-------------------------------------------------------------------------")

# Menampilkan informasi pengguna
profil()
print("\nBerikut adalah daftar mata kuliah yang bisa Anda ambil sesuai dengan semesternya.")

# TOPOLOGICAL SORT ATAS DAFTAR MATA KULIAH
semester = 1
for i in range(len(daftarMatkul)):
    hapusMatkul(i,daftarMatkul,baris,semester)
    i += 1