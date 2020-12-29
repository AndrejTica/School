# Verzeichnis oder home-Verzwichnis ent/verschlüsseln beim login/logout 


<http://wiki.ubuntuusers.de/ecryptfs/Einrichten#Einrichtung-Verzeichnis-Private>

sudo apt-get install ecryptfs-utils 

as root:
 add 'ecryptfs' to /etc/modules


as user:
ecryptfs-setup-private

use /home/username/Private


