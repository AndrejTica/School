var ich= 
{
	name: 'Max Mustermann',
	alter: 42,
	toString: function (){return "Hallo " + this.name;}
};

console.log(ich.toString());

ich.name="Max Wiese";
console.log(ich.toString());
