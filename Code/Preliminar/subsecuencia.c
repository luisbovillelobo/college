
#include <stdio.h>

void main()
{
   const char MARCA = '$'; 
   int ant, act, antlg = 0, actlg = 0, cont = 0;

   if((ant = getchar()) == MARCA)
   {
      printf("\n Secuencia vacia\n");
      return;
   }

   actlg++;

   while((act = getchar()) != MARCA)

      if(ant == act)    
             actlg++;
      else 
      {
          if(antlg >= actlg)
                break;

          antlg = actlg;        
          actlg = 1;
          ant = act;
          cont++;
      }
   
   if(antlg < actlg)
        printf("\n Secuencia CL, numero de subsecuencias = %d\n",cont + 1);
   else printf("\n secuencia no CL\n");

}