/**
 * http://www.cplusplus.com/reference/ios/ios/exceptions/
 * Get/set exceptions mask
*/

// ios::exceptions
#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream

using namespace std;

int main () {
	std::ifstream file;
	string sinput;

	// set exception mask
	file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

	try {
		file.open ("test.txt");


		while (!file.eof()) {
			// zeichenweise mit: file.get();

			// wortweise lesen mit: file >> sinput

			// zeilenweise lesen mit: std::getline
			std::getline(file, sinput, '\n');
			cout << sinput << endl;
		}

		file.close();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Exception opening/reading/closing file\n";
	}

	return 0;
}





/*
// istream::getline example
#include <iostream>     // std::cin, std::cout

int main () {
  char name[256], title[256];

  std::cout << "Please, enter your name: ";
  std::cin.getline (name,256);

  std::cout << "Please, enter your favourite movie: ";
  std::cin.getline (title,256);

  std::cout << name << "'s favourite movie is " << title;

  return 0;
}


*/




/*

http://www.cplusplus.com/reference/string/string/getline/

// extract to string
#include <iostream>
#include <string>

int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}

*/
