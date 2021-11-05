Alright so my goal thus far has been to put as much of the messy class stuff that ive been working on into a header file so that we don't have to look at it
Once done this should hopefully make implementation a breeze since we will just be calling various functions

For rewriting the database, you're gonna want to change the functions in librarysystems.cpp on lines 79, 138 and 213 for writing to files, and lines 162, 239, 269, 303, 339
and 372. Do whatever you want with them, as long as it works im fine
Please note that these are the definitions of member functions for classes that are declared in the header file librarysystems.h. Thats why its a gross mess. Trust me it works
Also note that since QtFiles dont have a way to read a string up to a comma, I had to make my own. Thats what the parsefile functions does, it divides the strings by their 
commas.

I have made 2 namespaces. All of the classes are in the namespace LibSystems (to make a book you gotta write LibSystems::Book. or using namespace LibSystems)
The other one is called QtHelpers and it has some stuff in there to help with qt. Most of that is taken care of in the backend