#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>

#include <QMessageBox>
#include <QThread>



namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::MainWidget *ui;

    static const int RAHMEN=120;

    //lokale Methoden
    void erstelleLabyrinth();
    void zeichneLab();

    int wegSuche(int x, int y);




private slots:
    void on_lineEditGroesse_returnPressed();
    void on_pushButtonWegesuche_clicked();
    void on_pushButtonNeuesLab_clicked();
    void on_pushButtonEnde_clicked();

private:

    // interne Member
    QColor** a; // DAS 2DIM LABYRINTH

    int zeilen, spalten;
    int w;  // breite einer Zelle
    int h;	// höhe einer Zelle
    int verzoegerung;
    //QThread threadSuche;

};

#endif // MAINWIDGET_H
