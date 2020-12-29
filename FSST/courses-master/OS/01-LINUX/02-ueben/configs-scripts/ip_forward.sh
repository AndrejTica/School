## ausführen mit: sudo ./ip_forward.sh
sudo iptables --table nat --append POSTROUTING --out-interface eth0 -j MASQUERADE	
sudo iptables --append FORWARD --in-interface eth1 -j ACCEPT					

echo 1 > /proc/sys/net/ipv4/ip_forward								

