import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import java.awt.Graphics;

import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.BoxLayout;
import java.awt.GridBagLayout;
import java.awt.CardLayout;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.Rectangle;
import java.awt.Color;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.border.TitledBorder;
import java.awt.Font;

public class GrfLabyrinth extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton jButtonNeu = null;
	private JButton jButtonSuche = null;
	private JButton jButtonEnde = null;
	private JPanel jPanel = null;
	private JTextField jTextFieldSize = null;
	private JTextField jTextFieldSleep = null;
	
	
	// App Vars
	private java.awt.Color a[][];
	private int zeilen, spalten;
	private int w= 4;
	private int h= 4;
	private int verzoegerung= 0;
	Thread threadSuche;

	 	
	java.lang.Runnable doWegSucheRunnable= new Runnable() 
	{
	    public void run() 
	    {
	    	try
			{
				int gefunden;  //  @jve:decl-index=0:
				gefunden= wegSuche(0,0);
				
				if (gefunden==-1){
					JOptionPane.showMessageDialog(null, "Nicht gefunden!");
				}
				else
					JOptionPane.showMessageDialog(null, "Gefunden!");
			}catch(Exception ex)
			{
				ex.printStackTrace(System.out);
			}
		}
	};
	

	
	/**
	 * erstellt ein neues lab im Ram
	 *
	 */
	public void erstelleLabyrinth(){
		// wenn ein Such-Thread läuft, wollen wir diesen
		// unterbrechen
		if (threadSuche != null)
			threadSuche.interrupt();
		
		// lies lab-auflösung
		w= Integer.parseInt(jTextFieldSize.getText());
		h=w; // hoehe ist weite
		
		// lies verzoegerung
		verzoegerung= Integer.parseInt(jTextFieldSleep.getText());
		System.out.println(verzoegerung);
		
		spalten= jPanel.getWidth() / w ;
		zeilen= jPanel.getHeight() / h;
	
		java.util.Random zufall= new java.util.Random();
		
		a= new Color[spalten][zeilen];
		
		//labyrinth erstellen
		for (int x=0; x<spalten; x++){
			for (int y=0; y<zeilen; y++){
				if (zufall.nextInt(100) < 33) //höchstens 1/3 schwarz
					a[x][y]= Color.black;
				else
					a[x][y]= Color.white;
			}
		}
				
		//Umrandung oben und unten zeichnen
		for (int x=0; x<spalten; x++){
			a[x][0]= Color.black;//oben
			a[x][zeilen-1]= Color.black;//unten
		}
		
		//Umrandung links und rechts zeichnen
		for (int y=0; y<zeilen; y++){
			a[0][y]= Color.black;//li
			a[spalten-1][y]= Color.black;//re
		}
		
		//' Eingang und ausgang
		a[0][0]= Color.white;
		a[0][1]=Color.white;
		
		a[spalten-1][zeilen-1]= Color.white;
		a[spalten-1][zeilen-2]= Color.white;
	
	}


	/**
	 * Sucht einen Weg
	 * @param x
	 * @param y
	 * @return
	 */
	int wegSuche(int x, int y) throws InterruptedException{		

		zeichneLab();
		//Thread.sleep(verzoegerung);
		
		// REKURSIONSABBRUCH; REKURSIONSABBRUCH
		
		// Abbruch, wenn ausserhalb des Labs
		if (x <0 || x >= spalten)
			return -1;		
		if (y <0 || y >= zeilen)
			return -1;
		
		// Abbruch, wenn Wand
		if (a[x][y]== Color.black) // Wand
			return -1;
		
		// Abbruch, wenn ich schon da war,
		//und führt nicht zum ziel
		if (a[x][y]== Color.red)
			return -1;

		// Abbruch, wenn ich schon da war,
		//und führt nicht zum ziel
		if (a[x][y]== Color.green)
			return -1;
		
		//Abbruch, wir sind nun am Ziel
		if (x == spalten-1 && y== zeilen -1){
			JOptionPane.showMessageDialog(this, "AM ZIEL!!!!");
			return 1;
		}
		
		
		// REKURSION , REKURSION 
		// suche einen neuen Weg
		
		// markiere momentanen Weg
		a[x][y]= Color.green;

		// suche einen Weg durch das Lab
		
		//---------OBEN		
		if (wegSuche(x, y-1)== 1) { 
			//a[x][y-1]= Color.red;
			return 1;
		}
		//---------RECHTS
		else if (wegSuche(x+1, y)== 1) { 
			//a[x+1][y]= Color.green;
			return 1;
		}
		//---------UNTEN
		else if (wegSuche(x, y+1)== 1) { 
			//a[x][y+1]= Color.red;
			return 1;
		}
		//---------LINKS
		else if (wegSuche(x-1, y)== 1) { 
			//a[x-1][y]= Color.red;
			return 1;
		}		
		
		// wenn wir bis hierher kommen gibts keinen weg
		a[x][y]= Color.red;
		return -1;
	}
	
	// wird durch ein repaint() aktiviert
	public void paint(Graphics g)
	{
		super.paint(g);
		Graphics gr= jPanel.getGraphics();
		for (int x=0; x<spalten; x++){
			for (int y=0; y<zeilen; y++){
				gr.setColor(a[x][y]);
				gr.fillRect(x*w, y*h, w, h);
			}
					
		}
	}
	
	/**
	 *  zeichne das Lab
	 * @throws InterruptedException 
	 *  */
	public void zeichneLab(){
		Graphics gr= jPanel.getGraphics();
		for (int x=0; x<spalten; x++){
			for (int y=0; y<zeilen; y++){
				gr.setColor(a[x][y]);
				gr.fillRect(x*w, y*h, w, h);
			}
					
		}
	}

	// ---------------------------------------------------------------------
	
	/**
	 * This method initializes jButtonNeu	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonNeu() {
		if (jButtonNeu == null) {
			jButtonNeu = new JButton();
			jButtonNeu.setName("jButton");
			jButtonNeu.setText("Neu");
			jButtonNeu.setBounds(new Rectangle(137, 8, 95, 35));
			jButtonNeu.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					//erstelle im RAM
					erstelleLabyrinth();
					
					//zeichne das Lab
					repaint();	
				}
			});
		}
		return jButtonNeu;
	}

	/**
	 * This method initializes jButtonSuche	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonSuche() {
		if (jButtonSuche == null) {
			jButtonSuche = new JButton();
			jButtonSuche.setName("jButton1");
			jButtonSuche.setText("Wegsuche");
			jButtonSuche.setBounds(new Rectangle(399, 8, 111, 35));
			jButtonSuche.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) 
				{
					
					threadSuche= new Thread(doWegSucheRunnable);
					threadSuche.start();
					
				}
			});
		}
		return jButtonSuche;
	}

	/**
	 * This method initializes jButtonEnde	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonEnde() {
		if (jButtonEnde == null) {
			jButtonEnde = new JButton();
			jButtonEnde.setName("jButton3");
			jButtonEnde.setText("Ende");
			jButtonEnde.setBounds(new Rectangle(530, 8, 95, 35));
			jButtonEnde.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					threadSuche.stop();
					System.exit(0);
					
				}
			});
		}
		return jButtonEnde;
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
			jPanel.setPreferredSize(new Dimension(100, 100));
			jPanel.setBounds(new Rectangle(7, 67, 618, 411));
			jPanel.setBackground(Color.lightGray);
			jPanel.setName("jPanel");
		}
		return jPanel;
	}

	/**
	 * This method initializes jTextFieldSize	
	 * 	
	 * @return javax.swing.JTextField	
	 */
	private JTextField getJTextFieldSize() {
		if (jTextFieldSize == null) {
			jTextFieldSize = new JTextField();
			jTextFieldSize.setBounds(new Rectangle(6, 8, 95, 35));
			jTextFieldSize.setBorder(BorderFactory.createTitledBorder(null, "Lab.Grösse", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, new Font("Microsoft Sans Serif", Font.PLAIN, 11), new Color(0, 70, 213)));
			jTextFieldSize.setText("4");
		}
		return jTextFieldSize;
	}

	/**
	 * This method initializes jTextFieldSleep	
	 * 	
	 * @return javax.swing.JTextField	
	 */
	private JTextField getJTextFieldSleep() {
		if (jTextFieldSleep == null) {
			jTextFieldSleep = new JTextField();
			jTextFieldSleep.setBounds(new Rectangle(268, 8, 95, 35));
			jTextFieldSleep.setText("4");
			jTextFieldSleep.setBorder(BorderFactory.createTitledBorder(null, "Verzögerung", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, new Font("Microsoft Sans Serif", Font.PLAIN, 11), new Color(0, 70, 213)));
		}
		return jTextFieldSleep;
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				GrfLabyrinth thisClass = new GrfLabyrinth();
				thisClass.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				thisClass.setVisible(true);
			}
		});
	}

	/**
	 * This is the default constructor
	 */
	public GrfLabyrinth() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(640, 521);
		this.setMaximumSize(new Dimension(436, 439));
		this.setContentPane(getJContentPane());
		this.setTitle("Labyrinth");
		this.addWindowListener(new java.awt.event.WindowAdapter() {
			public void windowOpened(java.awt.event.WindowEvent e) {
				// im Ram
				erstelleLabyrinth();
				
				//zeichne es, d.h. es wird paint() aufgerufen
				repaint();
			}
		});
	}

	/**
	 * This method initializes jContentPane
	 * 
	 * @return javax.swing.JPanel
	 */
	private JPanel getJContentPane() {
		if (jContentPane == null) {
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.setBackground(Color.white);
			jContentPane.add(getJButtonNeu(), null);
			jContentPane.add(getJButtonSuche(), null);
			jContentPane.add(getJButtonEnde(), null);
			jContentPane.add(getJPanel(), null);
			jContentPane.add(getJTextFieldSize(), null);
			jContentPane.add(getJTextFieldSleep(), null);
		}
		return jContentPane;
	}

}  //  @jve:decl-index=0:visual-constraint="10,10"
