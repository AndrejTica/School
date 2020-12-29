/*
 * @file mystring.h
 * @author N.N.
 * @date dd.mm.yyyy
*/

void logo(void);

int  mystrlen(const char s[]);

void mystrcpy(char s[], const char t[]);

void mystrcat(char s[], const char t[]);

int  mystrcmp(const char s[], const char t[]);

void mystrtoupper(char s[]);

int  isPalindrom(const char s[]);
//  (z.B.: otto)

void mystrsort(char s[]);

int  mystrcontains(const char s[],char ch);

void mystrcaesar(unsigned char s[],int schluessel);

void mystrchins (char s[],int stelle, char ch);

void mystrchdel (char s[],int stelle);

