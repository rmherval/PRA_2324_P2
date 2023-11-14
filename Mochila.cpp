#include <iostream>
#include <cstdlib>
#include <chrono>
#include<vector>
#include<cmath>

/*La tabla A representa en las columnas los pesos y en las filas los casos de pesos que nos han propuesto. Dentro de las columnas voy comprobando si para el objeto 1 que en este caso pesa 9 si entra en la mochila, pues de 0 a 8 no entra, a partir de 9 si y hasta el final pq no hay otro. En el caso del objeto 2 que pesa 6 de 0 a 5 no entra nada y a partir de 6 entra, ponemos 40 pq en este caso ese tiene beneficio de 40, cuando llegamos a nueve podría entrar el de 9 o el de 6  pero como el de 6 tiene mayor benficio, entra el de 6 hasta 15 que entra 9+6 38+40=78. Y por último el bojeto 3 que entra en 5 kilos pero en 6 como entra 5 o 6 y 6 tiene mas beneficio entra 6, así hasta 11 que entra 5+9 que consiguen 64 mayor beneficio que 40 y hasta 15 que 9+6 sigue teniendo mayor beneficio que 9+5. En A[3][15] tenemos el resultado */

const int M = 15;
const int N = 3;
const int FILAS = 4, COL = 16;
int A[FILAS][COL];

void inicializar(int A[][COL]){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COL; j++){
            A[i][j] = -1;
        }
    }
}
void imprimir(int A[][COL]){
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
     std::cout<<A[k][l]<<"\t"<<"";
   }
 }

}

int Mochila(std::vector<int> p, std::vector<int> b, int M, std::vector<int>& Sol){

inicializar(A);

for(int i=0; i<FILAS; i++){ //inicialización de la primera fila y columna de la tabla A a 0 (ganancia de no tener nada)
    int j=0;
    for(j=0; j<COL && i<1; j++){
        A[i][j] = 0;
    }
    A[i][j]=0;
}
 

 /*
for(int i =1; i<2; i++){// en el caso del primer objeto
    for(int j=1; j<COL; j++){
        if(j<p[i-1])// si el peso en el que estoy es más pequeño que el peso del primero objeto no puedo meter nada
            A[i][j] = 0;
        else//si cabe lo meto directamente
            A[i][j] = b[i-1];
    }
}
*/
for(int i = 1; i<FILAS; i++){// caso general
    for(int j= 1; j<COL; j++){
        if(j<p[i-1])//si no cabe cojo lo que tenía en la fila anterior
            A[i][j]= A[i-1][j];
        else  //si coge tengo que comprobar que es mayor si lo que tenía para ese peso en la fila anterior o lo que tenía en la fila anterior menos el peso de la actual más el beneficio actual
            A[i][j]=std::max(A[i-1][j], A[i-1][j-p[i-1]] + b[i-1]);
    }
}

 int i = p.size();
 int j = M;
 while(i>0 && j>0) { //mientras que no lleguemos a la fila/columna de mochila vacía seguimos
 	if(A[i][j] != A[i-1][j]){ //si es distinta que el anterior  se ha metido
 	  Sol[i-1]=1;
 	  j = j-p[i-1]; //le resto el peso actual para volver a comprobar
 	  }
 	i--;
 	}

imprimir(A);

return A[p.size()][M];
}
int main(){
    std::vector<int> p{9,6,5};//como tanto p como b van de 0,1,2 cuando comparo mis bucles de i con b no cuadra pq sería b-1 entonces cambio en el programa todo a p-1 y b-1
    int M = 15;
    std::vector<int>b{38,40,24};
    std::vector<int>Sol{0,0,0};

    int benef_max = Mochila(p,b,M,Sol);
    std::cout<<std::endl<<"Beneficio máximo: "<<benef_max<<std::endl;

    std::cout<<"vector Solución: ";
     for(int i=0; i<Sol.size(); i++){
	std::cout<<Sol[i];
     }
     std::cout<<std::endl;
    return 0;
}
