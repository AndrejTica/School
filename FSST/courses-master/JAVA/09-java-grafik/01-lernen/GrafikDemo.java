/* GrafikDemo.java */

import java.awt.*;
import javax.swing.*;

public class GrafikDemo extends JFrame {

	private static final long serialVersionUID = 1L;
	private JDesktopPane jDesktopPane = null;
	private JPanel jPanel = null;
	private JButton jButtonStart = null;

	/**
	 * This method initializes jDesktopPane	
	 * 	
	 * @return javax.swing.JDesktopPane	
	 */
	private JDesktopPane getJDesktopPane() {
		if (jDesktopPane == null) {
			jDesktopPane = new JDesktopPane();
			jDesktopPane.add(getJButtonStart(), null);
			jDesktopPane.add(getJPanel(), null);
		}
		return jDesktopPane;
	}


	/**
	 * This method initializes jButtonStart
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getJButtonStart() {
		if (jButtonStart == null) {
			jButtonStart = new JButton();
			jButtonStart.setBounds(new Rectangle(0, 0, 70, 20));
			jButtonStart.setText("Start");
			jButtonStart.addActionListener(new
				 java.awt.event.ActionListener() {
					public void actionPerformed(
						 java.awt.event.ActionEvent e) {

						// Window neu zeichnen lassen
						repaint();

				}
			});
		}
		return jButtonStart;
	}



	/**
	 * This method initializes jPanel
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JPanel getJPanel() {
		if (jPanel == null) {
			jPanel = new JPanel();
			jPanel.setBackground(Color.yellow);
			jPanel.setBounds(new Rectangle(0, 20, 640, 460));	
		}
		return jPanel;
	}


	/**
	 * This method paints GrafikDemo the Window
	 * 	
	 * @return void
	 */
	public void paint(java.awt.Graphics g){
		//um die steuerelemente (Buttons,...) zu zeichnen

		super.paint(g);

		// die eigentliche Grafik wird im jPanel angezeigt
		java.awt.Graphics leinwand= jPanel.getGraphics();
		leinwand.drawLine (0,0,100,100);
	}


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				GrafikDemo thisClass = new GrafikDemo();
				thisClass.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				thisClass.setVisible(true);
			}
		});
	}
		

	/**
	 * This is the default constructor
	 */
	public GrafikDemo() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(640, 480);
		this.setContentPane(getJDesktopPane());
		this.setBackground(Color.orange);
		this.setTitle("Java: Grafik Programmierung");
	}

} 
