angka = [[1,2,3],[2,3,4],[3,4,5]]
hasil = []
for i in angka:
    tmp = 0
    for j in i:
        tmp += j
    hasil+=[tmp]
print(hasil)