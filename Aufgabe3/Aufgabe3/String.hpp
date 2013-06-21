#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;

class String {

	private:

		int size;	// ohne Nullterminator
		char* str; 
	

	public:
		const char* getStr() const { return str;} // inline --> direkt implementiert
		int getSize() const { return size;}

	//Konstruktoren
		//Konstruktor ohne Parameter
		String() { 
			size = 0;
			str = new char[1];
			str[0] = '\0';
		}

		//Konstruktor mit Parameter
		String(char c) {
			size = 1;
			str = new char[2];
			str[0] = c;
			str[1] = '\0';
		}

		//Konstruktor, der neue Zeichenkette anlegt, indem er char kopiert
		String(char* c) {
			str = nullptr;
			kopiere(c);
		}

		//Konstruktor, der neue Zeichenkette anlegt, indem er anderen von anderem String Zeichen kopiert 
		String(const String& s){
			str = nullptr;
			kopiere(s.str);
		}

		//Destruktor
		~String() { delete[] str; }

		// make friend, so we can access private members
		friend ostream& operator<< (ostream &out, String &s);

		//überladene Konstruktoren
		char & operator[](int index);
		char operator[](int index) const;

		 String& operator= (const String &s);
		 void operator+=(const String&);


	private:
		/*
		1. alles leer machen, falls str noch nicht leer ist 
		2. gibt länge des Array zurück (nullterminator exklusive)
		3. +1 für Nullterminator
		4. Kopieren von c nach str
		5. Nullterminator am Ende anhängen
		*/
		void kopiere(char* c) {
			//1.
			if (str != nullptr){
				delete[] str;
			}

			//2.
			size = strlen(c);
			
			//3.
			str = new char[size + 1]; 
			
			//4.
			for (int i = 0; i < size; i++) {
				str[i] = c[i];

			}
			//5.
			str[size] = '\0';
		}
};



// Nicht-konstanter Index-Operator, gibt Referenz auf Zeichen zurück, so dass es
// geändert werden kann

   char& String::operator[](int index) {   
    
	   if (index > size){
		     return str[size-1];	//letztes Zeichen zurückgeben, falls Index größe überschreitet
	   }else if(index < 0){ 
			return str[0];
	   }else {
		 return str[index];
	   }
  }


// konstanter Index-Operator für konstante Objekte(Kopierkonstruktor )
   char String::operator[](int index)const
   {     
	   if (index > size){
			return str[size-1];
	   }else if(index < 0){ 
			return str[0];
	   }else{ 
			return str[index];
	   }
		 
  }


//definiert Ausgabe
ostream& operator<< (ostream &out, String &s) {// &out Einganereferenz, ostream Ausgabe

	for(int i=0; i<s.size; i++)
		{out << s.str[i];}

	return out;
}

//defineriert =-Operator
String& String:: operator= (const String &s){ 
	// x = y = z = "test"
	//Selbstzuweisung prüfen
	if(this == &s){
		return *this;
	}

	delete [] str;

	size = s.getSize();
	str = new char[size+1]; // neues Array der größde des neuen Strings

	for(int i = 0; i<size; i++){
		str[i]= s[i];
	}
	str[size]= '\0';

	return *this;
}

//definiert +=-Operator
 void String:: operator+=(const String& s) {
 
    int sSize = s.getSize();
	int totalSize = size + sSize;
	char* temp = new char [totalSize+1];                   //String  temp(totalSize);
	int i; 
      
	 //altes s1 kopieren in temp
      for ( i = 0; i < size; i++){
        temp[i] = str[i];
	  }
	  //s2 anhängen
      for (int j = 0; j < s.getSize(); j++, i++){

		  temp[i] = s[j];
       
	  }
      temp[totalSize]='\0';

	  delete [] str;
	  str = temp;
      
   }



#endif 