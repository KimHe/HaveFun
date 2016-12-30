#!/bin/bash

# a small script to list the battery condition 

upower -i /org/freedesktop/UPower/devices/battery_battery | grep -E "state|time\ to\ empty|percentage|capacity"
