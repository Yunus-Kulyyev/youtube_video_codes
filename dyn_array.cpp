#include <iostream>

using namespace std;

int SIZE = 0;
int *expandingArray;

void push_number(int n);
void display();

int main()
{
    expandingArray = new int[SIZE];

    int input;
    do{
        cout << "Enter #" << SIZE+1 << ": ";
        cin >> input;
        push_number(input);
    }while(input != -1);

    display();
}

void display()
{
    for(int i = 0; i < SIZE; i++) {
        cout << expandingArray[i] << endl;
    }
}

void push_number(int n)
{
    if(SIZE == 0){
        expandingArray[0] = n;
    }
    else {
        int* temp = new int[SIZE];
        for(int i = 0; i < SIZE; i++) {
            //We are copying everything into temp array
            temp[i] = expandingArray[i];
        }
        expandingArray = new int[SIZE+1];
        for(int i = 0; i < SIZE; i++) {
            expandingArray[i] = temp[i];
        }
        expandingArray[SIZE] = n;
    }
    SIZE++;
}
