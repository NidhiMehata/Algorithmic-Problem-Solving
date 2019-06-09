#include<iostream>
using namespace std;

class UnionFind{
    private:
        int *a;
        int size;
    
    public:
        UnionFind(int s){
            size = s;
            a = new int[s];
            for(int i = 0; i < s; i++) a[i] = i;
        }

        ~UnionFind(){
            delete [] a;
        }

        void zeta(int x, int y){
            int val_x = a[x];

            for(int i = 0; i < size; i++){
                if(a[i] == val_x){
                    a[i] = a[y];
                }
            }
        }

        int find(int x, int y){
            return (a[x] == a[y]? 1 : 0);
        }

        void print_array(){
            for(int i = 0; i < size; i++){
                cout << a[i] << "\t";
            }
            cout << "\n";
        }

};

int main(){
    UnionFind u = UnionFind(7);

    u.zeta(0, 1);
    u.zeta(1, 2);
    u.zeta(3, 4);
    u.zeta(2, 4);
    u.zeta(6, 1);

    u.print_array();

    cout << u.find(1,5) << endl;
    
    return 0;
}