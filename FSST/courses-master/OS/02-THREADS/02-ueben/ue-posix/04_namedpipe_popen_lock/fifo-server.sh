#!/bin/sh 
# fifo-server.sh 
#    Telefonserver 
#			$1	$2		$3		$4 
#    Kommandos: 
#			add	Name	Number	FIFO 
#               get Name    FIFO 
#               get Number  FIFO 

SERVER_FIFO=/tmp/serverFIFO 
DATA=fifo-server.db         # Name Number 

mkfifo $SERVER_FIFO 
# 
trap 'trap "" 0 1 2 3 15; 
	rm -f $SERVER_FIFO; exit ' 0 1 2 3 15 

while true 
do 
	(  while read question < $SERVER_FIFO 
		do 
			set $question 
			case  $1 
				in a*) echo "$2 $3" >>  $DATA 
						sort -u -o $DATA $DATA 
						echo added > $4 
				;; g*) found="`grep "$2" $DATA`" 
						echo "$found" > $3 
				;; *)  echo "What?" > /dev/console 
			esac 
		done 
	) 
done 
