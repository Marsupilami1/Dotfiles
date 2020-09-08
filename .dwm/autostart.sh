#!/bin/bash

xbindkeys # luminosité et son
xinput set-prop "Synaptics TM3336-001" "libinput Tapping Enabled" 1 # track apd
picom &
emacs --bg-daemon &

#feh --bg-fill Fractal.png &
#/home/martin/Documents/Travail/Prog/C/Mandelbrot/mandelbrotppm/Mandelbrotppm &
~/.fehbg

dte(){
	dte="$(date +"%H:%M")"
	echo -e "$dte"
}

# tot=26520000 # /sys/class/power_supply/BAT0/energy_now à 100%
tot=$(cat /sys/class/power_supply/BAT0/energy_full)
bty(){
	n=`cat /sys/class/power_supply/BAT0/energy_now`
	percentage=$(($n*100/$tot))
	numb=$((percentage*15/100))
	loadbar=$(printf '▰%.0s' $(seq -s\  1 $numb))
	spaces=$(printf ' %.0s' $(seq -s\  1 $((14-$numb))))
	echo -e "$percentage % /$loadbar$spaces/"
}

while true; do
	xsetroot -name "  $(bty) $(dte) "
	sleep 30s
done &
