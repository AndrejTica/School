#!/bin/bash
# mqtt_hw_gpu.sh
# ahofmann: 2017
# ./mqtt_hw_gpu.sh

while true
do
	mosquitto_pub -t /hw/gpu -h 172.16.48.156 -m `/opt/vc/bin/vcgencmd measure_temp`

	sleep 3s
done
