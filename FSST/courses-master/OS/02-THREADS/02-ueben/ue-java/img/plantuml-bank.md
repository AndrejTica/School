@startuml
skinparam titleBorderRoundCorner 15
skinparam titleBorderThickness 2
skinparam titleBorderColor blue
skinparam titleBackgroundColor Aqua-CadetBlue

title Bank\nexample

note top of SimpleBank
3 Angestellte überweisen <b>gleichzeitig</b> je 20 Euro:
- Angestellter 1 überweist 20 Euro von Konto-0 zu Konto-1
- Angestellter 2 überweist 20 Euro von Konto-1 zu Konto-2
- Angestellter 3 überweist 20 Euro von Konto-2 zu Konto-0

Wenn alles korrekt inplementiert wurde, gibt es <b>KEIN LOST UPDATE</b>.
end note


skinparam classAttributeIconSize 0
class SimpleBank {
- int konten[]={30,50,100}
+ void ueberweisung(int von, int nach, int betrag)
+ void kontostand()
}

class Angestellter{
- SimpleBank* bank
- int von, nach, betrag;
+ Angestellter(SimpleBank* bank, int von, int nach, int betrag)

+ void operator()(){ bank->ueberweisung(von, nach, betrag);}
}

SimpleBank o-- Angestellter : uses

SimpleBank1 <-- Angestellter1 : überweist 20 Euro
SimpleBank1 <-- Angestellter2 : überweist 20 Euro
SimpleBank1 <-- Angestellter3 : überweist 20 Euro
@enduml