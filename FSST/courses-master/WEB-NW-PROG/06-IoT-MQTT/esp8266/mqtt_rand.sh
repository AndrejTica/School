#!/bin/bash
# mqtt_rand.sh
# ahofmann: 2017
# ./mqtt_rand.sh

while true 
do
	mosquitto_pub -t /rand -h 172.16.48.156 -m `/usr/bin/shuf -i 1-100 -n 1`

	sleep 3s
done

