# REGEX with regexr.com and cpp

- goto: <http://regexr.com>

## Hint:regex cheat sheet

~~~ bash
Character classes
  .       any character except newline
  \w\d\s  word, digit, whitespace
  \W\D\S  not word, digit, whitespace
  [abc]   any of a, b, or c
  [^abc]  not a, b, or c
  [a-g]   character between a & g

Anchors
  ^abc$  start / end of the string
  \b\B   word, not-word boundary

Escaped characters
  \.\*\\  escaped special characters
  \t\n\r  tab, linefeed, carriage return

Groups & Lookaround
  (abc)   capture group
  \1      backreference to group #1
  (?:abc) non-capturing group
  (?=abc) positive lookahead
  (?!abc) negative lookahead

Quantifiers & Alternation
  a*a+a?    0 or more, 1 or more, 0 or 1
  a{5}a{2,} exactly five, two or more
  a{1,3}    between one & three
  a+?a{2,}? match as few as possible
  ab|cd     match ab or cd
~~~

## what

1. matching a 24 hour time
2. matching a password
3. matching a hex value
4. matching a hex color
5. mathing an email
6. matching an url
7. matching an IP address
8. matching a HTML tag

## what: matching a 24 hour time

~~~ bash
\b([01]?[0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?\b
match nomatch  string
  o     o      23:50      
  o     o      50:23      
  o     o      1:23       
  o     o      23:50:55   
-------------------------------------------
~~~

## what: matching a password

~~~ bash
\b[a-z0-9_-]{6,18}\b
match nomatch  string     
  o     o      qwert      
  o     o      comein     
  o     o      c0m31n     
  o     o      go2me      
  o     o      go-me      
-------------------------------------------
~~~

## what: matching a hex value

~~~ bash
\b#?([a-f0-9]{6}|[a-f0-9]{3})\b
match nomatch  string     
  o     o      #abc       
  o     o      aBc        
  o     o      1b         
  o     o      #1b        
  o     o      1bb        
-------------------------------------------
~~~

## what: matching a hex color

~~~ bash
#?([0-9a-f]{3}){1,2}
match nomatch  string     
  o     o      ccc        
  o     o      #ccc       
  o     o      aabbcc     
  o     o      cc         
-------------------------------------------
~~~

## what: matching an email

~~~ bash
\b([a-z0-9_\.-]+)@([\da-z\.-]+)\.([a-z\.]{2,6})\b
match nomatch  string                         
  o     o      abc@me.com                     
  o     o      abc@me..de                     
  o     o      abc-me@1.de                    
  o     o      1@sooolong.is.thisemail        
-------------------------------------------
~~~

## what: matching an url

~~~ bash
\b(https?:\/\/)([\da-z-\.]+)([a-z]{2,3})([\/\w -]*)*\/?\b
match nomatch  string                        
  o     o      http://www.htl.com            
  o     o      www.old.man                   
  o     o      ftp://www.me.com              
  o     o      https://www.ooooooooo.hh.io   
-------------------------------------------
~~~

## what: matching an IP address

~~~ bash
\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b
match nomatch   string                      
  o     o       73.60.124.136               
  o     o       256.60.124.136              
  o     o       255.60.124.136              
  o     o       255.255.255.255             
  o     o       0.0.0.0                     
-------------------------------------------
~~~

## what: matching a HTML tag

~~~ bash
[(http(s)?):\/\/(www\.)?a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)

match nomatch   string  
  o     o       <img src="img.jpg" alt="My image>" />
  o     o       http://net.tutsplus.com/ is cool
  o     o       <https://net.tutsplus.com/> as markdown string
  o     o       regexr is the best <a href="http://regexr.com">regexr</a>
  o     o       <a href="hallo://regexr.com">regexr</a>                     
-------------------------------------------
~~~

  
## CPP: REGEX examples

* algorithms
	- regex_match
	- regex_search
	- regex_replace
* iterators
	- regex_iterator
	- regex_token_iterator
* classes
	- basic_regex



## example: regex_replace
https://de.cppreference.com/w/cpp/regex/regex_replace
~~~cpp
#include <iostream>
#include <regex>
#include <string>
int main()
{
   std::string text = "Quick brown fox";
   std::regex vowel_re("a|o|e|u|i");
   std::cout << std::regex_replace(text, vowel_re, "[$&]") << '\n';
}
Output:

Q[u][i]ck br[o]wn f[o]x
~~~





## Example: regex_match
<https://solarianprogrammer.com/2011/10/12/cpp-11-regex-tutorial/>
~~~cpp
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string input;
	regex integer("(\\+|-)?[[:digit:]]+");
	//As long as the input is correct ask for another number
	while(true)
	{
		cout<<"Give me an integer!"<<endl;
		cin>>input;
		if(!cin) break;
		//Exit when the user inputs q
		if(input=="q")
			break;
		if(regex_match(input,integer))
			cout<<"integer"<<endl;
		else
		{
			cout<<"Invalid input"<<endl;
		}
	}
}
~~~


## example: regex_search
<https://en.cppreference.com/w/cpp/regex/regex_search>

~~~cpp
#include <iostream>
#include <string>
#include <regex>
 
int main()
{
    std::string lines[] = {"Roses are #ff0000",
                           "violets are #0000ff",
                           "all of my base are belong to you"};
 
    std::regex color_regex("#([a-f0-9]{2})"
                            "([a-f0-9]{2})"
                            "([a-f0-9]{2})");
 
    // simple match
    for (const auto &line : lines) {
        std::cout << line << ": " << std::boolalpha
                  << std::regex_search(line, color_regex) << '\n';
    }   
    std::cout << '\n';
 
    // show contents of marked subexpressions within each match
    std::smatch color_match;
    for (const auto& line : lines) {
        if(std::regex_search(line, color_match, color_regex)) {
            std::cout << "matches for '" << line << "'\n";
            std::cout << "Prefix: '" << color_match.prefix() << "'\n";
            for (size_t i = 0; i < color_match.size(); ++i) 
                std::cout << i << ": " << color_match[i] << '\n';
            std::cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
        }
    }
 
    // repeated search (see also std::regex_iterator)
    std::string log(R"(
        Speed:	366
        Mass:	35
        Speed:	378
        Mass:	32
        Speed:	400
	Mass:	30)");
    std::regex r(R"(Speed:\t\d*)");
    std::smatch sm;
    while(regex_search(log, sm, r))
    {
        std::cout << sm.str() << '\n';
        log = sm.suffix();
    }
 
    // C-style string demo
    std::cmatch cm;
    if(std::regex_search("this is a test", cm, std::regex("test"))) 
        std::cout << "\nFound " << cm[0] << " at position " << cm.prefix().length();
}
Output:

Roses are #ff0000: true
violets are #0000ff: true
all of my base are belong to you: false
 
matches for 'Roses are #ff0000'
Prefix: 'Roses are '
0: #ff0000
1: ff
2: 00
3: 00
Suffix: ''
 
matches for 'violets are #0000ff'
Prefix: 'violets are '
0: #0000ff
1: 00
2: 00
3: ff
Suffix: ''
 
Speed:	366
Speed:	378
Speed:	400
 
Found test at position 10

~~~
