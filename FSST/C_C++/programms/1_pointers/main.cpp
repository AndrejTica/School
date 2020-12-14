

#include <iostream>

using namespace std;

void swap(int* a, int* b);

int main()
{
/*
========================================================
Pointer/reference
========================================================
*/
    cout << "Pointer/Reference "<< endl;
    cout << " "<< endl;


    int x=5;
    int y=2;
    int* pt;                                                //pointer variable definition
    pt = &x;                                                //dem pointer wird die adresse von x zugewiesen mit adress operator &

    cout << "x ist " << x << endl;
    cout << "Adresse von x ist " << pt << endl;             //der inhalt von pointer wird angezeigt, oder praktisch "auf welche adresse es zeigt", alsodie adresse
    cout << "Adresse von x ist " << &x << endl;             //die adresse von x wird angezeigt, das gleiche wie oben
    cout << "x ist " << *pt << endl;                        //der Wert von x wurde angezeigt durch die dereferenzierung von pointer pt.

    *pt = 17;

    cout << "Nach ver�nderung durch pointer ist x jetzt " << x << endl;
    cout << "Nach ver�nderung durch pointer ist x jetzt " << *pt << endl;

    *pt = *pt+100;

    cout << "Jetzt ist x " << *pt << endl;

    swap (&x, &y);

    cout << "x und y wurden getauscht " << x << " " << y << endl;

    swap (x, y);

    cout << "x und y wurden wieder getauscht " << x << " " << y << endl;



    cout << " "<< endl;
    cout << "==============================================="<< endl;
/*
========================================================
Pointers, Arrays, Strings
========================================================
*/

    cout << "Pointers, Arrays, Strings "<< endl;
    cout << " "<< endl;

    int i;
    int element[8]= {1,55,4,8,16,32,64,128};
    int* ptr;

    ptr= &element[0];                                         //oder ptr=element; now ptr is pretty much the same as the array


    cout << "Adresse f�r element[0]= " << ptr <<endl;
    cout << "Wert f�r element[0]= " << *ptr << endl;
    cout << "Adresse f�r element[1]= " << ptr+9 <<endl;
    cout << "Wert f�r element[1]= " << *ptr+1 << endl;      // 2nd element

    cout << " " << endl;

    cout << "Adresse f�r element[0]= " << element <<endl;   //nur arrayname ist gleichzeitig ein zeiger auf das erste element des arrays
    cout << "Wert f�r element[0]= " << *element << endl;
    cout << "Adresse f�r element[1]= " << element+1 <<endl;
    cout << "Wert f�r element[1]= " << *(element+1) << endl;

    cout << " " << endl;

    cout << "Adresse f�r element[1]= " << &ptr[1] <<endl;
    cout << "Wert f�r element[1]= " << ptr[1] << endl;

    cout << "=================================" << endl;

/*
=========================================================================================
=========================================================================================
*/

    int example[5];
    int* ptrr = example;                                    //ptr ist jetzt ein pointer auf die erste addresse im array

    for (int i=0; i < 5; i++)
        example[i] = 3;                                     //wenn wir ein element bearbeiten, dereferencieren wir praktisch die addresse an der stelle 2
                                                            //Unser pointer zeigt auf ein integer (4bytes).
                                                            //wir haben ein int array, also 5 mal 4 bytes. F�r den pointer also 5 adressen auf die er zeigt
                                                            //wenn wir index 2 bearbeiten wollen, wird der pointer um 2 stellen nach rechts geshiftet
                                                            //adressen unterscheiden sich immer um 1 byte
                                                            //der compiler muss nur wissen, welcher datentyp in der adresse ist.

    example[2] = 10;                                       //diese 3 zeilen machen alle das gleiche
    cout << example[2]  << endl;
    *(ptrr + 2) = 6;
    cout << example[2]  << endl;
    *((int*)((char*)ptrr + 8)) = 11;                        //2 * 4: wir haben int array (4byte) pro stelle, bei char pointer (1byte) m�ssen wir also um 4 mal nach
                                                            // rechts gehen um auf den n�chsten index zu kommen. bei 2 indexe also um 8 mal nach rechts
    cout << example[2]  << endl;

     cout << "=================================" << endl;
/*
=========================================================================================
=========================================================================================
*/
     char y1[] = "Hallo1";
     cout << y1  << endl;                                   //wir geben den pointer aus??

     char* y2 = "Hallo2";                                   //wie k�nnen wir einen pointer einfach ein wert zuweisen das keine adresse ist?
     cout << y2  << endl;

     char* y3;                                              //wie k�nnen wir einen pointer einfach ein wert zuweisen das keine adresse ist?
     y3 = "Hallo3";
     cout << y3  << endl;

    char y4[] = {55};
    cout << y4 << endl;

}

void swap(int* a, int* b){                                  //pass by Pointer
	int help;
	help= *a;
	*a= *b;
	*b= help;
}

void swap2(int& a, int& b){                                 //pass by Reference. A reference is always & after an datatype like int&
	int help;
	help= a;
    a= b;
	b= help;
}



