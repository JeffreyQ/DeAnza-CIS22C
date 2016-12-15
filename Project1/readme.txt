Hello Professor,

This program compiles and works fine on Visual Studio 2015; it should also work on XCode.

Another way to run it is on a UNIX machine that has g++ with the following script (assuming you're
in the directory containing all of the source code):

	$ g++ project1.cpp MyQueue.cpp MyStack.cpp MyQueue.h MyStack.h OperatorPriority.h
	$ ./a.out

I've compiled it on multiple systems without error. Some compilers, however, give warnings about non-compatibility issues
with versions earlier than C++11.
	
	
Regards,
Jeffrey Qiu