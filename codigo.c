#include <stdio.h>
#include <string.h>

void ruta(char *bbdd, char *equipo, char *listar){
    char *ruta[200];
    
    strcpy(ruta,"db/");
    strcat(ruta,bbdd);
    strcat(ruta,"/");
    strcat(ruta,equipo);
    strcat(ruta,"/");
    strcat(ruta,lista);
    strcat(ruta,".json");
    
}
void insertar(char *bbdd,char *equipo,char *lista,char *contenido){
   
    FILE *archivo;
    
    char *ruta[200];
    
    strcpy(ruta,"db/");
    strcat(ruta,bbdd);
    strcat(ruta,"/");
    strcat(ruta,equipo);
    strcat(ruta,"/");
    strcat(ruta,lista);
    strcat(ruta,".json");
    
    archivo = fopen(ruta,"a");
    fputs(strcat(contenido,"\n"),archivo);
    fclose(archivo);
    
}
void buscar(char *bbdd,char *equipo,char *lista){    
    FILE *archivo;
    
    int incremento=1;
    
    char linea[1024];
    
    ruta(bbdd,equipo,lista);
    
    archivo=fopen(ruta,"r");
    
    while(fgets(linea,sizeof(linea),archivo) != NULL){
        printf("Linea %d : %s",incremento,linea);
        incremento++;
    }
    fclose(archivo);
    
}
void eliminar(char *bbdd, char *equipo, char *lista){
    
    ruta(bbdd,equipo,lista);
    
    if(remove(ruta)==0){
        printf("La ruta se ha eliminado");
    }else{
        printf("Algo ha salido mal");
    }
    
}
void crearArchivo(char *bbdd, char *equipo){
    
    char ruta[200];
    
    strcpy(ruta,"db/");
    strcat(ruta,bbdd);
    strcat(ruta,"/");
    strcat(ruta,equipo);
    
    if(mkdir(ruta,0777)==0){
        printf("correcto");
    }else{
        printf("algo ha salido mal");
    } 
    
}
int main (int argc, char *argv[]){
        char *opcion = argv[1];
    
        if (strcmp(opcion,"crear_archivo")==0){
            crearArchivo(argv[2],argv[3]);
        }else if(strcmp(opcion,"insertar")==0){
            insertar(argv[2],argv[3],argv[4],argv[5]);
        }else if(strcmp(opcion,"buscar")==0){
            buscar(argv[2],argv[3],argv[4]);
        }else if(strcmp(opcion,"eliminar")==0){
            eliminar(argv[2],argv[3],argv[4]);
        }else{
            printf("No ha elegido nada");
        }
    
    
    return 0;
}
