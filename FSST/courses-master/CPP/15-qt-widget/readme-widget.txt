Qt Widgets
================================================================================

Quellen Cpp und Qt:
--------------------
* http://zetcode.com/gui/qt5/ (SUPER)
* https://www.youtube.com/playlist?list=PLS1QulWo1RIZiBcTr5urECberTITj7gjA (SUPER)
* http://www.bogotobogo.com/Qt/Qt5_GridLayout.php (SUPER)
* http://www.codeprogress.com/cpp/libraries/qt/QTreeWidgetBrowseDirectory.php
	Viele Beispiele f. QWidgets (SUPER)

* https://www.youtube.com/playlist?list=PL2D1942A4688E9D63 (SUPER, etwas alt)
* http://doc.qt.io/qt-5/qtexamplesandtutorials.html 




Inhalt: 01-qt-widgets.odt
-------------------------
* QWidget1 (Hello ohne Designer)
* QWidget2 (Hello mit Designer)

* QMyString - File
* QMyString - shuffle
* QMyString - caesar

* QWidgetQRcode-process
* QNotepad
* NO.QWebEngine 1/2 (todo)
* QCustomPlot (todo)

* QTreeWidget (todo)
	* http://www.codeprogress.com/cpp/libraries/qt/QTreeWidgetBrowseDirectory.php
* QTreeWidgetDirectory (todo)

* QGameOfLife-verkehr-waermeleitung
	file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/02-ueben/AB-CPP-qt-spiel-des-lebens.odt
	file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/02-ueben/AB-CPP-qt-verkehr.odt
	file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/02-ueben/AB-CPP-qt-waermeleitung.odt
	file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/02-ueben/DasBallspiel_UE.zip
	file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/02-ueben/GrfLabyrinth.java

* QRSA (todo)
	* mit QWidgetView


* QMQTT-Plot (todo)
	* Internet of Things
	* mosquitto
	* QCustomPlot

	

Inhalt: 99-qt-db.odt
-------------------------
file:///media/home/home/GITlab/4me/courses/CPP/15-qt-widget/01-lernen/99-qt-db.odt
* QDB-sqlite-people
* QDB-mysql-Professoren
* QDB-mysql-Professoren-Designer
* QDB-sqlite-pruefen-plot-Designer

	


	
* TODO: Lib-tests
	* mysql
	* mqtt
	* QRcode


* TODO* vielleicht:
	* Labyrinth
	* nDamen
	* obenUnten
	* Pizza








QWidget1-1
--------------------------------------------------------------------------------
	* erstes Programm ohne Form-Designer (*.ui)
	* leer
	
QWidget1-2
--------------------------------------------------------------------------------
	* wie oben aber 
	* mit einem QPushButton und 
	* signal/slot (quit)

QWidget1-3
--------------------------------------------------------------------------------
	* wie oben aber 
	* 3 Buttons, Label, 
	* Layout
	* signal/slot (hello, clear, quit)
	
QWidget2
--------------------------------------------------------------------------------
	* DESIGNER
	* 3 Buttons, Label, Layout
	* Go to Slot


QLucky7	
--------------------------------------------------------------------------------
	* DESIGNER
	* qrc: Qt->New->Resource

	QPixmap p(":/img/Sunflower.gif");

	ui->labelBild->setPixmap(p);
	ui->labelBild->setVisible(true);

	int z1= qrand() % 9 + 1;
	ui->labelBild->setNum(z1);


QMyString - QFILE
--------------------------------------------------------------------------------
	* mit Form-Designer: QSlider, QLCDNumber
	* QHorizontalSpacer
	* QFileDialog,QFile,QTextStream
	* QTextEdit (toPlainText)
	* mit MyString.shuffle
	* mit CaesarCipher
	
	
	QString fileName = QFileDialog::getOpenFileName(this,
		    tr("Open Textfile"), ".", tr("Text Files (*.txt *.doc)"));
	if (!fileName.isEmpty()){
		    QFile file(fileName);
		    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		                      return;
		    ui->textEdit_Original->setText(file.readAll());
		    file.close();
	}



	QString fileName = QFileDialog::getSaveFileName(this,
		    tr("Save Textfile"), ".", tr("Text Files (*.txt *.doc)"));
	if (!fileName.isEmpty()){
		    QFile file(fileName);
		    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		                      return;
		    QString txt= ui->textEdit_Ergebnis->toPlainText();
		    QTextStream out(&file);
		    out<< txt;
		    out.flush();
		    file.close();
	}


QMyString - SHUFFLE
--------------------------------------------------------------------------------
	* Aufgabe:
	string s= ui->textEdit_Original->toPlainText().toStdString();

	MyString mystring(s);
	
	s=mystring.shuffle();  
	// pro Wort: 
	//	1 und letztes Zeichen bleiben unverändert.
	//	alle anderen Zeichen werden per Zufall mehrfach untereinander
	//	ausgetauscht.
	// Der text in mystring bleibt aber unverändert.
	
	QString qstring(s);

	ui->textEdit_Ergebnis->setPlainText(qstring);
	
	
	* Lösung:
	// //////////////////////////
	string shuffle(){

		string sret="";
		string sword;
		string sline;

		string str(s);
		istringstream streamLine(str);

		//Paragraphweise
		while(!streamLine.eof()){
			std::getline(streamLine, sline, '\n');


			// wortweise
			istringstream streamWord(sline);
			while(!streamWord.eof()){
				streamWord >> sword;

				for (int i=0; i<10; i++){
					if (sword.size() > 3){
						int idx1= rand()% (sword.size()-2) +1; // 1-8
						int idx2= rand()% (sword.size()-2) +1; // 1-8
						char h= sword[idx1];
						sword[idx1]= sword[idx2];
						sword[idx2]= h;
					}
				}
				sret+=sword + " ";
			}

			sret += "\n";
		}

		return sret;
	}


QMyString - Caesar
--------------------------------------------------------------------------------
	* Aufgabe:

	CaesarStream cs(1); 
	string sPlain= "Hallo"; 
	string sCipher; 

	cs << sPlain; 
	cout << cs << endl;  // gibt Ibmmp aus 

	cs >> sCipher; // liefert den verschlüsselten Text
	cout << sCipher <<endl;  // gibt Ibmmp aus 


	* Lösung: caesarstream.h
	#ifndef CAESARSTREAM_H
	#define CAESARSTREAM_H

	#include <string>
	using namespace std;

	class CaesarStream{
	private:
		int key;
		string cipher;
	public:
		CaesarStream(int key){
		    this->key= key;
		    cipher="";
		}

		void operator<<(const string& sPlain){
		    // sPlain verschlüsseln
		    unsigned char ch; // !!!!!!!!!!!!

		    for(int i=0; i<sPlain.size(); i++){
		        if(sPlain[i]>='A' && sPlain[i]<='Z'){
		            ch= sPlain[i] + key;
		            ch= ch>'Z'? ch-26 : ch;
		        }else if(sPlain[i]>='a' && sPlain[i]<='z'){
		            ch= sPlain[i] + key;
		            ch= ch>'z'? ch-26 : ch;
		        }
		        else
		            ch= sPlain[i];

		        cipher += ch;
		    }
		}

		void operator>>(string& sCipher){
		    sCipher= cipher;
		}

	};
	#endif // CAESARSTREAM_H

	
QNotepad
--------------------------------------------------------------------------------
	* DESIGNER
	
	* QMenue
	* http://www.codebind.com/cpp-tutorial/qt-tutorials-for-beginners-simple-notepad-application/
	* http://www.iconarchive.com/search?q=about
	* https://www.youtube.com/watch?v=j4j1gbYJtUw&index=26&list=PLS1QulWo1RIZiBcTr5urECberTITj7gjA

	* TextEdit (horiz. layout)
	
	* Menu
		File
			New
			Open
			----
			Save
			Save As
		Edit
			Cut
			Copy
			Paste
			-----
			Redo
			Undo

	*QRC
		* Add new File: Qt->Resource File: (name Resources)
		* add qrc für die Icons
		* Prefix: /res
		* add File: select all files in folder img
		
		
	*ACTION EDITOR
	* im Designer ->Action fenster-> DOPPELKLICK auf actionNew
		Icons auswählen
		... auch alle anderen
	* im Designer ->Action fenster-> DRAG actionNew zur Toolbar
		... auch alle anderen
		
	* in Toolbar: re.Mouse->add Seperator
	
	* RUN
	
	* KEINE SEITENRAENDER
		* MainWindow::MainWindow()
			this->setCentralWidget(ui->textEdit)
	
	* im Designer ->Action fenster-> re.Maus -> GO TO SLOT ->trigger
		... auch alle anderen

		void MainWindow::on_actionNew_triggered()
		{
		
		}
		
		
	* COPY,CUT,PASTE,REDO,UNDO
		void MainWindow::on_actionCut_triggered()
		{
			ui->textEdit->cut();
		}

	* RUN

	* FILE-NEW:
	* private:
		QString file_path;

	* void MainWindow::on_actionNew_triggered()
	{
		file_path="";
		ui->textEdit->clear();
	}

	#include	<QFile>
	#include	<QFileDialog>
	#include	<QTextStream>

	* FILE-OPEN:
		* QFileDialog
		* file_path setzen
			* file_path= filename

	* FILE-SAVE
		* file_path nutzen

	* FILE-SAVE-AS
		* QFileDialog
		* file_path setzen
			* file_path= filename


	void MainWindow::on_actionOpen_triggered()
	{
		QString filename= QFileDialog::getOpenFileName(this, "Open File");
		if (!filename.isEmpty()){


			QFile file(filename);

			if (!file.open(QFile::ReadOnly|QFile::Text)){
				QMessageBox::warning(this, "..", "file  not open");
				return;
			}

			// remember !!!
			file_path= filename;

			QTextStream in(&file);
			ui->textEdit->setText( in.readAll());
			file.close();
		}
	}

	void MainWindow::on_actionSave_triggered()
	{

		QFile file(file_path);

		if (!file.open(QFile::WriteOnly|QFile::Text)){
			QMessageBox::warning(this, "..", "file  not open");
			return;
		}

		QTextStream out(&file);
		QString sout= ui->textEdit->toPlainText(); //!!
		out << sout;
		file.flush();
		file.close();

	}

	void MainWindow::on_actionSave_As_triggered()
	{
		QString filename= QFileDialog::getSaveFileName(this, "Save as File");
		if (!filename.isEmpty()){
			QFile file(filename);


			if (!file.open(QFile::WriteOnly|QFile::Text)){
				QMessageBox::warning(this, "..", "file  not open");
				return;
			}

			//remember
			file_path= filename;


			QTextStream out(&file);
			QString sout= ui->textEdit->toPlainText(); //!!
			out << sout;
			file.flush();
			file.close();
		}

	}



	void MainWindow::on_actionAbout_triggered()
	{
		QString about_text="Notepad<br>";
		about_text += "Author: A.Hofmann<br>";
		about_text += "<a href='https://www.youtube.com/watch?v=j4j1gbYJtUw&index=26&list=PLS1QulWo1RIZiBcTr5urECberTITj7gjA'>Quelle: URL</a>";

		QMessageBox msgBox(this);
		msgBox.setWindowTitle("About");
		msgBox.setTextFormat(Qt::RichText);
		msgBox.setText(about_text);
		msgBox.exec();
	}

	
QWebEngine 1
---------------
	1.10.  Projekt: QWebEngine-mini - Ein kleiner Webbrowser
	Qt console app
	QT += core
	QT += gui
	QT += webenginewidgets
	CONFIG += c++11
	TARGET = QWebEngine-mini
	TEMPLATE = app
	SOURCES += main.cpp

	main.cpp

	#include <QApplication>
	#include <QWebEngineView>
	int main(int argc, char *argv[])
	{
		    QcoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

		    QApplication app(argc, argv);

		    QWebEngineView view;

		    view.setUrl(QUrl(QStringLiteral("https://fs-v3.htl-salzburg.ac.at/WebUntis")));

		    view.resize(1024, 750);
		    view.show();

		    return app.exec();
	}


QWebEngine 2
---------------
	Designer: 
	4 Buttons (btnReload, btnBack, btnForward, btnLoad)
	1 lineEditURL
	1 Widget mit Promote to … (Basis: Qwidget, Klassenname: QWebEngineView)

	Signal/Slot
		    //#include <QScreen>
		    resize(QApplication::primaryScreen()->availableSize());


		    //
		    connect(ui->pushButtonLoad, SIGNAL(clicked(bool)),
		                    this, SLOT(on_pushButtonLoad_clicked()));
		    connect(ui->lineEditURL, SIGNAL(returnPressed()),
		                    this, SLOT(on_pushButtonLoad_clicked()));

		    // back, forward, reload
		    connect(ui->pushButtonBack, SIGNAL(clicked(bool)),
		                    ui->widgetWebEnigneView, SLOT(back()));
		    connect(ui->pushButtonForward, SIGNAL(clicked(bool)),
		                    ui->widgetWebEnigneView, SLOT(forward()));
		    connect(ui->pushButtonReload, SIGNAL(clicked(bool)),
		                    ui->widgetWebEnigneView, SLOT(reload()));

* QWidgetQRcode-process
------------------------
	* https://ralgozino.wordpress.com/2011/05/29/introducing-qtqr-a-qr-code-generator-and-decoder/
	* sudo apt-get install libqrencode-dev
	* qrencode -t PNG -o google.png http://www.google.at
	* https://code.google.com/archive/p/qrencode-win32/


	void MainWindow::on_pushButtonGetPicture_clicked()
	{
		QString program = "/usr/bin/qrencode";
		QStringList arguments;
		arguments << "-t" << "PNG";
		arguments << "-o" << "bla.png";
		arguments << ui->plainTextEdit->toPlainText();

		QProcess *myProcess = new QProcess(this);
		myProcess->setWorkingDirectory("/tmp");
		myProcess->start(program, arguments);
		myProcess->waitForFinished();


		QPixmap pix("/tmp/bla.png");
		ui->labelQRpicture->setPixmap(pix);
		ui->labelQRpicture->update();
	}

	* siehe auch:
	* git clone https://github.com/yoneal/qtqrencode.git

