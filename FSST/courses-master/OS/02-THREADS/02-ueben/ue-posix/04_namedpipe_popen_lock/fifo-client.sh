#!/bin/sh 
# fifo-client.sh 
# $$ ... liefert die PID 
# 
CLIENT_FIFO=/tmp/clientFIFO.$$ 
SERVER_FIFO=/tmp/serverFIFO 

# 
mkfifo $CLIENT_FIFO 

# SIGTERM SIGINT abfangen und CLIENT_FIFO löschen und ende 
trap "trap '' 0 1 2 3 15; 
	rm -f $CLIENT_FIFO; exit 0;" 0 1 2 3 15 

# infos 
echo " Kommandos:" 
echo "		add	Name	Number" 
echo "		get	Name" 
echo "		get	Number" 

# Anfrage lesen und an Server schicken 
while read question 
do 
	echo $question $CLIENT_FIFO > $SERVER_FIFO 
	read answer < $CLIENT_FIFO 
	echo $answer > /dev/tty 
done 
