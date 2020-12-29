/*
 * demo-wget-opendata-hotspot-salzburg.c
 *
 * uses: system(), wget(), scanf()
 *
 * Hint: proxy
 * File: /home/informatik/.wgetrc
    proxy_user=username
    proxy_password=password
    http_proxy=http://tmg-z2.htl.org:8080
    https_proxy=http://tmg-z2.htl.org:8080
 *
 *
 * gcc demo-wget-opendata-hotspot-salzburg.c -o demo-wget-opendata-hotspot-salzburg.exe
 *
 * ./demo-wget-opendata-hotspot-salzburg.exe
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>



int main()    {
    int ret;
    
    
    // opendata HOTSPOTs von Salzburg
    system("wget \"http://data.stadt-salzburg.at/geodaten/wfs?service=WFS&version=1.1.0&request=GetFeature&srsName=urn:x-ogc:def:crs:EPSG:4326&outputFormat=csv&typeName=ogdsbg:wlanhotspot\" -O wlanhotspot.csv");
    
    
    system("cat wlanhotspot.csv");
    
    
    return EXIT_SUCCESS;
}


