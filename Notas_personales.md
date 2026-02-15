# Guardar archivos en GitHub:
## Estados de guardado en GitHub
- 🟢U (Untracked - No rastreado / Verde): 
    - Es un archivo completamente nuevo. Git te dice: "No sé qué es esto, nunca le he tomado una foto".
- 🟢A (Added - Agregado / Verde): 
    - Es el paso intermedio. Significa que escribiste git add, por lo que el archivo ya está en el "escenario" posando, listo para que dispares la cámara con el commit.
- 🟡M (Modified - Modificado / Amarillo o Naranja): 
    - Es un archivo veterano. Git ya lo conoce (ya le tomó fotos antes), pero detectó que le cambiaste líneas de código desde la última foto.
- 🔴D (Deleted - Eliminado / Rojo): 
    - Borraste un archivo que Git conocía. Te avisa que en la próxima foto, ese archivo ya no existirá.
- ⚪Sin letra y sin color (Gris/Blanco): 
    - El estado ideal. Significa "Limpio" (Clean). El archivo en tu computadora es una copia exacta e idéntica a la que está respaldada en GitHub.
### En terminal
    General:

    1 git add .
    2 git commit -m "mensaje personal"
    3 git push

    Si quiero guardar un archivo en especifico:

    1 git add Nombre_de_archivo.extension
    2 git commit -m "docs: Actualizo solo este archivo"
    3 git push

El `.` en `add .` le dice a GitHub que **GUARDE TODO** los archivos del proyecto que no esten en **.gitignore**

[Enlace a mi GitHub: NODO_Plataforma_Cognitiva](https://github.com/aizenWN/NODO_Plataforma_Cognitiva)

# Guardado de Datos en PC y advertencias
``
Para guardar todos los archivo presionar la combinacion de teclas: `Control + k` y despues `s`
(Desapareceran los circulos blancos en los archivos)