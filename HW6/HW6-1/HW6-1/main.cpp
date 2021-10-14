//
//  main.cpp
//  HW6-1
//
//  Created by Apple on 2019/11/23.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>
#include "customset.h"

int main() {
    
        int a[5] = { 0,6,32,-4,0 };
        CustomSet<int> sample1(a, 5);
        int b[5] = { 4,2,32,-2,0 };
        CustomSet<int> sample2(b, 5);
        CustomSet<std::pair<int, int>> sample3;
//        sample1.add(1);
        sample3=sample1*sample2;
    
        cout << sample3.size() << endl;
        sample1.sortSet();
        sample1.printSet();
    return 0;
}




