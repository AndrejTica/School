@startuml
skinparam titleBorderRoundCorner 15
skinparam titleBorderThickness 2
skinparam titleBorderColor blue
skinparam titleBackgroundColor Aqua-CadetBlue

title Sieb des Eratosthenes (prime)\nexample

legend top left
Grundprinzip ist, dass jede ungerade Zahl der Reihe nach daraufhin untersucht wird,
- ob sie Vielfaches einer bereits erkannten Primzahl ist. 
- Wenn das nicht der Fall ist, dann ist sie natürlich prim.

Die folgende Lösung stellt für <b>jede Primzahl einen eigenen Thread</b>.
D.h. wir erhalten eine Reihe von Threads, die als <b>Member je eine Primzahl</b> enthalten.
- Der Main-thread 
  - erzeugt die ungeraden Zahlen und 
  - sendet sie dem nächsten Thread in der Reihe. 
- Dieser ist für die Primzahl 3 zuständig und filtert demnach alle Zahlen aus, 
- die Vielfache von 3 sind. D.h. er schickt diese Zahl nicht weiter. 
- Alle anderen Zahlen reicht er an den nächsten Thread weiter, 
- der für die Primzahl 5 zuständig ist, usw. 
- Jeder Thread erzeugt für die erste Zahl, die er weiterreichen muss 
- (das ist die nächste Primzahl!), dynamisch seinen Nachfolger-Thread. 
endlegend


skinparam classAttributeIconSize 0

main: gibt 2 aus
main: sendet 3,5,7,9,11,...
main: sendet -1 (ende)

state3 : filtert alle Vielf. von 3
state3 : gibt 3 aus, wenn -1 kommt
state5 : filtert alle Vielf. von 5
state5 : gibt 5 aus, wenn -1 kommt
state7 : filtert alle Vielf. von 7
state7 : gibt 7 aus, wenn -1 kommt
state11: filtert alle Vielf. von 11
state11 : gibt 11 aus, wenn -1 kommt

main -> state3 : ...,13,11,9,7,5,3
state3 -> state5 : ...,13,11,7,5
state5 -> state7: ...,13,11,7,
state7 -> state11: ...,13,11,


@enduml