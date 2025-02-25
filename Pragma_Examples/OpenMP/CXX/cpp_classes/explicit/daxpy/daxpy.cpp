#include<iostream>
#include "daxpy.hpp"

void daxpy::apply(){

   #pragma omp target teams distribute parallel for map(to:x_[:N_]) map(tofrom:y_[:N_])	
   for(int i=0; i<N_; i++){
      y_[i] = a_ * x_[i] + y_[i];
   }

}
