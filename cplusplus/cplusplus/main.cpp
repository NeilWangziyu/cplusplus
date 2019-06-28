//
//  main.cpp
//  cplusplus
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <limits>

using namespace std;


#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a, b;
    int c;
    a = 10;
    b = 20;
    c = a + b;
    
    cout << c <<endl;
    
    int area;
    
    area = LENGTH * WIDTH;
    cout << area <<endl;
    cout << NEWLINE;
    
    auto f = 3.14;
    cout << f <<endl;
    
    int var1;
    char var2[10];
    
    cout << "var1's address: ";
    cout << &var1 << endl;
    
    cout << "var2's address: ";
    cout << &var2 << endl;
    
    int var = 20;
    int *ip;
    
    ip = &var;
    
    cout << "value of var variable:";
    cout << var << endl;
    
    cout << "Address storeed in ip var:";
    cout << ip <<endl;
    
    
    cout <<"Value of *ip variable:";
    cout << *ip << endl;
    
    
    
    return 0;
}
