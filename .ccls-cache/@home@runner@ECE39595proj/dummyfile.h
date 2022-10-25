//.H FILE::

class Singleton {
public: 
   static Singleton* getInstance( );
private:
   static Singleton* uniqueInstance;
   // other instance variables here
   Singleton( ); // could have arguments 
};
#endif /* SINGLETON_H_ */

//.CPP FILE

#include "Singleton.h"

Singleton* Singleton::uniqueInstance = nullptr;

Singleton::Singleton( ) { } 

Singleton* Singleton::getInstance( ) {
   if (uniqueInstance == nullptr) {
      uniqueInstance = new Singleton( );
   }
   return uniqueInstance; 
}

//MAIN:
Singleton* singleton1 = Singleton::getInstance( );
Singleton* singleton2 = Singleton::getInstance( );