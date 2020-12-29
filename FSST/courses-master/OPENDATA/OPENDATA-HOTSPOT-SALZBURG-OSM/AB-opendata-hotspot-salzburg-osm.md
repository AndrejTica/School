# OPENDATA und SALZBURG (Hotspot)
 

## Vorbereitung

* Entpacken Sie die Datei **DEMO-openstreetmap-mit-textfile.zip**
 
	Dateien: 

	* index.html
	* textfile.txt
	* Ol_icon_blue_example.png
	* Ol_icon_red_example.png


* Laden Sie mit Ihrem Webbrowser die Datei **index.html** 
(Menü: Datei->öffnen) und testen Sie die Funktionalität.

>> Tipp: Achten Sie auf den richtigen Aufbau (Tabulator) der Datei 
**textfile.txt**


## PROGRAMM: opendata-hotspot-salzburg-osm.c

* Laden Sie die Datei **wlanhotspot.csv** von 
<https://www.data.gv.at/datensatz/?id=4b901b6b-f131-49f7-ba8b-2e3b7bfd4ea6>


>> siehe unten Hinweis: OPENDATA Netzwerkzugriff 


* Lesen Sie die Datei **wlanhotspot.csv** ein und erstellen Sie die Datei 
**textfile.txt**

		
* Laden Sie mit Ihrem Webbrowser die Datei **index.html** (Menü: Datei->öffnen)
		und testen Sie die Funktionalität.
		Tipp: Achten Sie auf den richtigen Aufbau (Tabulator) der Datei textfile.txt



## HINWEIS: textfile.txt, index.html, wlanhotspot.csv
* Studieren Sie: <http://wiki.openstreetmap.org/wiki/Openlayers_POI_layer_example>

## HINWEIS: wlanhotspot.csv
	FID,GEOMETRIE,STANDORTNAME,HOMEPAGE,BEMERKUNG
	wlanhotspot.gisdb.21108,POINT (47.80208666428231 13.044696183497496),Salzburg surft Hotspot - BRICKS Music-Bar,http://www.salzburg-surft.at/hotspot-locations/bricks-music-bar/,Aufstelljahr: 2011
	wlanhotspot.gisdb.21109,POINT (47.78330855822309 13.080045699456964),Salzburg surft Hotspot - BWS Aigen,http://www.salzburg-surft.at/hotspot-locations/bws-aigen/ ,Aufstelljahr: 2013
	wlanhotspot.gisdb.21110,POINT (47.80891311800401 13.061969610720691),Salzburg surft Hotspot - BWS Gnigl,http://www.salzburg-surft.at/hotspot-locations/bws-gnig/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21111,POINT (47.82475165387156 13.045492617811695),Salzburg surft Hotspot - BWS Itzling,http://www.salzburg-surft.at/hotspot-locations/bws-itzling/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21112,POINT (47.788189707412734 13.07633640575754),Salzburg surft Hotspot - Cafe Dialog,http://www.salzburg-surft.at/hotspot-locations/cafe-dialog/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21114,POINT (47.78956567199874 13.035478347359131),Salzburg surft Hotspot - Freibad Leopoldskron,http://www.salzburg-surft.at/hotspot-locations/freibad-leopoldskron/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21115,POINT (47.77606246966332 13.071751307716475),Salzburg surft Hotspot - Gesundheitszentrum Sued,http://www.salzburg-surft.at/hotspot-locations/gsz-sued/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21116,POINT (47.81017702593366 13.030521686296531),Salzburg surft Hotspot - Inge-Morath-Platz,http://www.salzburg-surft.at/hotspot-locations/inge-morath-platz/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21117,POINT (47.80712622357241 13.066010187997676),Salzburg surft Hotspot - Jugendzentrum get2gether,http://www.salzburg-surft.at/hotspot-locations/juz-get2gether/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21118,POINT (47.80632504270535 13.046060483983911),Salzburg surft Hotspot - Jugendzentrum IGLU,http://www.salzburg-surft.at/hotspot-locations/juz-iglu/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21119,POINT (47.78790875216644 13.019630581864392),Salzburg surft Hotspot - Jugendzentrum KOMM,http://www.salzburg-surft.at/hotspot-locations/juz-komm/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21120,POINT (47.81463693761094 13.026230174761325),Salzburg surft Hotspot - Jugendzentrum Lehen,http://www.salzburg-surft.at/hotspot-locations/juz-lehen/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21121,POINT (47.81106329021125 13.006274636108788),Salzburg surft Hotspot - Jugendzentrum Taxham,http://www.salzburg-surft.at/hotspot-locations/juz-taxham/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21122,POINT (47.79704378324846 13.051839540152114),Salzburg surft Hotspot - Kajetanerplatz,http://www.salzburg-surft.at/hotspot-locations/kajetanerplatz/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21123,POINT (47.79691158787558 13.046628065352198),Salzburg surft Hotspot - Kapitelplatz,http://www.salzburg-surft.at/hotspot-locations/kapitelplatz/,Aufstelljahr: 2013
	wlanhotspot.gisdb.21124,POINT (47.801704568083714 13.04214719528929),Salzburg surft Hotspot - Makartsteg,http://www.salzburg-surft.at/hotspot-locations/makartsteg/,Aufstelljahr: 2011
	wlanhotspot.gisdb.21125,POINT (47.804564853462836 13.043145395240149),Salzburg surft Hotspot - Mirabellgarten,http://www.salzburg-surft.at/hotspot-locations/mirabellgarten/,Aufstelljahr: 2011
	wlanhotspot.gisdb.21126,POINT (47.798688278267 13.047936761961587),Salzburg surft Hotspot - Mozartplatz,http://www.salzburg-surft.at/hotspot-locations/mozartplatz/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21127,POINT (47.80040727226709 13.044893879702833),Salzburg surft Hotspot - Rathaus,http://www.salzburg-surft.at/hotspot-locations/rathaus-salzburg/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21128,POINT (47.813591021619935 13.027612786249824),Salzburg surft Hotspot - Stadt:Bibliothek Salzburg,http://www.salzburg-surft.at/hotspot-locations/stadtbibliothek-salzburg/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21129,POINT (47.79643460980809 13.060197478354686),Salzburg surft Hotspot - Volksgarten,http://www.salzburg-surft.at/hotspot-locations/volksgarten/,Aufstelljahr: 2012
	wlanhotspot.gisdb.21130,POINT (47.76281638251832 13.060395900792235),Salzburg surft Hotspot - Hellbrunn Wasserspiele Kassa,,Aufstelljahr: 2013
	wlanhotspot.gisdb.21131,POINT (47.76284883856024 13.065363326629926),Salzburg surft Hotspot - Hellbrunn Spielplatz/Park,,Aufstelljahr: 2013
	wlanhotspot.gisdb.21132,POINT (47.82262505699751 13.04107044930563),Salzburg surft Hotspot - CoWorkingSpace Salzburg,http://www.salzburg-surft.at/hotspot-locations/coworking-space-salzburg/,Aufstelljahr: 2012

## Hinweis: char * strtok(char *string, char *delimiters);
	char string[] = "Kurt,Kanns;555678;DE";
	char delimiter[] = ",;";
	char *ptr;

	// initialisieren und ersten Abschnitt erstellen
	ptr = strtok(string, delimiter);

	while(ptr != NULL) {
		printf("Abschnitt gefunden: %s\n", ptr);
		// naechsten Abschnitt erstellen
	 	ptr = strtok(NULL, delimiter);
	}

	Abschnitt gefunden: Kurt
	Abschnitt gefunden: Kanns
	Abschnitt gefunden: 555678
	Abschnitt gefunden: DE



## Hinweis: OPENDATA Netzwerkzugriff (C)
Verwenden Sie wget bzw. curl bzw. ....
zB: 

	`system("wget \"http://data.stadt-salzburg.at/geodaten/wfs?service=WFS&version=1.1.0&request=GetFeature&srsName=urn:x-ogc:def:crs:EPSG:4326&outputFormat=csv&typeName=ogdsbg:wlanhotspot\" -O wlanhotspot.csv");`



## Hinweis: OPENDATA Netzwerkzugriff (Java)
```
...
public class Main {
	private static final String sUrl= "https://data.stadt-salzburg.at/geodaten/wfs?service=WFS&version=1.1.0&request=GetFeature&srsName=urn:x-ogc:def:crs:EPSG:4326&outputFormat=csv&typeName=ogdsbg:wlanhotspot";

	public static void main(String[] args) throws IOException {
		// PROXY BEGIN
		// -------------------------------------------------------------------------------------------
		// PROXY
		System.setProperty("http.proxyHost","tmg-z2.htl.org") ;
		System.setProperty("http.proxyPort", "8080") ;

		Authenticator.setDefault(new Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {

				// pwd lesen
				JPasswordField passwordField = new JPasswordField(10);
				passwordField.setEchoChar('*');
				
				JOptionPane.showMessageDialog ( null, passwordField, "Enter password", JOptionPane.OK_OPTION );
				char[] chars = passwordField.getPassword();
				String pwd = new String(chars);


				return new
						PasswordAuthentication("htl\\ahofmann",pwd.toCharArray());
			}});

		// PROXY END
		// -------------------------------------------------------------------------------------------



		// Verbindung aufbauen
		// -------------------------------------------------------------------------------------------
		URL url = new URL(sUrl);
		HttpURLConnection con = (HttpURLConnection) url.openConnection();

		// Daten lesen
		// wlanhotspot.csv
		// FID,GEOMETRIE,STANDORTNAME,HOMEPAGE,BEMERKUNG
		//wlanhotspot.gisdb.21108,POINT (47.80208666428231 13.044696183497496),Salzburg surft Hotspot - BRICKS Music-Bar,http://www.salzburg-surft.at/hotspot-locations/bricks-music-bar/,Aufstelljahr: 2011
		
		// textfile.txt
		//lat	lon	title	description	icon	iconSize	iconOffset
		//48.9459301	9.6075669	Title One	Description one	Ol_icon_blue_example.png 24,24	0,-24

		// opendata lesen		
		Reader is = new InputStreamReader( con.getInputStream() );
		BufferedReader in = new BufferedReader( is );
...
```
