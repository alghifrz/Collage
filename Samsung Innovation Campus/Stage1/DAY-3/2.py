input = [
    {'nama':'Budi','gaji':5000},
    {'nama':'Dwi','gaji':8000},
    {'nama':'Tri','gaji':6000},
]

output = []
temp = 0
total = 0

for i in input:
    output.append(i['gaji'])

for i in output:
    temp+=i
total+= temp
    
urut = sorted(output, reverse=True)
gaji_tertinggi = urut[0]

index_tertinggi = output.index(gaji_tertinggi)

hasil = {
    'highest_salary':input[index_tertinggi]['nama'],
    'total_salary':total
}

print(hasil)
