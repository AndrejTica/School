var calc= function(callback){
	var result=0;
	for (var i=1; i <= 1000; i++)
		result += i*i;
	 
	callback (result);
}


var cb= function(data){
	console.log(data);
}

calc(cb);
