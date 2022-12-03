public class Program {
    public static int[] Simula(int[] colores, int[] posiciones, int[] pista){
        // si en posiciones hay algo negativo ponerlo al principio
        // si hay algo mayor que el tamaño del array ponerlo al final.
        /* el método insertar no se ve tan complicado de implementar, la cosa
        está en el método reducir porque dig
        */
                     int get_left(int posicion, int[] pista){
                  if(posicion >= pista.Length){posicion = pista.Length-1;}       
                  int result = posicion;
                  for (int i = posicion-1; i >= 0; i--){
                      if(pista[i] == pista[posicion]){result = i;}
                      else { return result;}    
                      
                    }
                  return result;  
                  }
             int get_right(int posicion, int[] pista){
                  if(posicion >= pista.Length){posicion = pista.Length-1;}
                  int result = posicion;
                  for (int i = posicion+1; i < pista.Length; i++){
                      if(pista[i] == pista[posicion]){result = i;}
                      else { return result;}    
                      
                    }
                   return result;  
                  }       
        int check_position (int a, int[] pista){
            if (a<0){return 0;}
            else if(a >pista.Length){return pista.Length;}
            else { return a;}}
        
        for (int i = 0; i < posiciones.Length; i++)
        {
            int pos = check_position(posiciones[i],pista); 
            pista = Insertar(colores[i], posiciones[i], pista);
            bool c = true;
            int left = get_left(pos, pista); // maybe itself
            int right = get_right(pos, pista);
            int consecutives = right -left + 1;
            while(consecutives >= 3 && c){
                  int[] r = new int[pista.Length - consecutives];
                  for (int j = 0; j < left; j++)
                  {
                      r[j] = pista[j];
                  }
                  for (int j = right+1; j < pista.Length; j++)
                  {
                      r[j - consecutives] = pista[j];
                  }  
                  pista = r;
                  pos = left;
                  left = get_left(pos, pista); // maybe itself
                  right = get_right(pos, pista);
                  consecutives = right -left + 1;
                  if (left < pos){c = true;}
                  else {c = false;}
                }

            
        }
        int[] Insertar(int color, int posicion, int[] pista){              
              posicion = check_position(posicion, pista);
              int[] r = new int[pista.Length+1];
              for (int i = 0; i < posicion; i++)
              {
                  r[i] = pista[i];
              }
              r[posicion] = color;
              for (int i = posicion+1; i < r.Length; i++)
              {
                  r[i] = pista[i-1];
              }
              return r;
            }
        return pista;
    }

    public static void Main(){
        int[] col1 = {4,4,-1,100,3,2,2,2};
        int[] pos1 = {5,3,8,-15,6,2,2,2};
        int[] pista = {100,4,100,100,100};
        int[] result = Simula(col1 ,pos1 ,pista);
        int[] otherresult = Zuma.Simula(col1,pos1, pista);
        for (int i = 0; i < result.Length; i++)
        {
            Console.Write(result[i] + " ");
        }
        Console.WriteLine("        ");
        for (int i = 0; i < result.Length; i++)
        {
            Console.Write(otherresult[i] + " ");
        }
    }
}


    public class Zuma
    {
        public static int[] Simula(int[] colores, int[] posiciones, int[] pista)
        {
            for (int i = 0; i < colores.Length; i++)
            {
                int color = colores[i];
                int pos = posiciones[i];

                pista = Inserta(pos, color, pista);
                if(pos<0)
                {
                    pos = 0;
                }
                else if(pos>=colores.Length)
                {
                    pos = pista.Length - 1;
                }

                if (FormaTres(pos, pista))
                {
                    pista = Reducir(pos, pista);
                }
                
            }
            return pista;
        }
        public static int[] Inserta(int pos,int color,int[] pista)
        {
            int[] auxiliar = new int[pista.Length+1];
            if(pos<0)
            {
                auxiliar[0] = color;
                for(int i = 0; i < pista.Length; i++)
                {
                    auxiliar[i + 1] = pista[i];
                }
            }
            else if(pos>=pista.Length)
            {
                auxiliar[auxiliar.Length - 1] = color;
                for(int i = 0; i < pista.Length; i++)
                {
                    auxiliar[i] = pista[i];
                }
            }
            else
            {
                for(int i = 0; i < pos;i ++)
                {
                    auxiliar[i] = pista[i];
                }
                auxiliar[pos] = color;
                for(int i = pos; i < pista.Length; i++)
                {
                    auxiliar[i + 1] = pista[i]; 
                }
            }
            pista = new int[auxiliar.Length];
            for(int i = 0; i < auxiliar.Length;i++)
            {
                pista[i] = auxiliar[i];
            }
            return pista;
        }
        public static int[] Reducir(int pos,int[] pista)
        {
            bool reducido = false;
            int iteracion = 0;
           
            while(!reducido)
            {
                reducido = true;

                /*Console.WriteLine("dfdf");
                for(int i = 0; i < pista.Length; i++)
                {
                    Console.WriteLine(pista[i]);
                }*/

                if((pos>=0 && pos<pista.Length-1 ) && (iteracion==0 || (pos-1>=0 && pista[pos]==pista[pos-1] && FormaTres(pos,pista)) ) )
                {
                    iteracion++;

                    for (int i = 0; i < pista.Length - 2; i++)
                    {
                        int cont = 0;
                        int j = 0;
                        for (j = i + 1; j < pista.Length; j++)
                        {
                            if (pista[i] == pista[j])
                            {
                                cont++;
                            }
                            else
                                break;
                        }
                        j--;
                        if (cont >= 2 && pos >= i && pos <=j && i>=0 && i < pista.Length && j>=0 && j < pista.Length)
                        {
                            pos = i;
                            pista = EliminarRango(i, j, pista);
                            reducido = false;
                            break;
                        }
                    }
                }
                
            }
            return pista;
        }
        public static int[] EliminarRango(int a, int b, int[] pista)
        {
            int[] auxiliar = new int[pista.Length-( (b-a)+1)];
            int piv = 0;
            for(int i = 0; i < a; i++)
            {
                auxiliar[piv] = pista[i];
                piv++;
            }
            for(int j  = b+1; j< pista.Length; j++)
            {
                auxiliar[piv] = pista[j];
                piv++;
            }
            pista = new int[auxiliar.Length];
            for(int i = 0; i < auxiliar.Length; i++)
            {
                pista[i] = auxiliar[i];
            }
            return pista;
        }
        public static bool FormaTres(int pos, int[] pista)
        {
            for (int i = 0; i < pista.Length-2; i++)
            {
                    if(pista[i]==pista[i+1] && pista[i]==pista[i+2] && pos<=i+2 && pos>=i)
                    return true;     
            }
            return false;
        }
    }

