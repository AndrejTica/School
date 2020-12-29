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

