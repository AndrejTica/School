// worker_labyrinth.js

var a;
var rows;
var cols;
var finished;
var found;
var slow;
// finished: 1|-1 found: 1|-1 data: a 

self.onmessage = function (event) {
//	receiving: { a: a, rows: rows , cols: cols, slow: slow});
	a= event.data.a;
	rows= event.data.rows;
	cols= event.data.cols;
	slow= parseInt(event.data.slow);
	
	var found= wayout(0,0);
	
	if (found==1)
		postMessage({finished: 1 , found: 1, element: "green", yy: 0, xx: 0}); 
	else
		postMessage({finished: 1 , found: -1, element: "green", yy: 0, xx: 0}); 
}



function wayout ( x, y){
	console.log("slow= " + slow +1);

	// REKURSIONSABBRUCH; REKURSIONSABBRUCH
	// Abbruch, wenn ausserhalb des Labs
	
	???????????????????????????????????
	
	
	
	// markiere momentanen Weg
	a[x][y]= "green" ;
	
	// inform caller to paint a green cell
	postMessage({finished: -1 , found: -1, element: "green", yy: y, xx: x}); 
	wait(slow);


	// suche einen Weg durch das Lab
	??????????????????????????????????????

	// wenn wir bis hierher kommen gibts keinen weg
	a[x][y]= "red" ;
	// inform caller for painting
	postMessage({finished: -1 , found: -1, element: "red", yy: y, xx: x}); 
	wait(slow);

	return -1;	
}


function wait(ms){
   var start = new Date().getTime();
   var end = start;
   while(end < start + ms) {
     end = new Date().getTime();
  }
}
