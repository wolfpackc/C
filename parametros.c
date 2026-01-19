#include<stdio>
void Parametros(int argc,char **argv);
int main(int argc,char **argv){
  Parametros(argc,argv);
  return 0;
}
//esta funcion imprime los parametros que se pasan por consola
//
//
void Parametros(int argc,char ** argv){
  for(int i=0;i<argc;i++){
  fprintf(stdout,"valor %d: %c", i, *(argv+i));
  }
}
