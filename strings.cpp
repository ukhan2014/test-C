#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    //print two space-separated integers, representing 
    //the length of  and  respectively. 
    cout << a.size() << " " << b.size() << endl;
    
    //print the string produced by concatenating a and b
    cout << a << b << endl;
    
    //swap first letters and print strings separated by
    //a space
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b << endl;
    
  
    return 0;
}
