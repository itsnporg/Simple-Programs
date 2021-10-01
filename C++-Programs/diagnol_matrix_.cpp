#include <iostream>
using namespace std;

class Diagnol{
        int *A;
        int n;
    public:
        Diagnol(){
            n = 2;
            A=new int[n];
        }
    Diagnol(int n){
        this->n=n;
        A=new int[n];
    }
    ~Diagnol(){
        delete[] A;}
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagnol::Set(int i, int j, int x) {
    if(i==j)
        A[i - 1] = x;
}

int Diagnol::Get(int i,int j) {
    if (i==j)
        return A[i - 1];
    return 0;
}
void Diagnol::Display(){
    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n;j++)
            {
                if(i==j)
                    cout << A[i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
}

int main() {
    Diagnol d(4);

    d.Set(1, 1, 4);
    d.Set(2, 2, 8);
    d.Set(3, 3, 9);
    d.Set(4, 4, 10);

    d.Display();
}

