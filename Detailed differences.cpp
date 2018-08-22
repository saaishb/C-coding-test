#include <iostream>
#include <string>
using namespace std;
int main(){
    int count, i, j, length;
    string first, second;
    cin >> count;
    for(i=0; i<count; i++){
        cin >> first >> second;
        cout << first << endl << second << endl;
        length = first.size();
        for(j=0; j<length; j++){
            if(first[j]!=second[j]){
                cout << '*';
            }
            else{
                cout << '.';
            }
        }
    cout << endl<<endl;
    }
}
