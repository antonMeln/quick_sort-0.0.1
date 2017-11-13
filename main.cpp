#include <iostream>
#include <sstream>

using namespace std;

bool read (int & n, float * mas)
{ 
  
  
  string str;
   getline(cin,str);
    istringstream stream(str);
     bool F = true;
    
       for (int i=0;i<n;i++)
        {
          if (!(stream >> mas[i])) { F = false; break;}
        }
   return F;
}
void quickSort (float *mas, int left, int right)
 {  int x, i= left , j = right;
       x = mas[(left+right)/2];
         
         do{
           
           while ( (mas[i] < x) && (i < right) ) i++;
           while ( (mas[j] > x) && (j > left ) ) j--;
           
          if (i <= j) { swap(mas[i], mas[j]);
                        i++;
                        j--;
          }
            } while (i <= j);
           
      if (left < j) quickSort(mas, left , j);
      if (right > i) quickSort(mas, right , i);
      }     
           
           
int main ()
 { 
  
   float *mas = new float; 
   int i,n;
   string str;
   getline(cin,str);
   istringstream  stream (str);
    
       if (stream >> n ) {   
         if ( read (n , mas) ){
           for (i = 0; i < n; i++) {
              quickSort(mas, 0, n-1);
         } }
   
   for (i = 0 ; i < n; i++)
      cout << mas[i] << " ";
       }
       
                else {cout << "An error has occured while reading input data." ; } 
   return 0;
 }
                  
                  
