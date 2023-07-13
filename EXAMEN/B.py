tamaño = int(input("Ingrese el tamaño del arreglo multidimensional: "))

arreglo = [[0] * tamaño for _ in range(tamaño)]
numero = 1

for i in range(tamaño):
    for j in range(tamaño):
        arreglo[i][j] = numero
        numero += 1

if numero > 101 :
    print("Tamaño inválido. Debe ser un número entre 1 y 100.")
    
else:
    print("Arreglo multidimensional:")
    for fila in arreglo:
        print(fila)