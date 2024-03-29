//****************************************************************************//
// Copyright 2024, Ted Ralphs
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the conditiosn specified in the LICENSE file
//
//****************************************************************************//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 3){
      cout << "Program takes two arguments, vector size and step size!" << endl;
      exit(1);
   }
   int size_of_step = atoi(argv[1]);
   int size_of_vector = atoi(argv[2]);
   
   clock_t start = clock();

   vector<double> myVector(size_of_vector);
   srand((unsigned int)time(NULL));
   for(int i=0; i != size_of_vector; ++i) {
      myVector[i]= double( rand() ) / RAND_MAX;
   }

   clock_t timeElapsed = clock() - start;
   double msElapsed = double(timeElapsed) / CLOCKS_PER_SEC;
   //cout << "Memory Allocation:" << msElapsed << endl;
   
   start = clock();
   
#ifdef SUM
   double sum(0);
#endif
   for (size_t i = 0; i < myVector.size(); i += size_of_step) {
#ifdef SUM
      sum += myVector[i];
#else
      myVector[i] *= 3;
#endif
   }
   
   timeElapsed = clock() - start;
   msElapsed = double(timeElapsed) / CLOCKS_PER_SEC;
   cout << "Running Time: " << msElapsed << endl;
   
   return 0;
}
