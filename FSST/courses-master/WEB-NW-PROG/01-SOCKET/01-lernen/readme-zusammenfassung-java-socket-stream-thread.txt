================================
-- SOCKET -CLIENT
================================

* Benötigte Objekte
-------------------------------
	private Socket socket=null;
	private PrintWriter bout=null;
	private BufferedReader bin=null;



* Objekte erzeugen
-------------------------------
	try{
		if (socket != null)
			socket.close();
	
		socket= new Socket("localhost", 51234);
	
		InputStream in = socket.getInputStream();
		OutputStream out = socket.getOutputStream();
		
		bin = new BufferedReader(new InputStreamReader(in));
		bout= new PrintWriter(new OutputStreamWriter(out));
		
	}catch(IOException e1){
			System.err.println(e.paramString());
	}


	
	
* Beispiel zum Schreiben/Lesen
-------------------------------
	try {
		//Schreiben
		bout.println("Sockets sind super!!!!");
		bout.flush();	// !!!!!!!!!!!!!!!!
		
		
		//Lesen						
		String line= bin.readLine();
		
		// auf die Konsole ausgeben
		System.out.println(line);
								
								
	} catch (IOException e1) {
		e1.printStackTrace();
	}


* Schliessen
----------------------------
	bin.close();
	bout.close();
	socket.close();
	



================================
-- SOCKET -SERVER
================================

Der Main-Thread nimmt die Verbindungsanforderung des Client an
und startet einen Service-Process, der dann die eigentliche
Kommunikation mit dem Client übernimmt.
--------------------------------------------------------------


import java.net.*;
import java.io.*;

/**
 * a.hofmann,
 *  
 * Der Server
 * soll von der Konsole aus gestartet werden
 * start->ausführen->cmd
 * cd workspace\SocketPingPong
 * java SocketPong
 *
 * siehe auch: netstat -a
 */


/**
 * -------------------------------------------------------------
 * MAIN Thread 
 * ------------------------------------------------------------- 
 */
public class SocketPong{	
	// Netzwerk
	private static int count=0;
	
	public static void main(String[] args) {
    	System.out.println("Warte auf Verbindung auf 51234");

        try {
	        ServerSocket listen_sock;
							
	        listen_sock = new ServerSocket(51234);
					        
			while (true){ // Server luft immer
				// warte auf einen Client-Anforderung
	        	Socket socket = listen_sock.accept();
				
	        	// starte Service Thread
	        	count++;
	        	Thread serviceThread = new ServiceThread(count, socket);
	        	serviceThread.start();
	        	
	        }// while
		        
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		
	}//main
}


/**
 * -------------------------------------------------------------
 * ServiceThread 
 * ------------------------------------------------------------- 
 */ 
class ServiceThread
extends Thread {
	private String name=null;
	private Socket socket=null;
	private BufferedReader bin= null;
	private PrintWriter bout=null;
	
	public ServiceThread(int nr, Socket socket) {
		// Konstruktor der Oberklasse aufrufen 
		super();
		
		try{
			name= "ServiceThread: " + nr;
			this.socket= socket;
			InputStream in= socket.getInputStream();
			OutputStream out= socket.getOutputStream();
			bin= new BufferedReader( new InputStreamReader(in));
			bout= new PrintWriter(new OutputStreamWriter(out));
			
			this.setName(name);
			
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}
	
	
	
	public void run(){
    	System.out.println(name + " gestartet ...");

		// Liest vom Client und schreibt zum client
		// Abbruch, wenn Client die Verbindung schliesst

		try{	
			String s;
			s= bin.readLine();
			while (null != s){
		    	System.out.println(name + " got: " + s);

				bout.println(s);
				bout.flush(); //!!!!!!!!!!!!!!!
				
				s= bin.readLine();
			}//while
		
			// Schliessen
			if (null != bout) bout.close();
			if (null != bin) bin.close();
			if (null != socket) socket.close();
		} catch (IOException e1) {
			e1.printStackTrace();
		}				
	}
}

