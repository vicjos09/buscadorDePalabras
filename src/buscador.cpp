/* Este programa lo que busca es un patron dentro de una cadena de caracteres
que le pide al usuario*/
#include <iostream>
#include <string>
#include <new>
int len(std::string cadena);
int considencias(std::string cadena,std::string pat);
int main()
{    
	int sizeCadena;
	int sizePatron;
    int * posi;
    int considen=0;
    int cont=0;
    std::string cadenaEntrada;
    std::string patron;

	std::cout<<"Dame una cadena:"<<"\n";
	std::cin>>cadenaEntrada;
	std::cout<<"Dame un patron:"<<"\n";
	std::cin>>patron;
    sizeCadena=len(cadenaEntrada);
    sizePatron=len(patron);

    int comparador=0;
    bool cumple=false;
    considen=considencias(cadenaEntrada,patron);
  //  std::cout<<"tamaño del vector creado: "<<considen<<"\n";
    if (considen==0)
    {
    	std::cout<<"No hay considencias";
    }else{
  		  posi=new(std::nothrow) int[considen];
          // guardar posiciones
 	      for (int i = 0; i < sizeCadena; ++i)
  		  { 		 
  		      
  		      if (cadenaEntrada[i]==patron[0])
  		      { 
  		   
  		      	posi[cont]=i;
  		      	cont++;

  		      }
	      }
          //checar si son iguales al patron
	      for (int indx = 0; indx < considen; ++indx)
	      {comparador=0;
	      	/* code */
	      	  if ((sizeCadena-posi[indx])<sizePatron)
	      	  {
	      	  	//no hagas nada
	      	  }else{

	      	  	//chechar
	      	  	 		for (int indxx = 0; indxx <sizePatron ; ++indxx)
	         	 		{
	         	 		  (patron[indxx]==cadenaEntrada[indxx+posi[indx]])?comparador++:comparador=comparador;
	         	        }     
                        if(comparador==sizePatron)cumple=true;                               
	                }
	      }  
	      (cumple)?std::cout<<"si cumple":std::cout<<"no cumple";
	     
	      
 	          

        
    }
    delete[] posi;
	return 0;
}
int considencias(std::string cadena,std::string pat){
    int considencias=0;
    for (int i = 0; i < 10; ++i)
    {
    	if (cadena[i]==pat[0])
    		{
    		 considencias++;
    		} 
    }
    return considencias;
}
int len(std::string cadena){
	//Esta funcion mide el largo de un string
	 int longitud=0;
	 int x=0;

	 do{
	 	
    	if (cadena[longitud]=='\0')
    	{
    	  x=1;	
    	}
        longitud++;

     }while(x!=1);
	return longitud-1;
}