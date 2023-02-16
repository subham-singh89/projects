#include<iostream>

using std::string;
bool validatepassword(string input)
{
  if(input.length()<6)
  {
    return false;
  }
  bool hasUpper=false;
  bool hasLower=false;
  bool hasDigit=false;
  bool hasSpecial=false;

  for(char cha : input)
  {
    if(isupper(cha))
    {
        hasUpper=true;
    }
    else if(islower(cha))
    {
        hasLower=true;
    }
    else if(isdigit(cha))
    {
        hasDigit=true;
    }
    else if(!isalnum(cha))
    {
        hasSpecial=true;
    }
    if(hasUpper && hasLower && hasDigit && hasSpecial)
    {
        break;
    }
  }
  return hasUpper && hasLower && hasDigit && hasSpecial;
}
int main()
{   
    string userinput;
    std::cin>>userinput;
    std::cout<<std::boolalpha<<validatepassword(userinput);
}
