SEC-Fragen
=========================================

SQL-Injection
Corss-Site-Scripting
Fileupload

Probleme und Lösungen

sqlmap
nmap
John/hydra
Gray Hat




---------------------------------------------
Widerrufszertifikat
Fingerprint

Kann man PGP verschlüsselte Nachrichten an mehrere Nutzer gleichzeitig schicken?
    Ja. Dazu möchte ich aus dem Wikipedia-Artikel zu PGP zitieren:

        Bei PGP wird aber nicht die ganze Nachricht asymmetrisch verschlüsselt, denn dies wäre viel zu rechenintensiv. Stattdessen wird die eigentliche Nachricht symmetrisch und nur der verwendete Schlüssel asymmetrisch verschlüsselt (Hybride Verschlüsselung). Dazu wird jedes Mal ein symmetrischer Schlüssel zufällig erzeugt.

        Dieser symmetrische Schlüssel wird dann per RSA- oder Elgamal-Kryptosystem mit dem öffentlichen Schlüssel des Empfängers verschlüsselt und der Nachricht hinzugefügt. Dadurch ist es möglich, eine Nachricht für mehrere Empfänger gleichzeitig zu verschlüsseln. Eine für mehrere Empfänger verschlüsselte Nachricht …. 

    … enthält also zusätzlich eine Liste, in der für jeden Empfänger der Schlüssel enthalten ist. Dieser Schlüssel wird für jeden Empfänger mit seinem öffentlichen Schlüssel asymmetrisch verschlüsselt. 
Kann ich meine gesendeten verschlüsselten Nachrichten im Postausgang noch lesen?
    Wenn eine Nachricht mit dem öffentlichen Schlüssel der Empfängers verschlüsselt worden ist, kannst man sie im Prinzip nach dem senden nicht mehr anschauen. Allerdings kann man sich selbst auch als Empfänger der Nachricht eintragen lassen (siehe oben). Bei Enigmail gibt es dazu die Einstellung: „Zusätzlich mit eigenem Schlüssel verschlüsseln“:


Wie kann ich herausfinden, ob mein Schlüssel bereits auf einen Schlüsselserver hochgeladen wurde?
    Dazu kannst Du einfach den Schlüsselserver nach deiner E-Mail-Adresse durchsuchen.

        Bei Enigmail geht das über: OpenPGP / Schlüssel verwalten und dann Schlüsselserver / Schlüssel suchen.
        Bei Seahorse kannst Du den/die Schlüsselserver durchsuchen, indem du auf Entfernt / Entfernte Schlüssel suchen klickst.
        Direkt im Internet kannst Du z.B. den MIT Schlüsselserver durchsuchen.
        Eine Liste grafischer Benutzeroberflächen für GnuPG findest Du auf der GnuPG Homepage.

=============
https

==============

Passwörter im Mozilla Firefox werden nicht gespeichert?

Viele Seiten im Internet erfordern eine Anmeldung mit einem Nutzernamen und einem Passwort. Im Optimalfall hat man für jede Seite ein eigenes (und sicheres) Passwort. Dadurch sammeln sich über die Zeit viele Passwörter an, die man nicht jedes mal neu eingeben möchte (oder kann, weil man sie vergessen hat).

Mozilla Firefox bietet daher die Möglichkit Passwörter zu speichern. Wie auf der deutschsprachigen Hilfeseite von Firefox beschrieben, macht Firefox dies bereits standardmäßg. Man sollte allerdings zusätzlich ein Master-Passwort vergeben, um unberechtigten Personen den Zugriff auf die Passwörter zu erschweren.

Unter Umständen kann es passieren, dass man nicht gefragt wird, ob man ein neues Passwort speichern möchte. Zudem kann man in den Sicherheitseinstellungen das Feld „Passwörter speichern“ nicht aktivieren.
Screen shot 2013-08-21 at 12.23.14_cut
Wenn man in den Datenschutzeinstellungen „immer den privaten Modus verwenden“ aktiviert hat, kann man in den Sicherheitseinstellungen das Feld „Passwörter speichern“ nicht aktivieren.

Die Ursache hierfür kann sein, dass man in den Datenschutz-Einstellungen „immer den privaten Modus verwenden“ aktiviert hat. In dem Falle ist es nicht möglich, das Feld „Passwörter speichern“ zu aktivieren. Dieser und andere Gründe für nicht gespeicherte Passwörter, werden auf der englischsprachigen Mozilla Hilfeseite diskutiert.

Um dennoch ein Passwort zu speichern, kann man den privaten Modus in den Datenschutzeinstellungen kurzzeitig deaktivieren (das erfordert einen Neustart des Browsers) und nach der erfolgreichen Speicherung des neuen Passwortes den Modus wieder aktivieren.
==============
