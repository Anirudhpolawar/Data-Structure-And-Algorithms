#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool check(string a,string b)
{

    
    string ab = a.append(b); 
  
    // then append X at the end of Y 
    string ba = b.append(a); 
  
    // Now see which of the two formed numbers is greater 
    return ab.compare(ba) > 0 ? 1: 0; 


}

string largest_number(vector<string> a) {
  //write your code here
 sort(a.begin(),a.end(),check);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
