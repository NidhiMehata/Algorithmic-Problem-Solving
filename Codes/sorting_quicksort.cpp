#include <iostream>
#include <vector>

using namespace std;

template<class T>
void swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
int partition(vector<T>& a, int low, int high){
    int i = low - 1;
    T pivot_ele = a[high];

    for(int j = low; j < high; j++){
        if( a[j] < pivot_ele ){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return (i+1);
}

template<class T>
void quicksort(vector<T>& a, int low, int high){
    int j;
    if( low < high ){
        j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    cout<<"After Sorting : "<<endl;

    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
}
