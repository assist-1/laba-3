/*!
\file
\brief  файл с описанием классов и функций

Данный файл содержит в себе определения основных
классов, используемых в  программе
*/
#include "Functions.h"

/*!
   \code
   int operator<(const Obj& obj1, const Obj& obj2){
    return obj1.start < obj2.start;
}
   \endcode
   */
int operator<(const Obj& obj1, const Obj& obj2){///перегрузка оператора меньше, чтобы сраванивать объекты типа Obj по координате начала
    return obj1.start < obj2.start;
}
/*!
   \code
   void swapp(Obj& a, Obj& b){
    Obj k;
    k = a;
    a = b;
    b = k;
}
   \endcode
   */
void swapp(Obj& a, Obj& b){///функция которая меняет два элемента(аналог std::swap)
    Obj k;
    k = a;
    a = b;
    b = k;
}
/*!
   \code
   double max(double& a, double& b){
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}
   \endcode
   */
double max(double& a, double& b){///функция которая берет максимум из двух чисел(аналог std::max)
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}
