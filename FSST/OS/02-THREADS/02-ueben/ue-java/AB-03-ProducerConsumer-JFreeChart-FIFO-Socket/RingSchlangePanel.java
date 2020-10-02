import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;


public class RingSchlangePanel extends JPanel implements Observer{
	private JLabel[] left= new JLabel[10]; 
	private JLabel[] center= new JLabel[10]; 
	private JLabel[] right= new JLabel[10]; 

	private JLabel lbltitle;
	private JPanel contentPanel;


	/**
	 * Creates a new demo panel.
	 */
	public RingSchlangePanel() {

		super(new BorderLayout());

		// title
		lbltitle= new JLabel("Fifo");
		lbltitle.setHorizontalAlignment(SwingConstants.CENTER);
		lbltitle.setForeground(Color.BLACK);
		lbltitle.setFont(new Font("Lucida Grande", Font.PLAIN, 18));		
		add(lbltitle, BorderLayout.NORTH);

		// die Ringschlange anzeigen		
		contentPanel= new JPanel(new GridLayout(10,3));
		add(contentPanel, BorderLayout.CENTER);


		setPreferredSize(new Dimension(300, 250));

		for (int i = 0; i < 10; i++) {

			left[i]= new JLabel(String.valueOf(i));
			center[i]= new JLabel(String.valueOf(i));
			right[i]= new JLabel(String.valueOf(i));

			left[i].setOpaque(true);
			left[i].setHorizontalAlignment(SwingConstants.RIGHT);
			
			center[i].setOpaque(true);
			right[i].setOpaque(true);

			center[i].setForeground(Color.BLACK);
			center[i].setHorizontalAlignment(SwingConstants.CENTER);
			
			

			contentPanel.add(left[i]);
			contentPanel.add(center[i]);
			contentPanel.add(right[i]);			
		}
		
	}

	
	// Observer-pattern
	@Override
	public void update(Observable arg0, Object arg1) {
		RingSchlange model= (RingSchlange) arg0;
		
		// Daten holen
		String[] values= model.getValues();
		int front= model.getFront();
		int end= model.getEnd();
		
		// Daten anzeigen
		for (int i = 0; i < 10; i++) {
			left[i].setText("");
			right[i].setText("");
			left[i].setBackground(Color.white);
			right[i].setBackground(Color.white);

			center[i].setText(values[i]);
		}

		left[front].setText("front="+String.valueOf(front));
		right[end].setText("end=" + String.valueOf(end));
		left[front].setBackground(Color.green);
		right[end].setBackground(Color.red);

	}
}




