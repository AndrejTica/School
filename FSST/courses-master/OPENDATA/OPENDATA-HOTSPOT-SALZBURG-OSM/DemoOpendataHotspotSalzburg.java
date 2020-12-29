import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.net.Authenticator;
import java.net.HttpURLConnection;
import java.net.PasswordAuthentication;
import java.net.URL;

import javax.swing.JOptionPane;
import javax.swing.JPasswordField;

// hofmann, 2014
// javac DemoOpendataHotspotSalzburg.java
// java DemoOpendataHotspotSalzburg


public class DemoOpendataHotspotSalzburg {
    // URL
	private static final String sUrl= "https://data.stadt-salzburg.at/geodaten/wfs?service=WFS&version=1.1.0&request=GetFeature&srsName=urn:x-ogc:def:crs:EPSG:4326&outputFormat=csv&typeName=ogdsbg:wlanhotspot";


	public static void main(String[] args) throws IOException {
		// PROXY BEGIN
		// -------------------------------------------------------------------------------------------
		// PROXY
/*		System.setProperty("http.proxyHost","tmg-z2.htl.org") ;
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
*/
		// PROXY END
		// -------------------------------------------------------------------------------------------



		// Verbindung aufbauen
		// -------------------------------------------------------------------------------------------
		URL url = new URL(sUrl);
		HttpURLConnection con = (HttpURLConnection) url.openConnection();


		// opendata lesen und auf console ausgeben
		Reader is = new InputStreamReader( con.getInputStream() );
		BufferedReader in = new BufferedReader( is );
	


		for ( String s; ( s = in.readLine() ) != null; ){
			System.out.println( s );
		}

		in.close();
	}
}
