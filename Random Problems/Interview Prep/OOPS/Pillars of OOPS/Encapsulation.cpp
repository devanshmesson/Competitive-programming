class employee
{
 private:
 string name;
 string company;
 int age;

 public:
 employee(string name,string company,int age)
 {
   this->name=name;
   this->company=company;
   this->age=age;
 }
 //Getters 
 string getName()
 {
   return this->name;
 }
 string getCompany()
 {
   return this->company;
 }
 int getAge()
 {
   return this->age;
 }
 //Setters with some conditions(Conditions are the advantage, we can control who can access)
 void setName(string name)
 {
   if(this->age > 18) this->name=name;
 }
 void setCompany(string company)
 {
   if(this->age > 18) this->company=company;
 }
 void setAge(int age)
 {
   if(this->age > 18) this->age=age;
 }
};
signed main()
{
  employee emp1("Devansh","Google",22);
  employee emp2("Parth","Amazon",17);
  
  emp1.setAge(23);  //Successfull
  cout<<emp1.getName()<<"'s Modified Age is:"<<emp1.getAge()<<endl;

  emp2.setAge(23);  //Un-Successfull, due to age < 18
  cout<<emp2.getName()<<"'s Age is:"<<emp2.getAge()<<endl;
}
