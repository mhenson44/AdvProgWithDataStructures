/*
   Name:Michael Henson  
   Class:Csc1720
   Date:01/26/20201
   Path:~/mhenson/csc1720/program1/counterType.h

   Desciption:header file with pubic and private variables for the implementation file
*/
#ifndef COUNTER_TYPE
#define COUNTER_TYPE

class counterType {
   //public variables
   public:
      void initializeCounter();
      void setCounter(int = 0);
      int getCounter() const;
      void incrementCounter();
      void decrementCounter();
      void displayCounter() const;
      counterType(int);
      counterType();
   //private variables
   private:
      int counter;
    
};
#endif
