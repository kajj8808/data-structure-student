#include <iostream>

using namespace std;

int main (){
    int num = 3;

    int totalMoves = (1 << num) - 1;

    cout<< totalMoves << "\n";
}