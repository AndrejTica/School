/// association.h
/// ahofmann, 2015
/// -------------------------------------------------

// ....
class Association {
	private:
		struct pair {char* key; int value; };
		pair* vect;
		int max;
		int current;
	public:
		Association (int);

		// search for aKey
		// return a reference to the integer part of its "pair"
		// if aKey has not been seen --> make a new pair
		//    but check for overflow: if so , grow the assoc-vector
		//...
		int& operator[] (const char*);
		void print_all() const;
	};
#endif

