angka = [1, 2, 3, 4, 5]
hasil = []
panjang = len(angka)
for i in range(panjang+1):
    if i%2==0:
        continue
    elif i==5:
        hasil += [5]
    else:
        hasil+=["ganjil"*i]
print(hasil)