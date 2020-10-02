// worker_ndamen.js

// PAP: Backtracking
// --------------------------------------
// void BT(int i)	// 1...8 : i-te Dame
//	int k;
//
//	for(k=1..8)
//		if (feld[i][k] nicht bedroht)
//			Setze feld[i][k] besetzt
//
//			if(Brett ist voll)
//				Gib Lösung aus
//			else
//				BT(i+1)
//
//			Nimm dame vom feld[i][k]


var brett;
var slow;

// --------------------------------------------------
self.onmessage = function (event) {
	// receive input data
	// { brett: brett , slow: slow};
	brett= event.data.brett;
	slow= parseInt(event.data.slow);
		
	// start the algo for the first dame
	backtrack(0);
}


// --------------------------------------------------
function backtrack(i){ // i-th Dame
//	console.log("backtrag: Queen Nr= " + i);

	// i-th Queen in (maybe) all cols
	for (_______________________________________) {

		if(! isInDanger(_______________________)){

			// not in danger, so use this column k
			brett_____________________+=2;
			// send row and col to caller to paint the queen on the canvas
			postMessage({finished: -1 , val: 2, y: i, x: k}); 
			wait(slow);
			
			// check END of REcursion
			if (__________________){ // we got done: last 
				postMessage({finished: 1 , val: 2, y: i, x: k}); 
				self.close();
				return true;
			}else{

				// try next row
				var ready= ______________________________; 

				if (ready) 
					return ready;
				else{	// no: this k is not good
					// delete queen from i,k
					brett___________________________-=2;
					// inform caller
					postMessage({finished: -1 , val: -2, y: i, x: k}); 
					wait(slow);
				}
			}
		}
//		console.log ("try next column= " + k);
	}
	return false;
}


function isInDanger( i, j) {
	var col,row;
	var iorig, jorig;

	iorig=i;
	jorig=j;
	// check row
	for (col = 0; col < 8; ++col){
		if(brett[i][col] > 1){ // queen already here
			return true;
		}
	}

	// check col
	for (row = 0; row < 8; ++row) {
		if(brett[row][j]> 1){ // queen already here
			return true;
		}
	}

	// diag  "/"
	// --
	while (i >= 0 && j < 8){
		if(brett[i][j]> 1) // queen already here
			return true;
		else{
			i--; 
			j++; // right and up
		}
	}

	// ++
	i=iorig; j= jorig;
	while (i< 8 && j >= 0){
		if(brett[i][j]> 1) // queen already here
			return true;
		else{
			i++; 
			j--; // left and down
		}
	}

	// diag "\\"
	//
	i=iorig; j= jorig;
	while (i>= 0 && j >= 0){
		if(brett[i][j]> 1) // queen already here
			return true;
		else{
			i--; 
			j--; // left and up
		}
	}


	//
	i=iorig; j= jorig;
	while (i<8 && j < 8){
		if(brett[i][j]> 1) // queen already here
			return true;
		else{
			i++; 
			j++; // right and down
		}
	}

	return false;
}

function wait(ms){
   var start = new Date().getTime();
   var end = start;
   while(end < start + ms) {
     end = new Date().getTime();
  }
}
