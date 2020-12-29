# Webservices with gSOAP - the CLIENT 

## install gSOAP
	sudo apt-get install gsoap

## create dirs

	mkdir gSOAP-javaCalculator
	cd gSOAP-javaCalculator
	mkdir soap

## create calc.h from wsdl file (into directory soap)

	wsdl2h -s -o soap/calc.h http://localhost:8080/calculator?wsdl

## create stubs

	soapcpp2 -i soap/calc.h -d soap


## create client-program: main.cpp

```cpp
// g++ -o calc main.cpp soap/soapC.cpp soap/soapcalcProxy.cpp -lgsoap++
//

#include "soap/soapCalculatorPortBindingProxy.h"
#include "soap/CalculatorPortBinding.nsmap"

int main() {
	CalculatorPortBindingProxy service;

	ns1__addResponse	  result;

	if (service.add(1, 2, result) == SOAP_OK)
		 std::cout << "The sum is " << result._return_ << std::endl;
	else
		 service.soap_stream_fault(std::cerr);
}
```


## compile and run

	g++ -o calc main.cpp soap/soapC.cpp soap/soapCalculatorPortBindingProxy.cpp -lgsoap++

	./calc 

