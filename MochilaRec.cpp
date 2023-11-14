#include <iostream>
#include <cstdlib>
#include <chrono>
#include<vector>
#include<cmath>

     std::vector<int> p{9,6,5};
     std::vector<int>b{38,40,24};
     std::vector<int> Sol {0,0,0};
     int M = 15;
     const int N = 3;
     const int FILAS = 4, COL = 16;
     int F[FILAS][COL];

void inicializar(int F[][COL]){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COL; j++){
            F[i][j] = -1;
        }
    }
}
void imprimir(int F[][COL]){
//IMPRIMO LA TABLA
 std::cout<<"Tabla: "<<std::endl<<"  ";
 for(int i=0; i< COL; i++){
     std::cout<<i<<"\t";
 }
 std::cout<<std::endl<<"  -----------------------------";

 for(int k=0; k<FILAS; k++){
   std::cout<<std::endl;
   std::cout<<k<<"|";
   for(int l=0; l<COL; l++){
     std::cout<<F[k][l]<<"\t"<<"";
   }
 }

}

int Mochila(int i, int j){



if( i<=0 || j==0)
    F[i][j] =  0;

    if(F[i][j]==-1){
        if(j<p[i-1]) //no cabe
            F[i][j]= Mochila(i-1,j);//meto el de la fila anterior
        else
            F[i][j] = std::max(Mochila(i-1,j), b[i-1]+Mochila(i-1,j-p[i-1]));
   }
    return F[i][j];

}

void rec_sol(int i, int j){

 while(i>0 && j>0) { //mientras que no lleguemos a la fila/columna de mochila vacía seguimos
 	if(F[i][j] != F[i-1][j]){ //si es distinta que el anterior  se ha metido
 	  Sol[i-1]=1;
 	  j = j-p[i-1]; //le resto el peso actual para volver a comprobar
 	  }
 	i--;
 	}
    std::cout<<"vector Solución: ";
     for(int i=0; i<Sol.size(); i++){
	std::cout<<Sol[i];
     }
     std::cout<<std::endl;
}

int main(){

inicializar(F);
int benef_max = Mochila(N,M);
imprimir(F);
std::cout<<std::endl<<"Beneficio máximo: "<<benef_max<<std::endl;
std::cout<<"vector Solución: ";
rec_sol(N,M);


    return 0;
}


