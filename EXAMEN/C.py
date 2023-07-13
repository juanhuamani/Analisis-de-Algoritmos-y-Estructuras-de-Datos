def calcular_segundos(horas, minutos, segundos):
    total_segundos = horas * 3600 + minutos * 60 + segundos
    return total_segundos

def calcular_tiempo(segundos):
    horas = segundos // 3600
    segundos %= 3600
    minutos = segundos // 60
    segundos %= 60
    return horas, minutos, segundos

while True:
    print("Seleccione una opción:")
    print("1. Calcular cantidad de segundos dadas horas, minutos y segundos.")
    print("2. Calcular cantidad de horas, minutos y segundos dadas los segundos.")
    print("0. Salir")
    opcion = input("Ingrese el número de opción: ")

    if opcion == "1":
        horas = int(input("Ingrese la cantidad de horas: "))
        minutos = int(input("Ingrese la cantidad de minutos: "))
        segundos = int(input("Ingrese la cantidad de segundos: "))
        total_segundos = calcular_segundos(horas, minutos, segundos)
        print("Total de segundos:", total_segundos)
    elif opcion == "2":
        segundos = int(input("Ingrese la cantidad de segundos: "))
        horas, minutos, segundos = calcular_tiempo(segundos)
        print("Horas:", horas)
        print("Minutos:", minutos)
        print("Segundos:", segundos)
    elif opcion == "0":
        print("¡Hasta luego!")
        break
    else:
        print("Opción inválida. Intente nuevamente.")