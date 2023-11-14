#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <time.h>

  std::vector<int>z{3,8,4,7,5,6,2};

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
  void swap(T* i, T* j){
   T aux;
 //  if((*i) > (*j)){
       aux = (*i);
       (*i) = (*j);
       (*j) = aux;
  // }
   }
  /*Selecciono como pivote el último y voy comparando entre el primero y el pivote, si es más grande que el pivote no hago nada, aumento la j y comparo el siugiente y el pivote si es más pequeño entonces hago swap con el de la i y la j así el de la i siempre tendrá un valor mayor que el pivote y lo hiré subiendo hasta que acabe el for e intercambie el que es mayor con el pivote y deje el pivote en su sitio dejando los menosres a la izquierda y los mayores a la derecha*/
  T Partition_f(std::vector<T>& v, int ini,int fin){//pivote final
     T x = v[fin];//pivote
    int i = ini;
    for(int j=ini; j<fin; j++){
      if(v[j] <=x){
        swap(&v[i], &v[j]);
        i++;
      }
    }
    swap(&v[i], &v[fin]);
    return i;//nos va a devolver la posicion en la que deja el pivote
  }

  T Partition_p(std::vector<T>& v, int ini,int fin){//pivote primero, modelo teoría
     T x = v[ini];//pivote
      int i = ini;
      int j = fin;
      do{
       // do{
			for(int n= 0; v[i] <= x && i<fin; n++)
              i++;

      //  }while(v[i]<=x && i<fin);
       // do{
			for(int n= 0; v[j] >= x && j>ini; n++)
              j--;
        //}while(v[j]>=x && j>ini);
        swap(&v[i], &v[j]);
      }while(i<j);
    swap(&v[i], &v[j]);
    swap(&v[ini], &v[j]);
    return j;
  }
    T Partition_p2(std::vector<T>& v, int ini,int fin){//pivote primero, modelo prácticas
      T x = v[ini];//pivote
    int i = ini;
    for(int j=ini; j<=fin; j++){
      if(v[j] <x){

          swap(&v[i], &v[j]);
        if(i==ini)ini=j;
        i++;
      }
    }
    swap(&v[i], &v[ini]);
    return i;
  }
    T Partition_m(std::vector<T>& v, int ini,int fin){//pivote primero
      int mid = (ini+fin)/2;
      T x = v[mid];//pivote
    int i = ini;
    for(int j=ini; j<=fin; j++){
      if(v[j] <x){

          swap(&v[i], &v[j]);
        if(i==mid)mid=j;
        i++;
      }
    }
    swap(&v[i], &v[mid]);
    return i;
  }

 /*   T Partition_m(std::vector<T>& v, int ini,int fin){//pivote medio
      T x = v[(ini+fin)/2];//pivote
    int i = ini;
    int j = fin;

    while (i <= j) {
        while (v[i] <= x) {
            i++;
        }

        while (v[j] >= x) {
            j--;
        }
     if(i<=j){
      swap(&v[i], &v[j]);
      i++;
      j--;
     }
    }

    return i;
  }*/

    T Partition_rand(std::vector<T>& v, int ini,int fin){//pivote primero
      srand(time(nullptr));
      int rnd = ini + rand() % (fin+1 - ini);
      T x = v[rnd];
      int i = ini;

      for (int j = ini; j <= fin; j++) {
        if (v[j] < x) {
            swap(&v[i], &v[j]);
            if(i==rnd)rnd=j;
              i++;
        }
      }

      swap(&v[i], &v[rnd]);
      return i + 1;
  }



  void  QuickSort(std::vector<T>& v, int ini, int fin){

    if(ini<fin){
      int pivote = Partition_p2(v, ini, fin);
      QuickSort(v,ini,pivote-1);
      QuickSort(v,pivote+1,fin);
    }
  }



};
#endif
