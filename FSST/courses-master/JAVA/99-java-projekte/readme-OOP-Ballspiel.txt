================================================================================
SwingBallSpiel
================================================================================
<pre>

--------------------------------------------------------------------------------
IDEE:
--------------------------------------------------------------------------------
Timer
	actionGame()
	repaint()   ruft paint() auf

Paint:
	paintSpielfeld()

PaintSpielfeld:
	spielfeld zeichnen
	ball.paint()

actionGame:
	if leben==0 exit()
	if ball.isOut() ... leben-=1
	ball.move();
	

StartButton:
	ball erzeugen
	startTimer()

MouseClick:
// wenn Ball erwischt ->ball wählt selbständig Zufallsposition
		ball.onClick(mouse_x,mouse_y);


--------------------------------------------------------------------------------
DETAILS
--------------------------------------------------------------------------------



// PAINT wird vom SYSTEM aufgerufen
//--------------------------------------------------------------------------
	public void paint(Graphics g){
		super.paint(g);
		paintSpielfeld();
	}

// PAINTSPIELFELD
//------------------------------------------------------
	// Zeichnet 
	//	1. das SPIELFELD und
	//	2. alle darauf befindlichen Objekte
	public void paintSpielfeld(){
		Graphics2D g= (Graphics2D)panelSpielfeld.getGraphics();

		g.setRenderingHint(
                RenderingHints.KEY_ANTIALIASING, 
                RenderingHints.VALUE_ANTIALIAS_ON);

		// blauer Hintergrund f. das Spielfeld
		g.setColor(Color.BLUE);
		g.fillRect(0, 0, panelSpielfeld.getWidth(), panelSpielfeld.getHeight());

		
		// Objekte auf dem Spielfeld zeichnen
		if (ball1!=null)
			ball1.paint();

		if (ball2!=null)
			ball2.paint();

	}


// START BUTTON
//----------------------------------------------------------------------------
	private class BtnStartActionListener implements ActionListener {
		public void actionPerformed(ActionEvent arg0) {

			// 
			// Erzeuge Spiel objekte
			ball1= new Ball(panelSpielfeld);
			ball2= new Ball(Color.GREEN, 70, new Point(150,150), panelSpielfeld);
			
			ball1.setDirection (-1,0);  // links
			ball2.setRandomDirection();
			
			ball1.setRandomPosition();
			ball2.setRandomPosition();
			

			
			// starte SPIEL-TIMER
			startTIMER();
		}



// TIMER starten
// ------------------------------------------------------------
	private void startTIMER() {
		if (timerSPIEL != null)
			return;
		
		delaySpiel= sliderSpeed.getValue();
		timerSPIEL= new Timer(delaySpiel, new java.awt.event.ActionListener(){
			public void actionPerformed(java.awt.event.ActionEvent arg0){

				// spiel das Spiel
				actionGame();
				
				// Zeichne das Spielfeld
				repaint();
			}
		});

		
		timerSPIEL.start();
	}
}
	
	
// SPIEL das Spiel
// ------------------------------------------------------------
private void actionGame() {
	// leben ?
	int leben= Integer.parseInt(lblLeben.getText());
	
	if (leben==0){
		timerSPIEL.stop();
		JOptionPane.showConfirmDialog(null, "SPIELENDE ...");
		System.exit(0);
	}
	
	if (ball1.isOut()){
		 leben--;
		 lblLeben.setText(String.valueOf(leben));			 
		 ball1.setRandomPosition();
		 ball1.setRandomDirection();
	}	 
	if (ball2.isOut()){
		 leben--;
		 lblLeben.setText(String.valueOf(leben));			 
		 ball2.setRandomPosition();
		 ball2.setRandomDirection();
	}	 

	
	ball1.move();
	ball2.move();
}


// MOUSE KLICK des SPIELERS
// ------------------------------------------------------------
private class PanelSpielfeldMouseListener extends MouseAdapter {
	@Override
	public void mouseClicked(MouseEvent arg0) {
		
		System.out.println("MOUSE-CLICKED:" + "x=" + arg0.getX() + " y= " + arg0.getY());
	
		
		// wenn ein Ball erwischt wurde, soll er 
		// selbständig eine ZUfallsposition einnehmen
		int mouse_x= arg0.getX();
		int mouse_y= arg0.getY();
		
		ball1.onClick(mouse_x,mouse_y);
		ball2.onClick(mouse_x,mouse_y);
	
	}
}




