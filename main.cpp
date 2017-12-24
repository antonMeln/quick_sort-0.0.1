#include <iostream>
#include <sstream>
 
 using namespace std;
 
 bool read( int &n, int *mas){

  string str;
  getline(cin,str);
  istringstream stream(str);
  bool f = true;
  
   for (int i =0;i<n;i++){
     if (!(stream >> mas[i])) {
       f = false;
       break;
       
     }
    }
return f;
}

void quick( int *mas, int left, int right){
  
  int i = left, j =right;
  int x = mas[j];
 
  if (right-left>0){
          while(i<j){
            if(mas[i]>x && i<j){
                     if (i==j-1){
                     swap(mas[i],mas[j]);
                     j--;
                    
                     }
                     else {
                       swap(mas[j],mas[j-1]);
                       swap(mas[i],mas[j]);
                     }
            }
            else i++;
      
    } quick(mas,left,j-1);
      quick(mas,j+1,right);
    
  }
}

int main()
{
  int *a=new int;
  int n;
  string str;
  getline(cin,str);
  istringstream stream(str);
  
   if (stream >> n) {
       if (read(n,a)){
         quick(a,0,n-1);
       }
       for (int i = 0;i<n;i++) cout << a[i] << " ";
     
   } 
   else cout <<"An error has occured while reading input data.";
   return 0;
}
