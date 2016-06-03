//
//  main.cpp
//  timer-class
//
//  Created by Cabana on 6/1/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include <iostream>
#include "timer.h"
int main()
{
    timer aTimer;
    aTimer.Start();
    for( int i = 1; i < 10; i++ )
    {
        std::cout << i << std::endl;
        while( aTimer.GetTicks() < 1000000 );
        aTimer.Reset();
    }
    std::cout << "FIRE!" << std::endl;
    return 0;
}
