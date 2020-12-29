# HOW-TO-USE: BITMASK

- <https://stackoverflow.com/questions/18591924/how-to-use-bitmask>

~~~
#define LOG_ERRORS            1  // 2^0, bit 0
#define LOG_WARNINGS          2  // 2^1, bit 1
#define LOG_NOTICES           4  // 2^2, bit 2
#define LOG_INCOMING          8  // 2^3, bit 3
#define LOG_OUTGOING         16  // 2^4, bit 4
#define LOG_LOOPBACK         32  // and so on...

// Only 6 flags/bits used, so a char is fine
unsigned char flags;

// CASE 1: initialising the flags
// ------------------------------
// note that assigning a value will clobber any other flags, so you
// should generally only use the = operator when initialising vars.

flags = LOG_ERRORS;
// sets to 1 i.e. bit 0

// CASE 2: initialising to multiple values with OR (|)
// ------------------------------
flags = LOG_ERRORS | LOG_WARNINGS | LOG_INCOMING;
// sets to 1 + 2 + 8 i.e. bits 0, 1 and 3

// CASE 3: setting one flag on, leaving the rest untouched
// ------------------------------
// OR bitmask with the current value
flags |= LOG_INCOMING;


// TEST 1: testing for a flag
// ------------------------------
// AND with the bitmask before testing with ==
if ((flags & LOG_WARNINGS) == LOG_WARNINGS)
   ...

// TEST 2: testing for multiple flags
// ------------------------------
// as above, OR the bitmasks
if ((flags & (LOG_INCOMING | LOG_OUTGOING))
         == (LOG_INCOMING | LOG_OUTGOING))
   ...

// CASE 4: removing a flag, leaving the rest untouched
// ------------------------------
// AND with the inverse (NOT) of the bitmask
flags &= ~LOG_OUTGOING;

// CASE 5: toggling a flag, leaving the rest untouched
// ------------------------------
flags ^= LOG_LOOPBACK;



**
WARNING: DO NOT use the equality operator (i.e. bitflags == bitmask) 
for testing if a flag is set - that expression will only be true 
if that flag is set and all others are unset. 

==> To test for a single flag you need to use & and == :
**

if (flags == LOG_WARNINGS) //DON'T DO THIS !!!!!!!!

   ...
if ((flags & LOG_WARNINGS) == LOG_WARNINGS) // The right way
   ...
if ((flags & (LOG_INCOMING | LOG_OUTGOING)) // Test for multiple flags set
         == (LOG_INCOMING | LOG_OUTGOING))
