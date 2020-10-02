#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // apps
    ui->lineEditGroesse->setText("4");
    ui->lineEditVerzoegerung->setText("4");

    //member init
    zeilen=spalten=4;

    a= new QColor* [zeilen];

    for(int i=0; i < zeilen; i++)
	a[i]= new QColor[spalten];

    erstelleLabyrinth();
}



MainWidget::~MainWidget()
{
    delete ui;

}




// BUTTONS
void MainWidget::on_pushButtonEnde_clicked()
{
    exit(0);
}

void MainWidget::on_pushButtonNeuesLab_clicked()
{

    erstelleLabyrinth();

}

void MainWidget::on_pushButtonWegesuche_clicked()
{
    if ( wegSuche(0,0) == -1){
	QMessageBox b(this);

	b.setText("Es gibt KEINEN WEG !!!");
	b.exec();
    }
}

//Lab zeichnen
void MainWidget::paintEvent(QPaintEvent *e)
{

    QPainter gr(this);
    for (int x=0; x<spalten; x++){
	for (int y=0; y<zeilen; y++){
	    //gr.setBrush(a[x][y]);
	    gr.fillRect(x*w +RAHMEN/2, y*h +RAHMEN/2, w, h, a[x][y]);
	}

    }



}


// interne Methoden
void MainWidget::erstelleLabyrinth(){
    // wenn ein Such-Thread läuft, wollen wir diesen
    // unterbrechen
    //		    if (threadSuche.isRunning())
    //			    threadSuche.exit();


    // alten speicher freigeben
    // array mit lab-farben frei geben
    for(int i=0; i < spalten; i++)
	delete a[i];
    delete [] a;


    // lies verzoegerung
    verzoegerung= ui->lineEditVerzoegerung->text().toInt();

    // lies lab-auflösung
    w= ui->lineEditGroesse->text().toInt();
    h=w; // hoehe ist weite

    spalten= (this->width() - RAHMEN )/ w ;
    zeilen=  (this->height() -RAHMEN)/ h;


    // neues array
    a= new QColor*[spalten];
    for(int i=0; i < spalten; i++)
	a[i]= new QColor[zeilen];



    //labyrinth malen
    for (int x=0; x<spalten; x++){
	for (int y=0; y<zeilen; y++){
	    if (qrand()%100 < 33) //hÖchstens 1/3 schwarz
		a[x][y]= Qt::black;
	    else
		a[x][y]= Qt::white;
	}
    }

    //Umrandung oben und unten zeichnen
    for (int x=0; x<spalten; x++){
	a[x][0]= Qt::black;//oben
	a[x][zeilen-1]= Qt::black;//unten
    }

    //Umrandung links und rechts zeichnen
    for (int y=0; y<zeilen; y++){
	a[0][y]= Qt::black;//li
	a[spalten-1][y]= Qt::black;//re
    }

    //' Eingang und ausgang
    a[0][0]= Qt::white;
    a[0][1]= Qt::white;

    a[spalten-1][zeilen-1]= Qt::white;
    a[spalten-1][zeilen-2]= Qt::white;


    // neu zeichnen
    repaint();

}


void MainWidget::zeichneLab(){
    repaint();
}

int MainWidget::wegSuche(int x, int y){
/*
    char s[1000];
    sprintf(s, "x= %i y=%i\n", x,y);
    qDebug(s);
*/

    for (int i=0; i< 10000000; i++)
	;

   // zeichneLab();
    repaint();
    //Thread.sleep(verzoegerung);

    // REKURSIONSABBRUCH; REKURSIONSABBRUCH

    // Abbruch, wenn ausserhalb des Labs
    if (x <0 || x >= spalten)
	return -1;
    if (y <0 || y >= zeilen)
	return -1;

    // Abbruch, wenn Wand
    if (a[x][y]== Qt::black) // Wand
	return -1;

    // Abbruch, wenn ich schon da war,
    //und führt nicht zum ziel
    if (a[x][y]==  Qt::red)
	return -1;

    // Abbruch, wenn ich schon da war,
    //und führt nicht zum ziel
    if (a[x][y]== Qt::green)
	return -1;

    //Abbruch, wir sind nun am Ziel
    if (x == spalten-1 && y== zeilen -1){
	QMessageBox box(this);
	box.setText("AM ZIEL!!!!");
	box.exec();

	return 1;
    }


    // REKURSION , REKURSION
    // suche einen neuen Weg

    // markiere momentanen Weg
    a[x][y]=  Qt::green;

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
    a[x][y]=  Qt::red;
    return -1;
}




void MainWidget::on_lineEditGroesse_returnPressed()
{
    erstelleLabyrinth();
}
