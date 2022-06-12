#include <iostream>

template <typename... Args> bool plot()
{
    std::cout << "plot() number of Args = " << sizeof ... (Args) <<std::endl;
    return true;
}

bool plot()
{
    std::cout << "my plot()" <<std::endl;
    return true;
}

int main( int argc, char **argv )
{
    plot();
    plot<>();
    plot<int>();
    plot<int, float>();
    return 0;
}
