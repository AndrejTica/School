# Aufgaben: Threads in Java
----
 
## 0. Aufgabenstellung
----

1. S-Lies: Multithreading in Java 
<https://gitlab.com/4me/courses/blob/master/OS/02-THREADS/02-ueben/ue-java/AB-01-java-multithreading.odt>
2. Bringen Sie die folg. Programmfragmente/Aufgaben zum Laufen.
	* S-Download: <https://gitlab.com/4me/courses/blob/master/OS/02-THREADS/02-ueben/ue-java/AB-02-java-threads-basics.zip>
3. Abgabetermin: OS-java-threads siehe WebUntis


## 1. Threads erzeugen / starten
----
	javac OS00_PunktStrich.java
	java  OS00_PunktStrich

## 2. Lost Update Problem beim Zugriff auf shared Memory
----
Die Begriffe **critical section** , **mutual exclusion** , **Semaphore**

	javac OS01_LostUpdate.java
	java  OS01_LostUpdate

	javac OS02_LostUpdate_Synchronized.java
	java  OS02_LostUpdate_Synchronized


## 3. Vortrag 01: Wie funktioniert ein Semaphore? (wait/notify)	
----
Der Begriff **semaphore** (vgl. Bahngleis)	


## 4. Ein FIFO - Speicher (nicht threadsafe)
----
Der Begriff **threadsafe**

	javac OS03_FIFO.java
	java  OS03_FIFO


## 5. Vortrag 02: FIFOs und Producer/Consumer Threads
----
Es gibt 2 Arten von Synchronisation

1. **Ereignis**-Synchronisation u. FIFO
2. **Sperr**-Synchronisation u. FIFO


	javac OS04_FIFO_Synchronized.java
	java  OS04_FIFO_Synchronized


## 6. Aufgaben: Bank, Sieb des Eratosthenes
----

1. <https://gitlab.com/4me/courses/blob/master/OS/02-THREADS/02-ueben/ue-java/AB-03-java-Bank-SiebEratosthenes-JSlider/AB-Bank-SiebEratosthenes.odt>


## 7. Fragen/MAB
----
1. BS08Sort


## 8. Abschluss-Projekt
----
1. <https://gitlab.com/4me/courses/blob/master/OS/02-THREADS/02-ueben/ue-java/AB-03-ProducerConsumer-JFreeChart-FIFO-Socket/AB-02-BSXXConsumerProducer-JFreeChart-Queue-Socket.txt>

