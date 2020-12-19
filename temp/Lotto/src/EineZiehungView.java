import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.GridBagLayout;
import javax.swing.JButton;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JLabel;
import javax.swing.border.TitledBorder;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;


public class EineZiehungView extends JFrame implements Observer{
	// VIEW-Elemente
	private JPanel contentPane;
	private JButton btnZiehung;
	private JButton btnEnde;
	private JLabel label;
	
	// MODEL
	Model model;


	/**
	 * Create the frame.
	 */
	public EineZiehungView() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 307, 175);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		contentPane.add(getLabel());
		contentPane.add(getBtnZiehung());
		contentPane.add(getBtnEnde());
	}

	public void setModel(Model m){
		// Das Model merken
		model=m;
		
	}
	
	private JButton getBtnZiehung() {
		if (btnZiehung == null) {
			btnZiehung = new JButton("Ziehung");
			btnZiehung.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					model.doZiehung();
				}
			});
			btnZiehung.setBounds(12, 92, 93, 25);
		}
		return btnZiehung;
	}
	private JButton getBtnEnde() {
		if (btnEnde == null) {
			btnEnde = new JButton("Ende");
			btnEnde.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					System.exit(0);
					
				}
			});
			btnEnde.setBounds(206, 92, 69, 25);
		}
		return btnEnde;
	}
	private JLabel getLabel() {
		if (label == null) {
			label = new JLabel("");
			label.setBounds(12, 23, 263, 57);
			label.setBorder(new TitledBorder(null, "Die Zahlen der letzten Ziehung", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		}
		return label;
	}

	@Override
	public void update(Observable o, Object arg) {
		// Daten holen
		Model m= (Model)o;
		int[] zahlen= m.getData();
		
		//anzeigen
		String s= "";
		
		for (int i = 0; i < zahlen.length; i++) {
			s+= String.valueOf(zahlen[i]) + ", ";
		}
		System.out.println(s);
		label.setText(s);
	}
}
