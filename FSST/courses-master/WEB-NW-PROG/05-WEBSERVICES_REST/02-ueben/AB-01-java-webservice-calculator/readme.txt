http://www.theserverside.de/webservice-in-java/
========================================================================
todo: setze statt 192.168.2.15 die richtige Adresse ein.
(wir arbeiten diesmal ohne eclipse; also nur mit vi und console)




Ordnerstruktur: am Server (zB: Beagelboard)
-------------------------------------------------------------------------
mkdir WebService
mkdir WebService/WebService-calc-serverside
mkdir WebService/WebService-calc-serverside/webservice



Ordnerstruktur: am Client (zB: Desktop)
-------------------------------------------------------------------------
mkdir WebService
mkdir WebService/WebService-calc-clientside
mkdir WebService/WebService-calc-clientside/webservice





1. zuerst Serverside (zB: BB) folg. erstellen:
------------------------------------------------------------------------	
	1.1. cd WebService/WebService-calc-serverside/webservice
		
	1.2. Erstelle die Dateien: (Quellcode: siehe unten)
		Calculator.java			// die eigentlichen Funktionen
		CalculatorServer.java	// der Zugriff via SOAP/HTTP
			Anmerkung: In CalculatorServer.java 
					setze statt 192.168.2.15 die richtige Adresse ein
 
 
	1.3. Übersetze die beiden Programme mit
		cd WebService/WebService-calc-serverside/
		
		javac webservice/Caculator.java
		javac webservice/CaculatorServer.java


	1.4. Starte webservice mit
		java webservice.CalculatorServer



2. dann Clientside (zB: Desktop)
------------------------------------------------------------------------	
	2.1. cd WebService/WebService-calc-clientside

	2.2. wsimport -keep http://192.168.2.15:8080/calculator?wsdl
			TODO: setze statt 192.168.2.15 die richtige Adresse ein (s. oben)
	
	2.3. Client-Klasse erstellen
		cd WebService/WebService-calc-clientside/webservice
		
		Erstelle die Datei: (Quellcode: siehe unten)
		CalculatorClient.java	


	2.3. Client-Klasse übersetzen
		cd WebService/WebService-calc-clientside/
		javac webservice/CalculatorClient.java 

	2.4. Client-Klasse starten
		cd WebService/WebService-calc-clientside/
		java webservice.CalculatorClient

	

FERTIG!!!!!


Hier der jeweilige Quellcode:
==================================================================================
SERVICE (serverside)
==================================================================================
Calculator.java
----------------
package webservice;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;

@WebService
@SOAPBinding(style=Style.RPC)

public class Calculator {
	public long add(int val1, int val2) {
		return val1 + val2;
	}

	public long min(int val1, int val2) {
		return val1 - val2;
	}
	
	public long mul(int val1, int val2) {
		return val1 * val2;
	}

	public long div(int val1, int val2) {
		return val1 / val2;
	}

}


==================================================================================
SERVER (serverside)
==================================================================================
CalculatorServer.java
----------------------
package webservice;
import javax.xml.ws.Endpoint;

public class CalculatorServer {

	public static void main (String args[]) {
		Calculator service = new Calculator();
		
		Endpoint endpoint = Endpoint.publish("http://192.168.2.15:8080/calculator", service);
	}
}





==================================================================================
CLIENT (clientside)
==================================================================================
CalculatorClient.java
------------------------
package webservice;

// bezug auf generierte STUBS
import webservice.Calculator;
import webservice.CalculatorService;


 public class CalculatorClient {
    public static void main(String args[]) {
        
    	CalculatorService service = new CalculatorService();
        
        Calculator calculator = service.getCalculatorPort();
        
        System.out.println("Summe: " + calculator.add(17, 13));
    }
}
