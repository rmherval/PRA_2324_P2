#include <iostream>
#include <vector>

//columnas lo que hay que devolver, columnas las monedas, dentro numero de monedas
int devolucion_monedas(std::vector<int>& V, int M, std::vector<int>& Sol){
	int n = V.size();
    	int T[n][M+1] = {-1};//inicializo
	T[0][0] = 0;

    for(int j=1; j<M+1; j++){
	    if(j>= V[0] && T[0][j-V[0]]  != -1)
	   T[0][j] = 1+ T[0][j-V[0]];
}
    for(int i=1; i<n; i++){
	    T[i][0]=0;
	    for(int j=1; j<M+1; j++){
		    if(j<V[i] || T[i][j-V[i]] == -1)
		      T[i][j] = T[i-1][j];
		    else if(T[i-1][j] != -1)
		      T[i][j] = std::min(T[i-1][j], 1+ T[i][j-V[i]]);
		    else
			    T[i][j] = 1 + T[i][j-V[i]];
    
	    }
    }


int i = n-1;
int j = M;
while (i>=0 && j != 0){
        if(i==0 || T[i][j] != T[i-1][j]){
                Sol[i] = Sol[i]+1;
                j=j-V[i];
        }
        else
                i = i-1;
 }

 int k,l;
 std::cout<<"Tabla: "<<std::endl<<"  ";
 for(int i=0; i<=M; i++){
     std::cout<<i;
 }
 std::cout<<std::endl<<"  ---------";
 
 for(k=0; k<n; k++){
   std::cout<<std::endl;
   std::cout<<k<<"|";
   for(l=0; l<M+1; l++){
     std::cout<<T[k][l]<<"";
   }
 }

 std::cout<<std::endl<<"Número de monedas a devolver: ";
  return T[n-1][M];
    
	
  }	

    int main(){
      std::vector<int>V = {1,4,6};
      int M = 8;
      std::vector<int>Sol = {0,0,0};
      std::cout<<devolucion_monedas(V,M,Sol)<<std::endl;

    std::cout<<"vector Solución: ";
      int i;
     for(i=0; i<V.size(); i++){
	std::cout<<Sol[i];
     }

	return 0;
    
    }
      
      
