#include <iostream>

using namespace std;

void towerofHanoi(int n, char source, char destination, char auxiliary) {
    if(n == 1){
        cout << "Chuyen dia 1 tu coc " << source << " sang " << destination << endl;
        return;
    }
    //doi n-1 dia tu coc nguon sang coc trung gian
    towerofHanoi(n - 1, source, auxiliary, destination);

    //doi dia n sang coc dich
    cout << "Chuyen dia " << n << " tu " << source << " sang " << destination << endl;

    //doi n-1 dia tu coc trung gian sang coc dich
    towerofHanoi(n - 1, auxiliary, destination, source);
}

int main(){
    int n=3;
    towerofHanoi(n, 'A', 'B', 'C');
    return 0;
}