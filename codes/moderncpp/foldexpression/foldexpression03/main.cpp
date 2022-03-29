#include <iostream>

void f( int i )
{
    std::cout << i << ' ';
}
//Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
//(E , ...) becomes (E1 , (... , (EN-1 , EN)))
template <typename ... Ts>
void call(Ts... ts)
{
    ( f(ts), ...);
}

//Binary left fold (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)
template <typename ... Ts>
void reverse_call(Ts... ts)
{
    int dummy;
    (dummy = ... = ( f(ts), 0) );
}

//Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
//(E && ...) becomes (E1 && (... && (EN-1 && EN)))
template <typename ... Ts>
void my_and(Ts... ts)
{
    ((f(ts), true) && ...);
}

int main( int argc, char **argv )
{
    {
        my_and(1, 3, 2);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
