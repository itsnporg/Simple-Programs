/* One of my favorite Sorting Algorithm(Bogosort) written in C++
   by Rahul Kumar Chaurasiya
   On 2021-10-01
   
   Last I checked it took about 15.35 minutes to sort a list of 13 elements. Pretty fast, isn't it?
*/

#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>

using namespace std;

void printArray(const vector<int> &A) {
    
    for(int i = 0; i < A.size(); i++) {
        cout<< A[i] <<" ";
    }
    cout<<endl;
}

void swap(int* const A, int* const B) {
    int t = *A;
    *A = *B;
    *B = t;
}


void random_shuffle(vector<int> &A) {
    int val;
    int temp;
    int size = A.size();
    
    for(int i = 0; i < size; i++) {
        swap(&A[rand()%size],&A[--size]);
    }
}

bool isSorted(const vector<int> &A) {
    int size = A.size();
    for(int i = 0; i < size - 1; i++) {
        if(A[i] > A[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {

    using namespace std::chrono;
    srand(time(0));

    vector<int> A = {19,1,8,4,-8,13,11,-3, 23, 7, -2};

    cout << "\nBefore Sorting: ";
    printArray(A);      
    int shuffleCount = 0;
        
    high_resolution_clock::time_point start_time = high_resolution_clock::now();

    while(!isSorted(A)) {
        random_shuffle(A);
        shuffleCount++;
    }
    high_resolution_clock::time_point end_time = high_resolution_clock::now();

    duration<double, std::milli> time_span = end_time - start_time;
    
    cout<<"\nSorted in "<<time_span.count()<<" ms after "<< shuffleCount <<" shuffles"<<endl;

    cout << "\nAfter Sorting: ";
    printArray(A);   

}
