#include <iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
#define SQUARE_SIZE 9


int anyLine = 0;
int currLine = 0;
int numSolutions = 0;


// swap two values in the square.
void swap(int arr[], int idxa, int idxb)
{
    int tmp = arr[idxa];
    arr[idxa] = arr[idxb];
    arr[idxb] = tmp;
}

void printArray(int arr[])
{
    for (int i = 0; i < SQUARE_SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

// this function tests to see if we have a "good" arrangement of numbers
// i.e the sum of each row, column and diagonal is equal

bool checkArr(int arr[])
{
    anyLine = arr[0] + arr[1] + arr[2];
    currLine = 0;
    for (int i = 0; i < SQUARE_SIZE; i++)
    {
        Sleep(0.75);
        currLine += arr[i];
        if ((i + 1) % 3 == 0)
        {
            if (currLine != anyLine)
                return false;
            currLine = 0;
        }
    }

    // check vertically
    for (int col = 0; col <3; col++)
    {
        for (int row = 0; row <3; row++)
        {
            currLine += arr[col + 3 * row];
        }

        if (currLine != anyLine)
            return false;

        currLine = 0;
    }

    // check the diagonals
    if ((arr[2] + arr[4] + arr[6]) != anyLine)
        return false;

    if ((arr[0] + arr[4] + arr[8]) != anyLine)
        return false;

    return true;
}

void solve(int arr[], int pos)
{
    Sleep(0.5);
    if (pos == 8)
    {
        if (checkArr(arr))
        {
            printArray(arr);
            numSolutions++;
        }
    }
    else
    {
        for (int i = pos ; i < 9; i++)
        {
            
            swap(arr,pos,i);
            solve(arr,pos +1);
            swap(arr,pos,i);
        }
    }
}

int main()
{
    int arr[SQUARE_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    clock_t s,e;
    s=clock();


    solve(arr, 0);
    e=clock();
    cout << "number of solutions is: " << numSolutions << endl;
    cout<<"Time taken="<<(double)(e-s)/CLK_TCK;

    return 0;
}