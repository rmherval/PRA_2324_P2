#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include<vector>

template <typename T>
class bbin{
public:

T busqbinaria(T x, std::vector<T> v, int ini, int fin){
if(ini>fin){
	std::cout<<"No se encuentra en el array"<<std::endl;
	return -1;
}
int  medio = (ini+fin)/2;

if(v[medio]==x) return medio;

else if(v[medio]> x)
	return busqbinaria(x,v,ini, (medio-1));
else
	return busqbinaria(x,v,(medio+1),fin);

}
T BusquedaBinaria_INV(T x, std::vector<T> v, int ini, int fin){
if(ini>fin){
	std::cout<<"No se encuentra en el array"<<std::endl;
	return -1;
}
int  medio = (ini+fin)/2;

if(v[medio]==x) return medio;

else if(v[medio]> x)
  	return BusquedaBinaria_INV(x,v,(medio+1),fin);
 else
   	return BusquedaBinaria_INV(x,v,ini, (medio-1));
}





};
#endif
