### Installation of norminette 
https://github.com/42school/norminette
Summary - Install using a virtual environment

python3 -m venv $HOME/.venv
source $HOME/.venv/bin/activate
python3 -m pip install --upgrade pip setuptools
python3 -m pip install norminette
echo "export PATH=\$PATH:$HOME/.venv/bin" >> $HOME/.${SHELL##/bin/}rc
deactivate

#### Funciona
sudo apt update
sudo apt install python3-setuptools
sudo apt install pipx
pipx install norminette
pipx ensurepath

### Installation of formatter-42
https://github.com/dawnbeen/c_formatter_42

