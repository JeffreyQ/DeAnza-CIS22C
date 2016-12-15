Hello Professor,

This program compiles and works fine on both Visual Studio 2015 and g++.

You can it on a UNIX machine that has g++ with the following script (assuming you're
in the directory containing all of the source code):

	$ g++ ClientApp.cpp Entry.h LinkedBinaryTree.h NonexistentElement.h SearchTree.h
	$ ./a.out

I've compiled it on multiple systems without error. Some Visual Studio versions, however, 
give warnings and/or errors about using sscanf_s() instead of sscanf().
	

	
Regards,
Jeffrey Qiu