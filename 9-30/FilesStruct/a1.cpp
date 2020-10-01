//
// Created by Muxxs on 2020/9/30.
//

#include "a1.h"

void p();
void g1();
void g2();
void h();

void f1()
{
    if( 1 ){
        p();
        g1();
    }else{
        g2();
        h();
    }
}//---end f1
