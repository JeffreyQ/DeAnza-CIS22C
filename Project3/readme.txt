Hello Professor,

This program compiles and works fine on both Visual Studio 2015 and g++.

You can run it on a UNIX machine that has g++ with the following script (assuming you're
in the directory containing all of the source code):

	$ g++ -std=c++11 main.cpp HashTable.h HashTable.cpp
	$ ./a.out

I've compiled it on multiple systems without error. 

~~~~

However, my program output on linux (using g++) is different from that of Windows (using Visual Studio C++ 2015). 
Would you mind sharing your thoughts on what could render such a difference?

Note that the operations on the hash table work properly.


-- Linux -- 

There are a total of 650722 words in the dictionary.
Building dictionary ......................................................................
Minimum Chain Length:   1
Maximum Chain Length:   7
Mean Chain Length:      1.2571

Our dictionary does not contain the following:
jhgfd
bazoogla
pikachu
pokemon

Press any key to quit.

-- Linux end --


-- Windows --

There are a total of 650722 words in the dictionary.
Building dictionary ......................................................................
Minimum Chain Length:   1
Maximum Chain Length:   8
Mean Chain Length:      1.55225

Our dictionary does not contain the following:
jhgfd
bazoogla
pikachu
pokemon

Press any key to quit.

-- Windows end --

	

Regards,
Jeffrey Qiu