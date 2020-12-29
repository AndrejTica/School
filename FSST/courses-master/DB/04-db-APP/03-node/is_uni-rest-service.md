# A modern REST-API for is_uni using node,express


<!-- vscode-markdown-toc -->
* 1. [Design a REST-API](#DesignaREST-API-0)
* 2. [install and setup](#installandsetup-1)
* 3. [server.js (version 1)](#server.jsversion1-2)
	* 3.1. [lab-1: test server.js (version 1)](#lab-1:testserver.jsversion1-3)
	* 3.2. [lab-2: Base setup: Creating a database connection](#lab-2:Basesetup:Creatingadatabaseconnection-4)
* 4. [ server.js (version 2) Using a route Middleware](#server.jsversion2UsingarouteMiddleware-5)
* 5. [Create a record: POST /api/is_professoren](#Createarecord:POSTapiis_professoren-6)
	* 5.1. [lab-3: Test with Firefox->RESTclient](#lab-3:TestwithFirefox-RESTclient-7)
* 6.1. [ Read all records: GET /api/is_professoren](#Readallrecords:GETapiis_professoren-8)
	* 6.2. [lab-4: Test /api/is_professoren](#lab-4:Testapiis_professoren-9)

<!-- /vscode-markdown-toc -->
ahofmann, 2016



##  1. <a name='DesignaREST-API-0'></a>Design a REST-API
-------------------------------------------------------------------
REST-API specification for a CRUD-App (Create,Read,Update,Delete)

|URL   |HTTP command   |POST-body   |Result   |
|---|---|---|---|---|
|/api/is_uni/is_professoren | GET  | empty  |  returns all profs |
|/api/is_uni/is_professoren | POST  | JSON string  |  new Prof created |
|/api/is_uni/is_professoren/:id | GET  | empty  | returns single prof|
|/api/is_uni/is_professoren/:id | PUT  | JSON string | updates an existing prof|
|/api/is_uni/is_professoren/:id | DELETE  | empty | deletes an existing prof|

			
##  2. <a name='installandsetup-1'></a>install and setup
-------------------------------------------------------------------

* install node and npm
* dir structure

~~~
mkdir ws-node/is_uni-rest-service/
mkdir ws-node/is_uni-rest-service/app
cd ws-node/is_uni-rest-service
    - node_modules/     // created by npm. holds our dependencies/packages
    - package.json      // define all our node app and dependencies
    - server.js         // configure our application and create routes
~~~

* create package.json

~~~
{
	"name": "uni-rest-api",
	"version": "0.0.1",
	"private": true,
	"main": "server.js",
	"dependencies": {
		"express": "~4.0.0",
		"mysql": "~2.11.1",
		"body-parser": "~1.0.1"
	}
}
~~~

* ```npm install```

* done




##  3. <a name='server.jsversion1-2'></a>server.js (version 1)
-------------------------------------------------------------------

~~~
// server.js

// BASE SETUP
// =============================================================================

// call the packages we need
var express    = require('express');        // call express
var app        = express();                 // define our app using express
var bodyParser = require('body-parser');

// configure app to use bodyParser()
// this will let us get the data from a POST
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var port = 3000;        // set our port

// ROUTES FOR OUR API
// =============================================================================
var router = express.Router();              // get an instance of the express Router

// test route to make sure everything is working 
// (accessed at GET http://localhost:3000/api)
router.get('/', function(req, res) {
    res.json({ message: 'Hello World! Welcome to the is_uni REST API!' });   
});

// more routes for our API will happen here
// .... TODO .....

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);

// START THE SERVER
// =============================================================================
app.listen(port);
console.log('is_uni REST API service on port ' + port + ' started.');
~~~

###  3.1. <a name='lab-1:testserver.jsversion1-3'></a>lab-1: test server.js (version 1) 
1. test it with ```node server.js``` and <http://localhost:3000/api>
2. install firefox RESTclient plugin and learn to use it


###  3.2. <a name='lab-2:Basesetup:Creatingadatabaseconnection-4'></a>lab-2: Base setup: Creating a database connection
~~~
// BASE SETUP
// =============================================================================

// call the packages we need
var express    = require('express');        // call express
var app        = express();                 // define our app using express
var bodyParser = require('body-parser');
var mysql      = require('mysql');

// ...

// database connection
var pool      =    mysql.createPool({
    connectionLimit : 100, //important
    host     : 'localhost',
    user     : 'is_uni',
    password : 'comein',
    database : 'is_uni',
    debug    :  false
});
function handle_database(req,res,sql) {

    pool.getConnection(function(err,connection){
        if (err) {
          connection.release();
          res.json({"code" : 100, "status" : "Error in connection database"});
          return;
        }   

        console.log('connected as id ' + connection.threadId);

        connection.query(sql,function(err,rows){
            connection.release();
            if(!err) {
                res.json(rows);
            }           
        });

        connection.on('error', function(err) {      
              res.json({"code" : 100, "status" : "Error in connection database"});
              return;     
        });
  });
}
~~~


##  4. <a name='server.jsversion2UsingarouteMiddleware-5'></a> server.js (version 2) Using a route Middleware
---------------------------------------------

1. to get a central place to implement  
	* logging, security, ...
2. improve maintenance of REST-API

server.js
~~~
...
// ROUTES FOR OUR API
// =============================================================================
var router = express.Router();              // get an instance of the express Router

// middleware to use for all requests
router.use(function(req, res, next) {
    // do logging
    console.log('Something is happening.');
    next(); // make sure we go to the next routes and don't stop here
});

// test route to make sure everything is working 
// (accessed at GET http://localhost:3000/api)
router.get('/', function(req, res) {
    res.json({ message: 'Hello World! Welcome to the is_uni REST API!' });   
});

// more routes for our API will happen here
// .... TODO .....

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);

~~~

##  5. <a name='Createarecord:POSTapiis_professoren-6'></a>Create a record: POST /api/is_professoren
-------------------------------------------------------------------------------

server.js
~~~
...
// on routes that end in /is_professoren
// ----------------------------------------------------
router.route('/is_professoren')

   .post(function(req, res) {
        
        // create a new instance of the Professor model
        var sql = "INSERT INTO is_professoren (persnr,name,rang,raum,gebdatum) VALUES (";
        sql += req.body.persnr + ",";
        sql += "'"+req.body.name + "',";
        sql += "'"+req.body.rang + "',";
        sql += req.body.raum + ",";
        sql += "'"+req.body.gebdatum + "')";
        
        
        handle_database(req,res, sql);

		res.json({ message: 'Professor ' + req.body.name + ' created! ' +sql});
        console.log(sql);
                
    });

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);
~~~

###  5.1. <a name='lab-3:TestwithFirefox-RESTclient-7'></a>lab-3: Test with Firefox->RESTclient  
* use POST http://localhost:3000/api/is_professoren
* and define a Header: ```Content-Type: application/json```
* body: ```{"persnr":1234,"name":"mustermann","rang":"c4","raum":123,"gebdatum":"1990-12-12T23:00:00.000Z"}```



## Read all records: GET /api/is_professoren
-------------------------------------------------------------------------------

server.js
~~~
...
// on routes that end in /is_professoren
// ----------------------------------------------------
router.route('/is_professoren')

    // create a prof (accessed at POST http://localhost:3000/api/is_professoren)
    .post(function(req, res) {
        
	// ...
        
    })

    // GET all profs (accessed at GET http://localhost:3000/api/is_professoren)
    .get(function(req,res){
        var sql=  "select * from is_professoren";
        handle_database(req,res,sql);
        console.log(sql);
        
    });

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);
~~~

###  6.2. <a name='lab-4:Testapiis_professoren-9'></a>lab-4: Test /api/is_professoren
* POST http://localhost:3000/api/is_professoren
* and define a Header: ```Content-Type: application/json```
* body: ```{"persnr":1234,"name":"mustermann","rang":"c4","raum":123,"gebdatum":"1990-12-12T23:00:00.000Z"}```


* GET http://localhost:3000/api/is_professoren


## GET a single Prof: GET http://localhost:3000/api/is_professoren/:persnr
-------------------------------------------------------------------------------
~~~
// on routes that end in /is_professoren/:persnr
// ----------------------------------------------------
router.route('/is_professoren/:persnr')

    // get the prof with that id (accessed at GET http://localhost:3000/api/is_professoren/:persnr)
    .get(function(req, res) {
        // ...........................
        // !!!TODO ENTER CODE HERE !!!
        // ...........................
            res.json(?????????????);
        });
    });

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);

...
~~~


## UPDATE a single Prof: PUT http://localhost:3000/api/is_professoren/:persnr
-------------------------------------------------------------------------------
~~~
// on routes that end in /is_professoren/:persnr
// ----------------------------------------------------
router.route('/is_professoren/:persnr')

    // get the prof with that id (accessed at GET http://localhost:3000/api/is_professoren/:persnr)
    .get(function(req, res) {
        // ...
    })
    // update the prof with that id (accessed at PUT http://localhost:3000/api/is_professoren/:persnr)
    .put(function(req, res) {
        // ...........................
        // !!!TODO ENTER CODE HERE !!!
        // ...........................

    }); 

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);

...
~~~


## DELETE a single Prof: DELETE http://localhost:3000/api/is_professoren/:persnr
-------------------------------------------------------------------------------
~~~
// on routes that end in /is_professoren/:persnr
// ----------------------------------------------------
router.route('/is_professoren/:persnr')

    // get the prof with that id (accessed at GET http://localhost:3000/api/is_professoren/:persnr)
    .get(function(req, res) {
        // ...
    })
    // update the prof with that id (accessed at PUT http://localhost:3000/api/is_professoren/:persnr)
    .put(function(req, res) {
        // ...
    }) 
    // delete the prof with that id (accessed at DELETE http://localhost:3000/api/is_professoren/:persnr)
    .delete(function(req, res) {
        // ...........................
        // !!!TODO ENTER CODE HERE !!!
        // ...........................

    }); 

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);

...
~~~


## Conclusion
-------------------------------------------------------------------------------
We now have the means to handle CRUD on a specific resource through our own API. 

This has been a quick look at creating a Node API using Express 4. 
There are many more things you can do with your own APIs. 
* You can add authentication (Authenticate a Node API with Tokens ), 
* create better error messages, 
* add different sections so you’re not just working with profs.


## links
-------------------------------------------------------------------------------
* <https://scotch.io/tutorials/build-a-restful-api-using-node-and-express-4>
* <https://scotch.io/bar-talk/designing-a-restful-web-api>
* <https://oauth.net/>
