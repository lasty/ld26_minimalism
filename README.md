
Ludum Dare 26:  Minimalism

By Lasty  (tristan.lasty@gmail.com)


==Libraries Required to build:

SDL2 http://www.libsdl.org/  (version 1.2 won't work)
GLEW http://glew.sourceforge.net/ 


==Build Instructions

* Get sources for required libraries into libs folder

$ cd libs

$ wget http://www.libsdl.org/tmp/SDL-2.0.tar.gz
$ tar -xf SDL-2.0.tar.gz
$ mv SDL-2.0.0* SDL2
$ rm SDL-2.0*tar.gz


(put glew-1.9.0.tgz into libs folder)
$ tar -xf glew-1.9.0.tgz
$ mv glew-1.9.0 glew
$ rm glew-1.9.0.tgz

(build glew)
$ cd glew
$ make



* Run CMake

$ mkdir Build
$ cd Build
$ cmake <options> ..

eg for Windows/MSYS: (Don't forget the .. )

$ cmake -G"MSYS Makefiles" ..

then run your build tool, in this case make

$ make 

this takes a while because it builds SDL2 


then run the executable it produces:

$ ./lasty_ld26_minimalism


