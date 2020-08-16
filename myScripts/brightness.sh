#!/bin/bash

dir="/sys/class/backlight/amdgpu_bl0"
max=`cat $dir/max_brightness`
current=`cat $dir/brightness`

new=$(($current+$1))

if [[ $new -lt $max ]]; then
	if [[ $new -gt 0 ]]; then
		echo $new > $dir/brightness
	else
		echo "0" > $dir/brightness
	fi
else
	echo $max > $dir/brightness
fi
