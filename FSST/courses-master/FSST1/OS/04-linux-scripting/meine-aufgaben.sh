#!/bin/bash
#
#
echo NAME shell script

function menue {
    #echo off
    clear
    #color 9F
    echo
    echo "*****************************************************************"
    echo "*********************** NAME  ***********************************"
    echo "** Datum:" `date`
    echo "** Home: `pwd`"
    echo "** Computer: `hostname`"
    echo "** Link:http://landoflinux.com/linux_bash_scripting_tutorial.html"
    echo "*****************************************************************"
    echo
    echo
    echo "1) Backup fsst1"
    echo "--------------------------"
    echo "2) Zeige aufgaben.txt"
    echo "3) Was ist heute zu tun?"
    echo "4) Lösche alle Aufgaben"
    echo "5) Neue Aufgabe erfassen"
    echo "--------------------------"
    echo "6) Edit Hello.java"
    echo "7) compile Hello.java"
    echo "8) Run Hello"
    echo "--------------------------"
    echo "0) exit"
    echo
    echo
}


choice=1
while [ $choice -gt 0 ] 
do
    menue
    read choice
    
    # -------------------------
    #echo $choice was given

    if [ $choice -eq 1 ]
    then
        echo "todo 1..."
    elif [ $choice -eq 2 ]
    then
        echo "===> meine-aufgaben.txt ..."
        cat meine-aufgaben.txt | sort
    elif [ $choice -eq 2 ]
    then
        echo "todo 2..."
    elif [ $choice -eq 0 ]
    then
        echo "===> GOODBYE <===="
        exit 0
    else
        echo "else"
    fi



    echo 
    echo "weiter mit enter ..."
    read
done
