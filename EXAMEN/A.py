disfraces = ["mono", "jirafa", "tigre", "elefante", "koala", "aguila", "gallina", "loro", "cocodrilo", "serpiente"]

mamiferos = []
aves = []
reptiles = []


for disfraz in disfraces:
    if disfraz in ["mono", "jirafa", "tigre", "elefante", "koala"]:
        mamiferos.append(disfraz)
    elif disfraz in ["aguila", "gallina", "loro"]:
        aves.append(disfraz)
    elif disfraz in ["cocodrilo", "serpiente"]:
        reptiles.append(disfraz)

especies = {
    "Mamíferos": len(mamiferos),
    "Aves": len(aves),
    "Reptiles": len(reptiles)
}
especie_con_mas_disfraces = max(especies, key=especies.get)

print("Mamíferos:", mamiferos )
print( "Total Mamíferos : " ,len(mamiferos))
print("Aves:", aves)
print( "Total Aves : " ,len(aves))
print("Reptiles:", reptiles)
print( "Total Reptiles : " ,len(reptiles))

print("La especie con más disfraces es:", especie_con_mas_disfraces)


