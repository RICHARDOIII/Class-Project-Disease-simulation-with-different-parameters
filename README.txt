Compile the first main

1: Creating the objects
type in 
icpc -c main.cc
icpc -c person.cc
This will create the objects of file.o 
2: Linking
icpc all relate objects

icpc main.o person.o -o executable

Compile the second main

1:
icpc -c main1.cc
icpc -c population1.cc
2:
icpc population1.o main1.o person.o -o executable

Compile the third main
1:
icpc -c main2.cc
icpc -c population.cc
2:
icpc population.o main2.o person.o -o executable

Compile the fourth main
1:
icpc -c main3.cc
icpc -c population.cc
2:
icpc population.o main3.o person.o -o executable

Compile the fifth main
1:
icpc -c main4.cc
icpc -c population.cc
2:
icpc population.o main4.o person.o -o executable

