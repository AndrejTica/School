================================================================================
﻿THREADS
================================================================================
﻿<pre>

--------------------------------------------------------------------------------
POSIX
--------------------------------------------------------------------------------
Signale:
	Beispiel: selfalarm.c
	Beispiel: id-code.c	
	Aufgabe: wecker.c - Wecker mit Text	
	Beispiel: control-c.c	
	Beispiel: kill-usr1-usr2.c	
	Aufgabe: t_minish.c	

Prozesse:	
	Beispiel: fork-demo.c	
	Aufgabe: selfalarm-fork.c	
	Aufgabe: file-server-fork.c	
	+Aufgabe: file-server-base64.c	
	Aufgabe: file-server-infix2postfix.c	
	Aufgabe: file-server-qrcode.c	
	Beispiel: execlp-demo.c	
	Beispiel: wait.c

IPC: Inter Process Communication
	Beispiel: Named Pipes sind FIFOs	
	Beispiel: demo-open.c - unix-like filehandling	
	Beispiel: demo-open.c	
	Beispiel: pipe-fork.c – IPC	
	Beispiel: pipe2.c – FILE* E/A Funktionen verwenden
	Aufgabe: pipe-toupper.c
	Aufgabe: pipe-rate.c

	Pipes zur bidirektionalen Kommunikation	
	Beispiel: pipe2-execlp-sort.c	
	Aufgabe: pipe-execlp-befehl.c	
	Aufgabe: einfacher-telnetd.c	

	Bidirektionale Kommunikation mit Komfort: popen()	
	Beispiel: popen-demo.c	
	Aufgabe: popen-starter.c	

	Aufgabe: pipe-zeitmessung.c	

	Named Pipes bei nicht verwandten Prozessen: mkfifo	
	Beispiel: fifo-demo-echo.c – 1 Reader und N Schreiber	
	Beispiel: fifo-zeitmessung.c	
	Beispiel: fifo-client-server 	

	Synchronisation mit Lockfiles	
	Beispiel: lock-demo.c	
	
	Aufgabe: Paralleles Sortieren 


--------------------------------------------------------------------------------
JAVA-THREADS
--------------------------------------------------------------------------------
Die Klasse Thread:
	Erzeugen eines Threads
		Aufgabe BS00CounterThread
		Aufgabe: BS00PunktStrich.java
	Abbrechen eines Threads	
		Aufgabe: BS00WaitInterrupt
	Das Interface Runnable
1		Aufgabe: BS01ThreadRunnable

Synchronisation
	Das Problem namens "race condition"	
		Aufgabe: BS02ThreadNotSynchron
		Aufgabe: BS03ThreadNotSynchronSleep	
	Monitore	
		Aufgabe: BS04ThreadSynchronSleep	
	Wait und notify	
		Aufgabe: BS05ProducerConsumer	
		Aufgabe: BS05ProducerConsumer	
	PipedInputstream, PipedOutputStream	
		Aufgabe: BS06ProducerConsumerPipe	
		Aufgabe: BS07GrepPipe	

ProcessBuilder: Kommunikation mit externen Programmen	
	Aufgabe: BSMPlayer	

Aufgaben:
	Aufgabe: BS08Eratosthenes	
	Aufgabe: BS08Sort	
	Aufgabe: BS08FileGrep	

</pre>
