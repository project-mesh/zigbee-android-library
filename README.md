#TEST LIBRARY
##Usage Instructions:<br>
To use use the test library, compile JNI library C file into the appropriate file type for your operating system (.ddl for Windows. .so for Linux, .jnilib for Mac OS X).
###Windows:<br>
###Linux:<br>
`gcc -o <LIBRARY NAME>.so <LIBRARY NAME>.c -shared -fpic -I/<PATH TO JAVA LIBRARY OR JVM>/java-1.<x>.0-openjdk/include -I/<PATH TO JAVA LIBRARY OR JVM>/java-1.<x>.0-openjdk/include/linux`
###Mac OS X:<br>
`gcc/clang -o lib<LIBRARY NAME>.jnilib -lc -shared <LIBRARY NAME>.c`
    