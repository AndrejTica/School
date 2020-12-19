import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

import java.util.Observer;
import java.util.Observable;


public class AlleZiehungenView extends JFrame implements Observer {
	// View
	private JPanel contentPane;
	private JTextArea textArea;
	private JScrollPane jscrollpane;

	// Model
	Model model;

	public AlleZiehungenView(){
		setTitle("Alle Ziehungen");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(400,100,300,300);
		contentPane= new JPanel();
		contentPane.setBorder(new EmptyBorder(5,5,5,5));
		contentPane.setLayout(null);
		contentPane.add(getTextArea());
		
		setContentPane(contentPane);
	}

	public JScrollPane getTextArea(){
		if (textArea==null){
			textArea= new JTextArea();
			textArea.setBounds(5, 5, 100, 100);
			jscrollpane= new JScrollPane(textArea);
			jscrollpane.setBounds(5,5,200,200);
		}
		return jscrollpane;
	}

	public void setModel(Model m){
		model= m;
	}


	@Override
	public void update(Observable o, Object arg){
		Model m= (Model)o;
		int[] zahlen= m.getData();
		
		//anzeigen
		String s= "";
		
		for (int i = 0; i < zahlen.length; i++) {
			s+= String.valueOf(zahlen[i]) + ", ";
		}
		System.out.println(s);
		textArea.append(s + "\n");
	}

}
