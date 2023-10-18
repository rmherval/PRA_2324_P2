#include <iostream>
#include <cstdlib>
#include <chrono>
#include<vector>
#include "DyV.h"

int main(int argc, char** argv){

  std::vector<int>v{3,8,15,23,56,60,72,75,81,92};//ascendente
  std::vector<float>b{3.3,5.2,6.3,10.7,12.7};//ascendente
  std::vector<int>w{92,81,75,72,60,56,23,15,8,3};
bbin<int> Objeto;
 bbin<float> Objeto2;

auto start = std::chrono::system_clock::now();

//Objeto.busqbinaria(atoi(argv[1]),v,0,9);//proceso a medir con enteros
// Objeto2.busqbinaria(5.2,b,0,4);
 Objeto.BusquedaBinaria_INV(atoi(argv[1]),w,0,9);

auto end = std::chrono::system_clock::now(); //Guarda el instante
std::chrono::duration<float, std::milli> duration = end - start; //Diferencia
std::cout << "Time: " << duration.count() << "s" << std::endl; //Resultado
	
return 0;

}
