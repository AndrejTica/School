
* 1) image installieren
00-docker-pull-vulnerables_web-dva.sh

* 2) einen docker container starten und testen und wieder löschen
01-01-run1_dvwa_8800_3306_4444.sh
01-02-login1_dvwa_8800_3306_4444.sh
01-03-stop1_dvwa_8800_3306_4444.sh
01-04-rm1_dvwa_8800_3306_4444.sh

* 3) 30 docker container starten und wieder löschen
- ports: 8801 .... 8800+Katalognummer 
- ports: 3307 .... 3306+Katalognummer
- ports: 4445 .... 4444+Katalognummer

30-01-run30_dvwa_8800_3306_4444.sh
30-02-stop30_dvwa_8800_3306_4444.sh
30-03-rm30_dvwa_8800_3306_4444.sh
