#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void read(double* p, const int N, const string fname);		//function that stores data from a file into an array 
void filter(double* p, const int N);				//function that applies filter
void print(const string pword, double* p, const int N);		//function that writes the results into a file

int main(void){
  
  const int N = 237; 
  const string fname = "noisy.txt";
  double* p = new double[N];
  const string pword = "results";
  stringstream s;
  int n=1;
  
  read(p,N,fname);
  
  cout << "Right now, the filter will be applied" << "\t" << n << "\t" << "time(s). How often should it be applied?" << endl;
  cin >> n;
  while (n<0) { 
    cout << "Please enter a number larger or equal to 0, so the filter can be applied or skip, respectively" << endl;
    cin >> n;  
    }
 
  for(int i=1; i<=n; i++){
    if (n==0) break;
  filter(p,N);
  }
  
  s.str("");							// empty stringstream
  s << pword << "_" << n << ".txt";				// file with number of applied filters at the end will be printed
  print(s.str(),p,N);
  
//   for(int i=0; i<N; i++){
//   cout << "p[" << i << "]=" << p[i] << endl;
//   }

delete[] p;  
 
return 0;
}


void read(double* p, const int N, const string fname){		
  ifstream in(fname.c_str());					//create input file stream
  for(int i=0; i<N; i++){
    in >> p[i];							//every entry is stored in p
  }
  in.close();							//close input flie stream
}


void filter(double* p, const int N){
  double a;
  double b=0;
  for(int i=0; i<N-1; i++){
  a=p[i];
  p[i]=(b + p[i] + p[i+1])/3;
  b=a;
  }
 p[N-1] = (b + p[N-1] + 0)/3; 
}


void print(const string pword, double* p, const int N){
  ofstream out(pword.c_str());					//create output file stream
  for(int i=0; i<N; i++){
    out << p[i] << endl;					//every entry is stored in file reaults
  }
  out.close();							//close output file stream
}