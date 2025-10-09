# ¿`gitignore`?
---
Es un archivo de texto que colocas en la raíz de tu proyecto y en el defines patrones de archivos o carpetas tu carpetas a tu repositorio de Git.


### Crea el archivo `.gitignore`
En la carpeta raíz de tu proyecto, crea un archivo llamado: `.gitignore`.

### Ejemplos de uso
Dentro del archivo, escribes los patrones de los archivos/carpetas a ignorar:

* Ignorar un archivo específico. `secret.txt`
* Ignorar todos los archivos .log: `*.log`
* Ignorar una carpeta completa: 
`
/node_modules
/dist
`
* Ignorar todos los archivos de configuración locales: `*.env`

### Importante: Si ya lo subiste antes
Si un archivo ya fue rastreado por Git y lo agregas a `.gitignore`, **Git seguirá rastreándolo.**
Para dejar de rastrearlo, haz: `git rm --cached archivo_o_carpeta`
```sh
git rm --cached secret.txt 
git commit -m "Dejo de rastrear secret.txt" # Después, haz un commit
# Ahora sí, Git lo ignorará.
```

#### Ejemplo completo de `.gitignore`
```sh
# Dependencias
/node_modules

# Archivos de compilación
/dist
/build

# Logs
*.log

# Configuración local
.env
```