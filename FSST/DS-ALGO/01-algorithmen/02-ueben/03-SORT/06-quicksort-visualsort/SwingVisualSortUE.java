/**
 * SwingVisualSortUE
 * 1. Bringen Sie folg. Programm zum Laufen
 * 2. Implementieren Sie die beiden Algorithmen: 
 * 		SelectionSort und
 * 		Quicksort
 * 
 */
import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import java.awt.CardLayout;
import java.awt.GridLayout;
import javax.swing.JDesktopPane;
import java.awt.Rectangle;
import java.awt.GridBagLayout;
import java.awt.Dimension;
import javax.swing.BorderFactory;
import java.awt.Color;
import java.text.SimpleDateFormat;

import javax.swing.JTextField;
import javax.swing.border.TitledBorder;
import java.awt.Font;

public class SwingVisualSortUE extends JFrame {

	private static final long serialVersionUID = 1L;
	private JDesktopPane jDesktopPane = null;
	private JPanel jPanel = null;
	private JButton jButtonMischen = null;
	private JButton jButtonBubble = null;
	private JButton jButtonQuickSort = null;
	private JButton jButtonEnde = null;
	private JButton jButtonSelection = null;
	private JTextField jTextFieldDauer = null;

	// meine nur hier sichtbaren glob. Variablen
	private int[] a;
	private int anzahl;	//ArrayLaenge
	private int maxWert; //größtmöglicher Wert im Array
	
	
	/**
	 * Algorithmen
	 * -----------------------------------------------------------
	 */

	private void bubblesort(){
		java.awt.Graphics g= jPanel.getGraphics();		 
		
		boolean fertig=false;
		while (fertig==false)
		{
			fertig= true;
			
			for (int i=0; i < anzahl -1; i++)
			{
				if (a[i]> a[i+1])
				{
					int help;
					
					//austauschen
					//löschen
					g.setColor(Color.blue);
					g.drawRect(i, a[i],1,1);
					g.drawRect(i+1, a[i+1],1,1);
					
					help=a[i];
					a[i]= a[i+1];
					a[i+1]= help;
					
					fertig= false;
					
					g.setColor(Color.yellow);
					g.drawRect(i, a[i],1,1);
					g.drawRect(i+1, a[i+1],1,1);
				}// if
			}//for
		}//while
		
		//repaint();  
		//ruft update() auf --> löscht das Window (JFrame)
		//ruft paint() auf 
	}
		
	
	private void quicksort(int left, int right){
	//TODO qsort programmieren
	}
	
	private void selectionsort(int left, int right){
		//TODO selectionsort programmieren
	}
		
	
	
	public void mischen(){
		
		java.util.Random zufall= new java.util.Random();
		java.awt.Graphics g= jPanel.getGraphics();
		
		this.setTitle("Sortieren: Anzahl der Arrayelemente: "+anzahl+" (http://sortieralgorithmen.de) und und www.delphiseiten.de/lex10/sort/selection.html");
		
		jTextFieldDauer.setText("0");

		//alles löschen
		g.setColor(Color.blue);
		g.fillRect(0, 0,  jPanel.getWidth(), jPanel.getHeight());
		
		// array mit Zufallszahlen setzen
		for (int i=0; i < anzahl; i++)
			a[i]= zufall.nextInt(maxWert);
		
		//array anzeigen
		//  array-index ..... X-Koord
		//   array-wert  .... Y-Koord
		g.setColor(java.awt.Color.yellow);
		for (int i=0; i < anzahl; i++)
			g.drawRect(i, a[i], 1,1);

	}
	
	/**
	 * Algorithmen
	 * -----------------------------------------------------------
	 */

	/**
	 * wenn das Window neu gezeichnet werden muss,
	 * wird das Ereignis PAINT aktiviert
	 * JRE versucht in unserem Programm die Methode
	 * paint aufzurufen.
	 */
	public void paint(java.awt.Graphics g){
		// Zeichne das gesamte Formular/Window neu
		super.paint(g);
		
		// Zeichne den Panelinhalt neu
		java.awt.Graphics graphPanel= jPanel.getGraphics();
		
		int w= jPanel.getWidth();
		int h= jPanel.getHeight();
		
		// panel löschen
		graphPanel.setColor(Color.blue);
		graphPanel.fillRect(0, 0, w, h);
		
		// Punkte setzen
		graphPanel.setColor(Color.yellow);
		for (int i=0; i< anzahl; i++)
			graphPanel.drawRect(i, a[i],1,1);
		
	}
	
	/**
	 * This method initializes jDesktopPane	
	 * 	
	 * @return javax.swing.JDesktopPane	
	 */
	private JDesktopPane getJDesktopPane() {
		if (jDesktopPane == null) {
			jDesktopPane = new JDesktopPane();
			jDesktopPane.add(getJPanel(), null);
			jDesktopPane.add(getJButtonMischen(), null);
			jDesktopPane.add(getJButtonBubble(), null);
			jDesktopPane.add(getJButtonQuickSort(), null);
			jDesktopPane.add(getJButtonEnde(), null);
			jDesktopPane.add(getJButtonSelection(), null);
			jDesktopPane.add(getJTextFieldDauer(), null);
		}
		return jDesktopPane;
	}

	/**
	 * This method initializes jPanel	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getJPanel() {
		if (jPanel == null) {
			jPanel = new JPanel();
			jPanel.setLayout(new GridBagLayout());
			jPanel.setBounds(new Rectangle(14, 52, 1093, 554));
			jPanel.setBackground(Color.blue);
			jPanel.setBorder(BorderFactory.createCompoundBorder(BorderFactory.createCompoundBorder(null, null), null));
		}
		return jPanel;
	}

	/**
	 * This method initializes jButtonMischen	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonMischen() {
		if (jButtonMischen == null) {
			jButtonMischen = new JButton();
			jButtonMischen.setBounds(new Rectangle(74, 13, 96, 25));
			jButtonMischen.setText("Mischen");
			jButtonMischen.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
				
					mischen();
				
				}
			});
		}
		return jButtonMischen;
	}

	
	/**
	 * This method initializes jButtonBubble	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonBubble() {
		if (jButtonBubble == null) {
			jButtonBubble = new JButton();
			jButtonBubble.setBounds(new Rectangle(214, 13, 96, 25));
			jButtonBubble.setText("Bubble");
			jButtonBubble.addActionListener(new java.awt.event.ActionListener() 
			{
				public void actionPerformed(java.awt.event.ActionEvent e) 
				{

					java.util.Date dstart= new java.util.Date();
					
					bubblesort();
					
					java.util.Date dstop= new java.util.Date();
					
					long dauer_ms= dstop.getTime() - dstart.getTime();
					jTextFieldDauer.setText(String.valueOf(dauer_ms));

				}
			
			});
		}
		return jButtonBubble;
	}

	
	
	
	
	/**
	 * This method initializes jButtonQuickSort	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonQuickSort() {
		if (jButtonQuickSort == null) {
			jButtonQuickSort = new JButton();
			jButtonQuickSort.setBounds(new Rectangle(494, 13, 109, 25));
			jButtonQuickSort.setText("Quick");
			jButtonQuickSort.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {			
				
					java.util.Date dstart= new java.util.Date();

					quicksort(0, anzahl-1);
					
					java.util.Date dstop= new java.util.Date();
					
					long dauer_ms= dstop.getTime() - dstart.getTime();
					jTextFieldDauer.setText(String.valueOf(dauer_ms));
					
				
				}
			});
		}
		return jButtonQuickSort;
	}

	/**
	 * This method initializes jButtonEnde	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonEnde() {
		if (jButtonEnde == null) {
			jButtonEnde = new JButton();
			jButtonEnde.setBounds(new Rectangle(647, 13, 96, 25));
			jButtonEnde.setText("Ende");
			jButtonEnde.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					System.exit(0);
				
				
				}
			});
		}
		return jButtonEnde;
	}

	/**
	 * This method initializes jButtonSelection	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonSelection() {
		if (jButtonSelection == null) {
			jButtonSelection = new JButton();
			jButtonSelection.setBounds(new Rectangle(354, 13, 96, 25));
			jButtonSelection.setText("Selection");
			jButtonSelection.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					java.util.Date dstart= new java.util.Date();

					selectionsort(0, anzahl-1);
					
					java.util.Date dstop= new java.util.Date();
					
					long dauer_ms= dstop.getTime() - dstart.getTime();
					jTextFieldDauer.setText(String.valueOf(dauer_ms));
					

				}
			});
		}
		return jButtonSelection;
	}

	/**
	 * This method initializes jTextFieldDauer	
	 * 	
	 * @return javax.swing.JTextField	
	 */
	private JTextField getJTextFieldDauer() {
		if (jTextFieldDauer == null) {
			jTextFieldDauer = new JTextField();
			jTextFieldDauer.setBounds(new Rectangle(787, 5, 124, 42));
			jTextFieldDauer.setBorder(BorderFactory.createTitledBorder(null, "Dauer in ms", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, new Font("Microsoft Sans Serif", Font.PLAIN, 11), new Color(0, 70, 213)));
			jTextFieldDauer.setText("0");
		}
		return jTextFieldDauer;
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				SwingVisualSortUE thisClass = new SwingVisualSortUE();
				thisClass.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				thisClass.setVisible(true);
			}
		});
	}

	/**
	 * This is the default constructor
	 */
	public SwingVisualSortUE() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(1123, 653);
		this.setContentPane(getJDesktopPane());
		this.setTitle("Visuelles Sortieren: http://sortieralgorithmen.de und www.delphiseiten.de/lex10/sort/selection.html");
		this.addWindowListener(new java.awt.event.WindowAdapter() {
			public void windowOpened(java.awt.event.WindowEvent e) {

				anzahl= jPanel.getWidth();
				maxWert= jPanel.getHeight();
				
				a= new int[anzahl];
				
				mischen();

			}
		});
		
		
	}

}  //  @jve:decl-index=0:visual-constraint="-11,-130"
