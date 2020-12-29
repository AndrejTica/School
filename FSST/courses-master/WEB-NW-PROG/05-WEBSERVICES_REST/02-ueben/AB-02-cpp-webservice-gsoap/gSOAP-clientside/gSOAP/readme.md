# Webservices with gSOAP - the CLIENT 

## install gSOAP
	sudo apt-get install gsoap

## create dirs

	mkdir gSOAP
	cd gSOAP
	mkdir soap

## create calc.h from wsdl file (into directory soap)

	wsdl2h -s -o soap/calc.h http://www.cs.fsu.edu/~engelen/calc.wsdl


## create stubs

	soapcpp2 -i soap/calc.h -d soap


## create client-program: main.cpp

```cpp
	#include "soap/soapcalcProxy.h"
	#include "soap/calc.nsmap"

	int main()
	{
		calcProxy service;
		double result;
		if (service.add(1.0, 2.0, result) == SOAP_OK)
		    std::cout << "The sum is " << result << std::endl;
		else
		    service.soap_stream_fault(std::cerr);
	}
```


## compile and run

	g++ -o calc main.cpp soap/soapC.cpp soap/soapcalcProxy.cpp -lgsoap++



# Webservices with gSOAP - the SERVER


