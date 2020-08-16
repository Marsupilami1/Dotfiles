alias grep='grep --color=always'
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ls='exa --color=always --group-directories-first'
alias lt='ls -T'
alias ll='ls -l'
alias la='ls -a'
alias lla='ls -la'

#Mes ajouts
PS1='${arch_chroot:+($debian_chroot)}\[\033[01;32m\]\u\[\033[00m\]: \[\033[01;34m\]\w\[\033[00m\] \$ '
alias compile='g++ -Wall -std=c++17 -O2 -c *.cpp && g++ -Wall -std=c++17 -O2 -o main *.o -lsfml-graphics -lsfml-window -lsfml-system'
alias prepa='cd ~/Documents/Travail/Prepa/'
alias prog='cd ~/Documents/Travail/Prog'
shopt -s globstar
export PATH="$HOME/.emacs.d/bin:$PATH"
set -o vi
