/* 
   Author:
   Date:
   Class: CSC-1720
   Code location:
   
   About: 
*/
#ifndef EMP_TYPE
#define EMP_TYPE

#include<iostream>
#include<iomanip>

using namespace std;

class empType {
   private:
      string name;
      int age;
      double salary;
      int id;
   public:
      /* Four set methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      void setName(string name_in);
      void setAge(int age_in);
      void setSalary(double salary_in);
      void setid(int);

      /* Four get methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      string getName(void) const;
      int getAge(void) const;
      double getSalary(void) const;
      int getid() const;
      /* Two constructors, one default and the other with passed parameters
         pre-condition: sets instances
         post-conditoon: sets parameters to zero; initialize all instance 
                         variables from input parameters. If name is an
                         empty string then output an error message with cerr. 
                         Likewise age must be >=18, id and salary must
                         be positive values. 
                         In case of bad age, id, or salary, use cerr to output 
                         an error message containing the values.
      */
      empType();
      empType(int eid, string iname, int iage, double isalary);
};
#endif
