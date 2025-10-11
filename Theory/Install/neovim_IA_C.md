## Neovim
---
### Método 1: Instalación rápida (desde repositorio oficial de Ubuntu)
Ideal si solo quieres usar Neovim sin complicarte.
```bash
sudo apt update
sudo apt install neovim -y
```
Luego puedes verificar la versión con:
```bash
nvim --version
```
* **Ventaja**: fácil y estable
* **Desventaja**: puede no ser la versión más reciente (suele quedarse un poco atrás)

### Método 2: Instalar la versión más reciente (PPA oficial de Neovim)
Recomendado si quieres las últimas funciones (LSP, Treesitter, etc.).
```bash
sudo add-apt-repository ppa:neovim-ppa/unstable -y
sudo apt update
sudo apt install neovim -y
```
Esto instala la versión más actual directamente mantenida por los desarrolladores de Neovim.

### Método 3: Usar AppImage (no requiere instalación del sistema)

Ideal si no quieres tocar tus paquetes del sistema.

1. Descarga la AppImage:
```bash
wget https://github.com/neovim/neovim/releases/latest/download/nvim.appimage
```
2. Dale permisos de ejecución:
```bash
chmod u+x nvim.appimage
```
3. Ejecútalo directamente:
```bash
./nvim.appimage
```
4. (Opcional) Instálalo globalmente:
```bash
sudo mv nvim.appimage /usr/local/bin/nvim
```
#### Comprobación
Ejecuta:
```bash
nvim
```
