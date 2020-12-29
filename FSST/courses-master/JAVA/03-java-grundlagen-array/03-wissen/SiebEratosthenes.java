// mab: SiebEratosthenes.java
// ----------------------------------------------------------------------------
// Was gibt das folg. Programm aus?
// Gib der ersten 5 Ausgabewerte an.

public class SiebEratosthenes{
   public static void main(String[] args){
      int[] f= new int[500]; //Array with 500 int-Elements
      int j;

      for (int i=1;i<500;i++)   
         f[i]=i; // fill Array

      j=2;
      while(j<250){
         for(int i=2*j; i<500; i=i+j)
            f[i]=0;

         j++;
         while(f[j]==0)
            j++;
      }

      for(int i=2; i<500; i++)
         if(f[i]!=0)
            System.out.print(i+ ",");

      System.out.println();
      
   }
}
