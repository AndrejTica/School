# Exercise: Textadventure


## topic

> C++, classes, filestream, operator overloading


## description

We will build a **Text-Adventure-Game**, that uses
* rooms, objects
* one hero and many monsters

By the introduction of game databases the player can play many different games. 
So our program will act like an interpreter reading different games/situations 
from the database.


## Text-Adventure-Game V1.0: Rooms and Game database

### description:

Rooms are stored in a text-file (=game database) called **world.txt**.
Our program can read as many rooms as there are in the database. The player can mov from room to room and see the room-description.

supported **commands** are:
**show**
:	shows the room description

**north, south, west, east**
:	if there is a room the player moves to that room.

**help**
:	shows help text (i.e. supported commands)

**quit**
:	quit program



advice: Files in C++
```cpp
#include <fstream>                           
...

ifstream fin;
fin.open("world.txt");
if(fin.fail()) {
        cout << "Konnte " << pFilename << " nicht finden" << endl;
        return -1;
}
```


advice: std::getline()
```cpp
// reads from current fileposition until character '*' into strLine
ifstream fin;
string strLine;
std::getline (fin, strLine, '*');     
```


example:
```cpp
while(std::getline(fin, strLine, '\n')){
        if(strLine == strRoom){
            getline(fin, strRoomDescription, '*');   
             ...
            fin >> strTemp >> strRoomNorth;               
            fin >> strTemp >> strRoomEast;               
            fin >> strTemp >> strRoomSouth;               
            fin >> strTemp >> strRoomWest;               
             ...
       }
}
```


Hinweis:
fin >> strInput >> strInput;
‭//liest das zweite Wort aus der Datei in die Variable strInput
//Bsp:
//<nord> Garderobe
//in strInput steht Garderobe, d.h. das erste Wort wird einfach überlesen

Hinweis:
//setze den Filepointer auf den Beginn und lösche das EOF-Flag
fin.seekg(ios::beg);                       
fin.clear();                                       

Wir wollen nun das Spiel strukturieren. Dazu werden wir folgende Klassen programmieren:

    Ein Raum besteht aus Raumbeschreibung und den Namen der Nachbarräume.
    Ein Spiel stellt die Schnittstelle zum Spieler zur Verfügung


Die Klasse CRaum
Die Klasse CRaum hält alle Informationen des aktuellen Raumes.

    string strCurrentRoom;              // speichert den Namen des aktuellen Raumes
    string strRoomDescription;          // Raum-Beschreibung
    string strRoomNorth;                // Name des Raumes, der im Norden ist
    string strRoomEast;                 // -"-           
    string strRoomSouth;                // -"-
    string strRoomWest;                 // -"-

Pro Raum (Raumbeschreibung und Namen der Nachbarräume) können die Daten aus der Spieldatenbank geladen werden. D.h. die Spieldatenbank besteht aus einzelnen Räumen.

Es wird jeweils nur der aktuelle Raum aus der Spieldatenbank geladen (s.u.). Wenn dann der Benutzer in eine Richtung (nord, sued, ..) geht, wird der jeweilige Raum nachgeladen.

Die Klasse CRaum enthält noch folgende Methoden:

    gibt die Raumbeschreibung (strRoomDescription) als string zurück
        string CRaum::toString(void) const;
    gibt die Raumbeschreibung (strRoomDescription) auf die Konsole aus
        void CRaum::display(void) const;
    liest aus der Spieldatenbank die neuen Raumdaten. strRoom enthält den gewünschten Raumnamen.
        void CRaum::readRoomInfo(string& strRoom) 
    prüft, ob in die Richtung strRoom ein Raum existiert. Wenn ja, lies die Raumdaten (readRoomInfo()). (D.h. moveto() ruft readRoomInfo() auf)
        void CRaum::moveto(string& strRoom)

//CRoom.h
//a.hofmann dez. 2004
#ifndef CRoom_h
#define CRoom_h CRoom_h

#include <fstream>
using namespace std;

class CRoom{
private:                                       
    string strCurrentRoom;                // speichert den Namen des aktuellen Raumes
    string strRoomDescription;            // Raum-Beschreibung (s.u.: endet mit *)
    string strRoomNorth;                // Name des Raumes, der im Norden ist
    string strRoomEast;                // -"-           
    string strRoomSouth;                // -"-
    string strRoomWest;                // -"-
   
    ifstream& fin;
public:
    CRoom(ifstream& pfin): fin(pfin) {}  //Merke FileStream zur Datenbasis

    void moveto(string& aRoom);
    void readRoomInfo(string& aRoom);
   
    string getCurrentRoom(void)const{ return strCurrentRoom; }
    string getRoomNorth(void)const{ return strRoomNorth; }
    string getRoomSouth(void)const{ return strRoomSouth; }
    string getRoomWest(void)const{ return strRoomWest; }
    string getRoomEast(void)const{ return strRoomEast; }
   
    string toString(void){ return strRoomDescription; };

    void display(void)const;
};
#endif


Die Klasse CGame
Die Klasse CGame spielt das Spiel, indem die Benutzerbefehle

    schau: zeigt die Raumbeschreibung
    nord, sued, ost, west: wenn es in diese Richtung einen Raum gibt, geh dorthin
    hilfe: zeigt die Befehle an
    ende: Programmende

eingegeben werden können und je Befehl die entsprechenden Aktionen ausgeführt werden.
Wenn zB. "nord" eingegeben wurde, muss überprüft werden, ob es in diese Richtung einen Raum gibt. Wenn ja, wird dieser geladen.  Zu diesem Zweck wird die Methode moveto(string& aRoom) der Klasse CRaum aufgerufen.

Member der Klasse CGame:

    ifstream fin;

Methoden der Klasse CGame:

    Der Konstruktor der Klasse CGame erhält als Parameter den Namen der Spieldatenbank und öffnet diese(s.o.). Zudem wird die Information des ersten Raumes eingelesenn. (s.u. Spieldatenbasis)
        CGame::CGame(char* pFilename);
    Die Methode start() spielt das Spiel. Es wird in einer while-Schleife ein Prompt ausgegeben, die Benutzereingabe gelesen und die entsprechende Aktion ausgeführt.
        void CGame::start(void)

//CGame.h
#ifndef CGame_h
#define CGame_h CGame_h

#include "CRoom.h"
#include <fstream>
using namespace std;

class CGame {
private:
    ifstream fin;
    CRoom *m_Room;    //Verweis auf Raum
public:
    CGame(char* pFilename);
    void start(void);
    ~CGame();
};

#endif


Hinweis: Die Spieldatenbank: world.txt
Eine Rauminformation besteht aus folgenden Teilen:

    Raumname
    Raumbeschreibung (endet mit einem '*')
    Richtungsinformationsblock mit den entsprechenden Raumnamen. Gibt es keinen Raum in der entsprechenden Richtung wird dies durch "None" angegeben.

Hier ein Beispiel:
<Start> Eingang      // wir starten mit dem Raum namens "Eingang"
...
<Eingang>
   Ja, endlich. Sie haben es gefunden. Ein unheimliches Haus.
   Eine geheimnisvolle Person aus dem Jenseits hat ihnen
   eine schreckliche Nachricht überbracht.

   Ihr Freund wird von dunklen Mächten in einem grossen Haus
   festgehalten. Sie müssen ihn retten. Ja, wirklich, das sind
   sie ihm schuldig.
   Also worauf warten Sie, gehen Sie ins Haus!!!!
   (hilfe bzw. ?)*
<nord> Mitte
<ost>  None
<sued> None
<west> None

Wir wollen nun den Programmablauf beschreiben:

File: main.cpp
#include "CGame.h"
int main(){
    CGame meinSpiel("world.txt");

    meinSpiel.start();
}

CGame::start()
liest in der Datei den Namen des Startraumes. In unserem Beispiel der Raum "Eingang".
Dannach suchen wir in der Datei nach dem String <Eingang>. Dann lesen wir die gesamte Rauminformation ein (CRaum::readRoomInfo()) und geben die Raumbeschreibung (CRoom::display()) aus.

In einer While-Schleife
geben wir den Prompt aus (Raumname): und
lesen die Benutzereingabe.

Wenn der Benutzer zB. "nord" eingibt, so kennen wir den Raum in diese Richtung (s. CRaum::strRoomNorth). Wir suchen wie oben beschrieben nun nach diesem Raum, lesen die Rauminformation geben die Raumbeschreibung aus. Wenn allerdings in der Richtung "nord" kein Raum gewesen wären (wird durch "None" gekennzeichnet) geben wir dem Benutzer den Text aus: "In Richtung nord ist kein Raum vorhanden!".

Ein Raum mit dem Namen "Ende" gibt das Spielende an. D.h. in unserem Spiel wird der Raum namens "Ende" immer der letzte Raum sein.

<Ende>
   Endlich haben Sie ihren Freund gefunden!!!!!
   Er stammelt für Sie unverständliche Worte. Sie gehen auf ihn zu.
   Aber, da sehen Sie, was er ihnen zurufen möchte.
   Die Gefahr ist noch nicht vorüber, sondern beginnt erst.
   To be continued...*
<nord> None
<ost>  None
<sued> None
<west> None


Dies ist nun sehr viel an Information. Am besten wir beginnen nun mit dem ersten Prototyp:

Arbeitsauftrag: Verzeichnis:
abgabe\textadventure1
CGame.h
CGame.cpp
CRoom.h
CRoom.cpp
main.cpp


Anhang: Ein Beispiel für world.txt
<Start> Eingang

<Mitte>
_____________________________________________________________________
   Sie befinden Sie genau in der Mitte des Hauses.

   In irgendeinem Zimmer befindet sich ihr Freund,
   der von geheimnisvollen Personen festgehalten wird.

   Es gibt eine Tuer in jede Richtung.
   (hilfe bzw. ?)
_____________________________________________________________________*
<nord> Oben
<ost>  Rechts
<sued> Eingang
<west> Links


<Links>
_____________________________________________________________________
   Hier befindet sich ein Computer auf dem vielen Fragen stehen.
   Es gibt nur eine Tuer nach west, woher sie gekommen sind.
   (hilfe bzw. ?)
_____________________________________________________________________*  
<nord> None
<ost>  Mitte
<sued> None
<west> None


<Eingang>
_____________________________________________________________________
   Ja, endlich. Sie haben es gefunden. Ein unheimliches Haus.
   Eine geheimnisvolle Person aus dem Jenseits hat ihnen
   eine schreckliche Nachricht ueberbracht.

   Ihr Freund wird von dunklen Maechten in einem grossen Haus
   festgehalten. Sie muessen ihn retten. Ja, wirklich, das sind
   sie ihm schuldig.
   Also worauf warten Sie, gehen Sie ins Haus!!!!
   (hilfe bzw. ?)
_____________________________________________________________________*
<nord> Mitte
<ost>  None
<sued> None
<west> None

<Rechts>
_____________________________________________________________________
   Gleich nachdem Sie durch die Tuer gekommen sind, merkten Sie
   das Unheimliche.
   Irgendwer will was von ihnen. Aber, was nur ?
   Es gibt hier keine Antwort fuer Sie.
   Also zurueck, denn es gibt nur diesen Weg nach Westen.
_____________________________________________________________________*  
<nord> None
<ost>  None
<sued> None
<west> Mitte

<Oben>
_____________________________________________________________________
   Ja, Sie hoeren ganz deutlich die Stimme. Sie kommt von oben
   Es gibt keinen Weg zurueck. Aber doch es gibt einen Weg nach
   Sueden und einen nach Norden.
   Wohin also ?
_____________________________________________________________________*  
<nord> Ende
<ost>  None
<sued> Mitte
<west> None

<Ende>
_____________________________________________________________________
   Endlich haben Sie ihren Freund gefunden!!!!!
   Er stammelt fuer Sie unverstaendliche Worte. Sie gehen auf ihn zu.
   Aber, da sehen Sie selbst, was er ihnen zurufen moechte.
   Die Gefahr ist noch nicht vorueber, sondern beginnt erst.
   To be continued...
_____________________________________________________________________*  
<nord> None
<ost>  None
<sued> None
<west> None


Aufgabe: (textadventure1-qt)
Erweitern Sie obiges Programm, sodass mit dem GUI-Programm Qt (s.unten) eine ansprechende Oberfläche bereitgestellt werden kann. Zur Orientierung  starten  Sie das Programm  ./textadventure1-qt
Es sollen folgende Eingabeelemente verwendet werden:

    ein TextEditor für world.txt
    ein TextEditor für die Befehlseingabe
    ein TextEditor für die Ausgabe des Raumes
    vier Buttons für nord,sued,west,ost (kreuzförmig angeordnet)


Hinweis Programmerstellung:
$> designer                       ... Qt designer starten

    neues C++Projekt (Name: textadventure1-qt)
    neues C++ Main-File (main.cpp)
    neues Widget mit
    save
    qmake
    make
    ./textadventure1-qt



Textadventure V2.0: Objekte in Räumen anzeigen

Beschreibung:
Wir wollen nun in den Räumen verschiedene Objekte plazieren und ansehen können. Dazu erweitern wir unseren Befehlssatz mit dem Befehl zeige . Wir müssen ebenfalls die Spieldatenbank um folgden Eintrag erweitern:

Hier ein Auszug aus der Spieldatenbank:
<Rechts>
______________________________________________________________________________
   Gleich nachdem Sie durch die Tür gekommen sind, merkten Sie das Unheimliche.
   Irgendwer will was von ihnen. Aber, was nur ?
   Es gibt hier keine Antwort für Sie.
   Also zurück, denn es gibt nur diesen Weg nach Westen.
______________________________________________________________________________*
<nord> None
<ost>  None
<sued> None
<west> Mitte
<zeige> 1 Fenster

<Rechts|Fenster>
.......
Ihre Augen stechen, weil die Sonne durch das Fenster scheint.
Jedesmal, wenn sie direkt ins Fenster sehen, schreien Sie vor Schmerz.
........*


Zum Programmablauf:
Sie erweitern den Code-Teil, der die Rauminformation einliest (CRaum::readRoomInfo()). Sie lesen wieviele zeige-Einträge  im Raum vorhanden sind. (hier 1) . Anschliessend lesen Sie in einer for-Schleife die Namen der zeige-Objekte in ein Stringarray ein. Dieses Stringarray muss als private member in der Klasse CRaum definiert werden: (Name m_zeigeArray). Das Array soll maximal 10 Einträge ermöglichen. (#define verwenden).

Hier ein weiteres Beispiel:
<zeige> 3 Fenster Buch Kasten

Bei der Ausgabe der Raumbeschreibung, soll dann auch noch folgendes ausgegeben werden:
    ....
    Folgende Objekte sind vorhanden: Fenster Buch Kasten

Wenn der Benutzer nun den Befehl zeige gefolgt mit einem zeige-Objekt eingibt (zB: zeige Fenster), prüft das Programm, ob der Name in m_zeigeArray vorhanden ist.

    bool CRoom::containsZeigeObjekt(string& pStr);

Wenn zB: zeige Fenster eingegeben wurde, wird folgender String gebildet:
aus "<" + Name des aktuellen Raumes + "|" + strInput + ">" wird ein String gebildet.
Ergebnis: "<Rechts|Fenster>"

Dann suchen wir nach diesem String in der Datenbasis (genau wie wir nach einem Raum suchen). Danach lesen wir die zeige-Beschreibung ein (m_strZeigeDescription).

    bool CRoom::readZeigeInfo(string& pStr);

 und geben sie aus.

    void CRoom::displayZeigeDescription(void) const;


Die Klasse CRaum hat nun weitere Member und Methoden erhalten:

    string m_zeigeArray[ANZ];
    int m_zeige_anz;
    string m_strZeigeDescription
    bool CRoom::containsZeigeObjekt(string& pStr) const;
    bool CRoom::readZeigeInfo(string& pStr);
    void CRoom::displayZeigeDescription(void) const;


Aufageb: (textadventure2-qt)
Erstellen Sie textadventure2-qt. Dazu eweitern sie obige Qt-Anwendung (V1.0) mit den Möglichkeiten der hier besprochenen Version V2.0.


Textadventure V3.0: Monster

Beschreibung:
Wir wollen in diesem Kapitel

    Ein Monster pro Raum hinzufügen
    Dem Spieler Attribute geben:

    <name>   Superheld
    <health> 275
    <weapon> Dolch
    <damage> 21

    Den Befehl status zur Anzeige der Spielerdaten



Monster hinzufügen:
Wir wollen nun Monster zu den Räumen  hinzufügen, die gegen den Spieler kämpfen. Dazu erstellen wir zwei neue Klassen: CMonster und CSpieler.

In unserem Raum-Objekt wird nun auch ein Monster-Objekt enthalten sein. Eine neue Methode:

        bool CRaum::bMonsterInRoom(void) const;

gibt Auskunft darüber, ob im Raum tatsächlich ein Monster ist.

Dazu müssen wir die Datenbasis ändern. Wir fügen zur Rauminformation einen neuen Block namens <feind>.
Darin wird der Monstername gespeichert oder None, falls kein Feind im Raum ist.
<nord> Mitte
<ost>  None
<sued> None
<west> None
<feind> None

oder

<nord> Mitte
<ost>  None
<sued> None
<west> None
<feind> gozilla


Wie beim zeige-Befehl suchen wir nach dem Monsterinformation mit Hilfe des Monsternamen.
<eingang|gozilla>
<health> 125
<damage> 12
<attack> Gozilla zerkratzt dein rechtes Auge.*

Aufgabe: (CMonster)

    Erstellen Sie die Klasse CMonster, die folgende Daten halten kann:
    m_health, m_damage, m_attack
    Erstellen Sie die Kontruktoren und die Methode
    void CMonster::setMonsterInfo(int pHealth, int pDamage, string& pattack)


    Fügen Sie zur Klasse CRoom noch einen Member m_monster vom Typ CMonster hinzu und
    Erstellen Sie die Methode void CRoom::readFeindInfo(string& pStr), die wie beim zeige-Befehl die Monsterinformationen mit Hilfe des Monsternamens einliest (<eingang|gozilla>). Sie verwendet CMonster::setMonsterInfo() (s.o.).
    Erstellen Sie die Methode bool CRoom::bFeindInRoom(void), die angibt, ob ein Monster im Raum ist. Diese Methode kann zur Lösung in einer der folgenden Aufgaben nützlich sein.




Die Klasse CSpieler:
Wir wollen noch einen neuen Befehl einführen: status
Dieser Befehl gibt

    den Namen des Spielers
    die Waffe des Spielers und seine
    Lebenspunkte


Aufgabe: (CSpieler)

    Erstellen Sie die Klasse CSpieler nach folgendem Vorschlag:

Class CSpieler {
          enum tWeapon { Dolch=10, Schwert=20, Speer=30, Pistole=100};
    private:
          string m_name;
          int m_health;
          int m_damage;
          tWeapon m_weapon;
    public:
       CSpieler();
       void readSpielerInfo(void);
       void display(void) const;
};

Sehen Sie nochmals eine Liste von Befehlen und eine kurze Beschreibung:

    schau: zeigt die Raumbeschreibung
    nord, sued, ost, west: wenn es in diese Richtung einen Raum gibt, geh dorthin
    hilfe: zeigt die Befehle an
    zeige: zeigt ein spezielles Objekt im Raum
    status: zeigt die aktuelle Information über den Zustand des Spielers
    ende: Programmende

Die Information für den Spieler befinden sich in der Datenbasis am Beginn:
<Name>   Superheld
<health> 275
<weapon> Dolch
<damage> 21

<Start>  Eingang



Aufgabe: (CGame)
Bei Programmstart wird zunächst ein Spielerobjket erzeugt und mit Werten aus der Datenbasis initialisiert. Wenn wir den Raum betreten greift uns das Monster an. void CMonster::attackSpieler(CSpieler& pSpieler). Überlegen Sie sich eine Lösung und realisieren Sie diese. Bereiten Sie eine 5 minütige Präsentation vor.


Wenn Sie alle Aufgaben bis hierher aufmerksam und selbständig gelöst/programmiert haben, sind Sie in der Lage folgende Zusatzaufgaben zu lösen und somit ihre C++ Kenntnisse zu perfektionieren. Viel Erfolg!!!


Zusatzaufgaben:
1) Bei einer Monsterattake könnten dem Helden/Spieler per Zufallszahlengenerator Schadenpunkte zugeordnet werden.

2) Erlauben Sie dem Spieler einen Kampf gegen ein Monster auszufechten.  Sie wollen vielleicht nicht immer bei Betreten des Raumes einen Kampf mit dem Monster ausfechten.

3) Erzeugen Sie per Zufall Monster in verschiedenen Räumen. Dadurch wird das Spiel interessanter. Getötete Monster sollen natürlich verschwinden.

4) Erzeugen Sie Gegenstände, die Sie in den Räumen positionieren. Der Held geht durch das Spiel und sammelt diese ein. Dadurch kann der Held seine Waffen, ... vermehren.

5) Erzeugen Sie einen Beamer Raum. D.h. wenn sie ein Monster töten oder etwas spezielles aufheben, werden Sie in einen anderen raum "gebeamt".

6) Erzeugen sie Leuteobjekte mit denen Sie in den Räumen sprechen können. Führen Sie den Befehl sprich ein.

7) Erlauben Sie, dass Sie mit anderen Leute-Objekten eine Gruppe bilden können und so ein Gruppenspiel entsteht.

8) Erzeuge Räume, die Sie in eine andere Spieldatenbasis portieren.

9) Der Spieler soll speichern und laden können, sodass der laufende Zustand des Spiels mit evtl. per Zufall erzeugten gegenstände, ... gespeichert werden kann.

10) Erlauben Sie Zauberei und Zaubersprüche

11) Erstellen Sie einen Multiple-Choice Test zum Thema: "Programmieren in C++" bzw. "Linux anwenden". Diesen transformieren Sie in eine Spieldatenbasis.

12) Integrieren Sie das textadventure-game in t_minish

13) Konvertieren Sie dieses Programm in ein Qt-Programm. Protokollieren Sie alle notwendigen Änderungen und gegeben Sie dieses Protokoll in Papierform (mit Deckblatt) ab.


