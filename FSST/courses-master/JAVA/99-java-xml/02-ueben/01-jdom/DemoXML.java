import java.io.IOException;
//jdom*.jar ins c:\programme\java\jdk\jre\lib\ext\jdom.jar kopieren
// fertig !	

public class DemoXML {
	public static void main(String[] args) {
		// Aufbau von inventar.xml
		// <gegenstaende>
		//		<gegenstand><Bezeichnung>......</gegenstand>
		//		<gegenstand><Bezeichnung>.......</gegenstand>
		// </gegentaende>
		//

		String bezeichnung;
		int angriffswert;
		int verteidigungswert;
		int heilwert;
		int gewicht;
		
		try{
		try{
		org.jdom.input.SAXBuilder builder= new org.jdom.input.SAXBuilder();
		org.jdom.Document doc = builder.build( "inventar.xml" );
							
		//Lesen des Wurzelelements des JDOM-Dokuments doc
		org.jdom.Element rootElement =   doc.getRootElement();
		
		//Lesen der einzelenen Gegenstände
		java.util.List gegenstaende = rootElement.getChildren("gegenstand"); 
		java.util.Iterator it= gegenstaende.iterator();
		
		while (it.hasNext()){
			org.jdom.Element gegenstand= (org.jdom.Element) it.next(); //lade nächsten gegenstand
			
			bezeichnung= gegenstand.getChild("Bezeichnung").getTextTrim();			        	
        	angriffswert= java.lang.Integer.parseInt(gegenstand.getChild("Angriffswert").getTextTrim());
        	verteidigungswert= java.lang.Integer.parseInt(gegenstand.getChild("Verteidigungswert").getTextTrim());
        	heilwert= java.lang.Integer.parseInt(gegenstand.getChild("Heilungswert").getTextTrim());
        	gewicht= java.lang.Integer.parseInt(gegenstand.getChild("Gewicht").getTextTrim());
        	
        	
        	System.out.println ("....................................");
        	System.out.println ("Bezeichnung: " + bezeichnung);
        	System.out.println ("Angriffswert: " + angriffswert);
        	System.out.println ("Verteidigungswert: " + verteidigungswert);
        	System.out.println ("Heilungswert: " + heilwert);
        	System.out.println ("Gewicht: " + gewicht);
        	
		}//while
		
		}catch(IOException ex){
			ex.printStackTrace(System.out);
			}
		
		}catch(org.jdom.JDOMException ex1){
			ex1.printStackTrace(System.out);
		}		
	}
}
