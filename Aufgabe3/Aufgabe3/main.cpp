#include "String.hpp"
#include <iostream>
using namespace std;


int main() {
  String s1;
  String s2("Hello");
  String s3(s2); 
  //String s4("Juhuuu es geht");

	s1 += s2;
  
	s2= s3;

  cout << s2 << endl;
  cout << s2[ 2 ] << endl;

  getchar();
};

