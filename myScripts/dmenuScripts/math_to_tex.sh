#!/usr/bin/env bash
set -euo pipefail

a=$(echo "Please type your formula..." | dmenu -c -i -p "TeX Formula : " -bw 1 -fn "Ubuntu Mono:size=11" -nb "#222222" -nf "#bbbbbb" -sb "#ff8000" -sf "#000000")
python ~/Documents/Travail/Prog/Python/Maths_to_TeX/Maths_to_TeX.py $a | head -n 1 | xclip -selection clipboard
