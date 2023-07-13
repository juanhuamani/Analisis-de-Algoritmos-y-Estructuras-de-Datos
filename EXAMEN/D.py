import random

class Moneda:
    def __init__(self):
        self.lanzamientos = []

    def lanzar(self):
        resultado = random.choice(["Cara", "Sello"])
        self.lanzamientos.append(resultado)
        return resultado

    def obtener_lanzamientos(self):
        return self.lanzamientos

moneda = Moneda()

for i in range(10):
    resultado = moneda.lanzar()
    print("Lanzamiento:", resultado)

lanzamientos = moneda.obtener_lanzamientos()
print("Lanzamientos registrados:", lanzamientos)

