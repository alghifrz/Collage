angka = [1, 2, 3, 4, 5]
hasil = []
for i in angka:
    if i%2==0:
        #hasil.append("genap")
        hasil+=["genap"]
    else:
        #hasil.append("ganjil")
        hasil+=["ganjil"]
print(hasil)
        