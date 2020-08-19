#!/bin/bash

xbindkeys # luminosité et son
xinput set-prop "Synaptics TM3336-001" "libinput Tapping Enabled" 1 # track apd

#feh --bg-fill Fractal.png &
#/home/martin/Documents/Travail/Prog/C/Mandelbrot/mandelbrotppm/Mandelbrotppm &
~/.fehbg

dte(){
    dte="$(date +"%H:%M")"
    echo -e "$dte"
}

tot=26520000 # /sys/class/power_supply/BAT0/energy_now à 100%
bty(){
    n=`cat /sys/class/power_supply/BAT0/energy_now`
    echo -e "$(($n*100/$tot))%"
}

while true; do
	xsetroot -name "  $(bty) | $(dte) "
    sleep 30s
done &
