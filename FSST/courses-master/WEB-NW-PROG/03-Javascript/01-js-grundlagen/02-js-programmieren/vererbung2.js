//Die Basisklasse Person:
function Person (pname, palter){
	this.name= pname;
	this.alter= palter;
}

//Die Unterklasse Arbeiter:
function Arbeiter (pStundenlohn, pStunden){
	this.stundenlohn= pStundenlohn;
	this.stunden= pStunden;
	this.getGehalt= function(){ return this.stunden * this.stundenlohn;}
}

//Vererbung:
Arbeiter.prototype.person= new Person("unknown", 99);


// Objekte erzeugen
var du= new Arbeiter(200,40);
console.log(du);
console.log(du.person);
console.log("Du verdienst " + du.getGehalt());



var ich= new Arbeiter(100,40);
ich.person.name="Susi";
ich.person.alter=22;

console.log(ich);
console.log(ich.person);
console.log("Ich verdiene " + ich.getGehalt());