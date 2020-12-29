package webservice;


import javax.xml.ws.Endpoint;

public class CalculatorServer {

	public static void main (String args[]) {
		Calculator service = new Calculator();
		
		Endpoint endpoint = Endpoint.publish("http://localhost:8080/calculator", service);
	}
}
