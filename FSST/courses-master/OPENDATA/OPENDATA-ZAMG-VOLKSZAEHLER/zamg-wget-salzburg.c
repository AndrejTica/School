/*
 * zamg-wget-salzburg.c
 * liest alle 5 Sekunden die aktuellen Temperaturdaten von Salzburg 
 * Quelle: ZAMG
 *
 * gcc zamg-wget-salzburg.c -ozamg-wget-salzburg.exe
 * ./zamkg-wget-salzburg.exe
 *
 * verwendet: system(), wget(), scanf()
 *
 * Hinweis: proxy
 * Datei: /home/informatik/.wgetrc
proxy_user=username
proxy_password=password
http_proxy=http://tmg-z2.htl.org:8080
https_proxy=http://tmg-z2.htl.org:8080

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX 50
#define PAUSE 5


// liest bei gegebenem Ort die Temperatur (s. call-by-reference)
// @param char* ort [in] ... Ortsangabe
// @param int* temp [out] ... Temperatur
// @return 0 ... ok
// @return -1 ... error
int get_temperatur(char *ort, float *pTemp);


int main()    {
    int ret;
	float temperatur;
    
    while(1){
        system("wget http://www.zamg.ac.at/ogd -q --output-document=temperatur.csv");
    
        ret=get_temperatur("Salzburg", &temperatur);
        if(ret<0)
            return ret;

        printf("Temperatur (Salzburg) = %f°C\n", temperatur);    
        sleep(PAUSE);
    }
    return EXIT_SUCCESS;
}



int get_temperatur(char *ort, float *pTemp)    {
    FILE *datei;
    char name[MAX];
    
    datei=fopen("temperatur.csv","r");
    if(datei==NULL)    {
        perror("Datei temperatur.csv nicht verfügbar");
        return -1;
    }    

    fscanf(datei,"%*[^\n]");  // überlies erste Zeile
    while (feof(datei) == 0){ // bis zum Dateiende   
        fscanf(datei,"%*i;\"%[^\"]\";%*i;\"%*[^\"]\";\"%*[^\"]\";%f%*[^\n]",name, pTemp);

        if(strcmp(name,ort)==0) // fertig
            break;
		else{
			printf("Ort=%s, name= %s, temp=%f\n", ort,name,*pTemp);
		}
    }

    fclose(datei);
    return 0;
}
/* Beispiel: temperatur.csv

"Station";"Name";"Höhe m";"Datum";"Zeit";"T °C";"TP °C";"RF %";"WR °";"WG km/h";"WSR °";"WSG km/h";"N l/m²";"LDred hPa";"LDsta
t hPa";"SO %"
11010;"Linz/Hörsching";298;"17-03-2014";"19:00";13,3;5,5;60;250;13;;22,3;0;1017,7;980,7;0
11012;"Kremsmünster";383;"17-03-2014";"19:00";14,3;5;54;270;13;299;19,8;0;1017,9;972,1;0
11022;"Retz";320;"17-03-2014";"19:00";12,5;;58;282;9;275;37,4;0;1016,8;978,9;0
11035;"Wien/Hohe Warte";203;"17-03-2014";"19:00";14,5;3,6;49;336;6,1;277;31,3;0;1016,3;991,6;0
11036;"Wien/Schwechat";183;"17-03-2014";"19:00";14,2;3,3;48;320;16,6;;29,5;0;1016,3;994,9;0
11101;"Bregenz";424;"17-03-2014";"19:00";11,7;4,4;62;122;6,5;106;8,3;0;1020,2;968,5;30
11121;"Innsbruck";579;"17-03-2014";"19:00";11,2;1,5;52;314;2,9;256;9,7;0;1018,8;950,3;0
11126;"Patscherkofel";2247;"17-03-2014";"19:00";3,8;-9,2;38;324;28,4;317;44,3;0;;778,1;0
11130;"Kufstein";495;"17-03-2014";"19:00";14,5;1,2;41;9;7,6;15;15,5;0;1018,1;960,8;0
11150;"Salzburg";430;"17-03-2014";"19:00";13,1;2,3;50;290;5,4;;11,2;0;1018,5;966,2;0
11155;"Feuerkogel";1618;"17-03-2014";"19:00";5,8;-0,7;63;286;18,7;287;50,8;0;;838,9;0
11157;"Aigen im Ennstal";640;"17-03-2014";"19:00";12,9;2,3;48;229;7,9;273;22,7;0;1017,9;942,4;0
11171;"Mariazell";866;"17-03-2014";"19:00";10,7;1,3;53;18;1,1;335;17,3;0;1017,5;918,1;0
11190;"Eisenstadt";184;"17-03-2014";"19:00";15,7;5,4;50;325;12,6;306;29,5;0;1016,1;994,6;0
11204;"Lienz";659;"17-03-2014";"19:00";10,8;-1,5;43;290;13,3;273;24,1;0;1018,6;940,7;0
11240;"Graz/Flughafen";340;"17-03-2014";"19:00";18,4;-1,6;26;340;11,2;;14,8;0;1015,3;973,3;0
11244;"Bad Gleichenberg";280;"17-03-2014";"19:00";17,3;;47;59;7,9;71;23;0;1015,9;984,2;0
11265;"Villacher Alpe";2140;"17-03-2014";"19:00";4,8;-8;39;277;25,9;269;33,5;0;;786;16
11331;"Klagenfurt/Flughafen";447;"17-03-2014";"19:00";14,7;-0,2;36;31;2,5;326;11,5;0;1016,3;963,6;0
11343;"Sonnblick";3105;"17-03-2014";"19:00";-3,3;-14,7;42;295;27;287;56,2;0;;698,4;19
11389;"St. Pölten";270;"17-03-2014";"19:00";13,5;6,3;62;217;6,8;249;21,6;0;1017,4;985,5;0
*/


/* Hinweis: scanf
%*i
bedeutet: überlies Ziffern. Ein Argument braucht nicht angegeben werden.

\"%[^\"]
bedeutet: lies den Text zwischen " und "
Bsp: "abc" ... es wird abc gelesen


%*[^\n]
bedeutet: überlies bis ein Enter kommt
*/

