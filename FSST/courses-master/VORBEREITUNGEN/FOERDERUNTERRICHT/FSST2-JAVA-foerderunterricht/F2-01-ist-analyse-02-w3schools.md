# Schritt 1: IST-Analyse mit w3schools.com

Antworten auf WAS ich noch nicht kann?

- Strings kann ich zu ____ % noch nicht.
- Arrays  kann ich zu ____ % noch nicht.
- Funktionen/Methods kann ich zu ____ % noch nicht.
- OOP kann ich zu ____ % noch nicht.

## 1. Java Strings

1. Lies: Java Strings
   1. https://www.w3schools.com/java/java_strings.asp
2. CHECK yourself: Java Strings exercise
   1. https://www.w3schools.com/java/exercise.asp?filename=exercise_strings1
   2. usw.

## 2. Java Arrays

1. Lies: Java Arrays
   1. https://www.w3schools.com/java/java_arrays.asp

2. CHECK yourself: Java Arrays exercise
   1. https://www.w3schools.com/java/exercise.asp?filename=exercise_arrays1
   2. usw.

## 3. Java Funktionen (Methods)

1. Lies: Java Methods
   1. https://www.w3schools.com/java/java_methods.asp

2. CHECK yourself: Java Methods exercise
   1. https://www.w3schools.com/java/exercise.asp?filename=exercise_methods1
   2. usw.

## 4. Java OOP

1. Lies: Java Classes (nur die folgenden Teile)
   1. https://www.w3schools.com/java/java_oop.asp
   2. https://www.w3schools.com/java/java_classes.asp
   3. https://www.w3schools.com/java/java_class_attributes.asp
   4. https://www.w3schools.com/java/java_class_methods.asp
   5. https://www.w3schools.com/java/java_constructors.asp
   6. https://www.w3schools.com/java/java_modifiers.asp
   7. https://www.w3schools.com/java/java_encapsulation.asp
   8. https://www.w3schools.com/java/java_packages.asp
2. CHECK yourself: Java classes

~~~ java
F1:
Create an object of MyClass called myObj.

__________ _________ = new _______________();


F2:
Use myObj to access and print the value of the x attribute of MyClass.

public class MyClass {
  int x = 5;

  public static void main(String[] args) {
    MyClass myObj = new MyClass();
    System.out.println(__________);
  }
}

F3:
Call myMethod on the object.


public class MyClass {
  public void myMethod() {
    System.out.println("Hello World");
  }

  public static void main(String[] args) {
    MyClass myObj = new MyClass();
    
	__________________________();
  }
}


F4:
Create and call a class constructor of MyClass
Follow the comments to insert the missing parts of the code below:


// Create a MyClass class
public class _____________
 {
  int _________;  // Create a class attribute x

  // Create a class constructor for the MyClass class
  public ______________() {
    x = _____________;  // Set the initial value for the class attribute x to 5
  }

  public static void main(String[] args) {
    // Create an myObj object of class MyClass (This will call the constructor)
    MyClass _______________ = new MyClass(); 
    // Print the value of x
    System.out.println(________________);
  }
}


F5:
Fill in the missing parts to import the java.util.Scanner class from the Java API:


____________ ________.________________._________________;



F1: 
Create an object of Complex called z2.

________________________ = new _____________ ();


F2(5,25): 
what is the output?

public class MyClass {
  int x = 5;

  public static void main(String[] args) {
    MyClass myObj1 = new MyClass();
    MyClass myObj2 = new MyClass();
    myObj2.x = 25;
    System.out.println(myObj1.x);
    System.out.println(myObj2.x);
  }
}


F3(5)
what is the output?

// Create a MyClass class
public class MyClass {
  int x;

  // Create a class constructor for the MyClass class
  public MyClass() {
    x = 5;
  }

  public static void main(String[] args) {
    MyClass myObj = new MyClass();
    System.out.println(myObj.x);
  }
}



F4(5)
what is the output?

public class MyClass {
  int x;

  public MyClass(int y) {
    x = y;
  }

  public static void main(String[] args) {
    MyClass myObj = new MyClass(5);
    System.out.println(myObj.x);
  }
}

F5(33)
what is the output?

public class MyClass {
  final int x = 10;
  final double PI = 3.14;

  public static void main(String[] args) {
    MyClass myObj = new MyClass();
    myObj.x = 50; 
    myObj.PI = 25;
    System.out.println(myObj.x); 
  }
}


F6(33)
what is the output?

public class Person {
   private String name;

   // Getter
   public String getName() {
     return name;
   }

   // Setter
   public void setName(String newName) {
     this.name = newName;
   }
}

public class MyClass {
  public static void main(String[] args) {
    Person myObj = new Person();
    myObj.name = "John";
    System.out.println(myObj.name);
  }
}



F7(John)
what is the output?

public class Person {
   private String name;

   // Getter
   public String getName() {
     return name;
   }

   // Setter
   public void setName(String newName) {
     this.name = newName;
   }
}


public class MyClass {
  public static void main(String[] args) {
    Person myObj = new Person();
    myObj.setName("John"); 
    System.out.println(myObj.getName());
  }
}
~~~
