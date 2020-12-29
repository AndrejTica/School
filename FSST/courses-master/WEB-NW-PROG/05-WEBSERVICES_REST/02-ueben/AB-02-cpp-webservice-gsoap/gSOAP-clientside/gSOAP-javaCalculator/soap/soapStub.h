/* soapStub.h
   Generated by gSOAP 2.8.16 from soap/calc.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20816
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns1__mulResponse
#define SOAP_TYPE_ns1__mulResponse (7)
/* ns1:mulResponse */
struct ns1__mulResponse
{
public:
	LONG64 _return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:long */
public:
	int soap_type() const { return 7; } /* = unique id SOAP_TYPE_ns1__mulResponse */
};
#endif

#ifndef SOAP_TYPE_ns1__mul
#define SOAP_TYPE_ns1__mul (11)
/* ns1:mul */
struct ns1__mul
{
public:
	int _arg0;	/* required element of type xsd:int */
	int _arg1;	/* required element of type xsd:int */
public:
	int soap_type() const { return 11; } /* = unique id SOAP_TYPE_ns1__mul */
};
#endif

#ifndef SOAP_TYPE_ns1__dicResponse
#define SOAP_TYPE_ns1__dicResponse (12)
/* ns1:dicResponse */
struct ns1__dicResponse
{
public:
	LONG64 _return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:long */
public:
	int soap_type() const { return 12; } /* = unique id SOAP_TYPE_ns1__dicResponse */
};
#endif

#ifndef SOAP_TYPE_ns1__dic
#define SOAP_TYPE_ns1__dic (15)
/* ns1:dic */
struct ns1__dic
{
public:
	int _arg0;	/* required element of type xsd:int */
	int _arg1;	/* required element of type xsd:int */
public:
	int soap_type() const { return 15; } /* = unique id SOAP_TYPE_ns1__dic */
};
#endif

#ifndef SOAP_TYPE_ns1__addResponse
#define SOAP_TYPE_ns1__addResponse (16)
/* ns1:addResponse */
struct ns1__addResponse
{
public:
	LONG64 _return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:long */
public:
	int soap_type() const { return 16; } /* = unique id SOAP_TYPE_ns1__addResponse */
};
#endif

#ifndef SOAP_TYPE_ns1__add
#define SOAP_TYPE_ns1__add (19)
/* ns1:add */
struct ns1__add
{
public:
	int _arg0;	/* required element of type xsd:int */
	int _arg1;	/* required element of type xsd:int */
public:
	int soap_type() const { return 19; } /* = unique id SOAP_TYPE_ns1__add */
};
#endif

#ifndef SOAP_TYPE_ns1__minResponse
#define SOAP_TYPE_ns1__minResponse (20)
/* ns1:minResponse */
struct ns1__minResponse
{
public:
	LONG64 _return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:long */
public:
	int soap_type() const { return 20; } /* = unique id SOAP_TYPE_ns1__minResponse */
};
#endif

#ifndef SOAP_TYPE_ns1__min
#define SOAP_TYPE_ns1__min (23)
/* ns1:min */
struct ns1__min
{
public:
	int _arg0;	/* required element of type xsd:int */
	int _arg1;	/* required element of type xsd:int */
public:
	int soap_type() const { return 23; } /* = unique id SOAP_TYPE_ns1__min */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 24; } /* = unique id SOAP_TYPE_SOAP_ENV__Header */
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
public:
	int soap_type() const { return 25; } /* = unique id SOAP_TYPE_SOAP_ENV__Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
public:
	int soap_type() const { return 27; } /* = unique id SOAP_TYPE_SOAP_ENV__Detail */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
public:
	int soap_type() const { return 30; } /* = unique id SOAP_TYPE_SOAP_ENV__Reason */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
public:
	int soap_type() const { return 31; } /* = unique id SOAP_TYPE_SOAP_ENV__Fault */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
