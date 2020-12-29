# Windows-Subsystem-Linux

- <https://docs.microsoft.com/en-us/windows/wsl>

- Powershell als Administrator starten

```bash
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

- kali-linux auswählen u. installieren

- user und pwd erstellen
  - alles klein geschrieben und kurzen namen wählen
  - Bei der passwort-eingabe werden überhaupt keine zeichen angezeigt.
  - wenn Du dich vertippt hast, kannst du mit Ctrl+u wieder von vorn beginnen

- Linux updaten
```bash
sudo apt update && sudo apt upgrade
```

---

# Programmier-Tools: gcc,g++,git,cmake

- git installieren

```bash
sudo apt install git
```

- [zum git Kurs](https://gitlab.com/4me/courses/-/tree/master/FSST-ALGO/00-TOOLS-git-ci-cmake)

- cmake installieren

```bash
sudo apt install cmake
```

- [zum cmake Kurs](https://gitlab.com/4me/courses/-/tree/master/FSST-ALGO/00-TOOLS-git-ci-cmake)

- C-Compiler installieren

```bash
sudo apt install build-essential
```

- C und Cpp Compiler starten/testen

```bash
gcc
g++

wenn zB. folg Ausgabe erscheint, ist alles OK
fatal error: no input files
compilation terminated.
```

- Mein erstes C Programm mit dem Linux-Editor nano

```bash
nano hello.c

/*
 * hello.c
 */
 #include <stdio.h>
 int main(){
    printf("Hello, world!\n");
    return 0;
 }

Ctrl-x eingeben und die Datei Speichern
```

- hello.c übersetzen

```bash
gcc hello.c -o hello
```

- hello starten

```bash
./hello
```

- Beispiel: Makefile

```bash
#Makefile begin
all:
  gcc hello.c -o hello
run:
  ./hello
clean:
  rm hello
#Makefile end


$> make
$> make run
$> make clean
```

- Beispiel: CMakeLists.txt

```bash
# CMakeLists.txt begin
cmake_minimum_required(VERSION 3.0)
project (hello)

add_executable( hello hello.c)
# CMakeLists.txt end


$> mkdir build
$> cd build
$> cmake ..
$> make
$> ./hello
```

---

# Linux Kurs I

> **pwd**  
> gibt das aktuelle Verzeichnis aus


> **cd**  
> wechselt in das sog. Home-Verzeichnis (meist /home/username)


> **cd /mnt/c**  
> wechselt in das Verzeichnis /mnt/c (unter Windows c:\)

> **mkdir /mnt/c/c-kurs**  
> erzeugt das Verzeichnis c-kurs im Verzeichnis /mnt/c

> **ls**  
> **ls -l**  
> **ls -al**  
> gibt den Inhalt des aktuellen Verzeichnisses an

> **ls -l /mnt/c/c-kurs**  
> gibt den Inhalt des Verzeichnisses /mnt/c/c-kurs an

> **cat hello.c**  
> zeigt den Inhalt der Datei hello.c (im aktuellen Verzeichnis)

> **cat /etc/passwd**  
> zeigt den Inhalt der Datei passwd im Verzeichnis /etc 

> **cp /etc/passwd bla-passwd.txt**  
> kopiert die Datei /etc/passwd ins aktuelle Verzeichnis unter dem Namen bla-passwd.txt

> **cp /etc/passwd .**  
> kopiert die Datei /etc/passwd ins aktuelle Verzeichnis unter dem Namen passwd

> **rm bla-passwd.txt**  
> löscht die Datei

> **mv passwd bla-passwd.txt**  
> umbennen: benennt die Datei passwd nun bla-passwd.txt
