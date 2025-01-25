#include <iostream>
using namespace std;

void trappingwater(int height[], int n)
{
    int leftmax[20000];
    int rightmax[20000];
    leftmax[0] = INT8_MIN; 
    rightmax[n - 1] = INT8_MIN;
    // cout << leftmax[0] << " ";
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(height[i - 1], leftmax[i - 1]);
        // cout << leftmax[i] << " ";
    }
    // cout << endl;
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(height[i + 1], rightmax[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        // cout << rightmax[i] << " ";
    }
    // cout << endl;
    int trapwater = 0;
    int currtrapwat[20000];
    for (int i = 0; i < n; i++)
    {
        currtrapwat[i] = min(rightmax[i], leftmax[i]) - height[i];
        if (currtrapwat[i] < 0)
        {
            currtrapwat[i] = 0;
        }
        // cout << currtrapwat[i] << " ";
        trapwater = trapwater + currtrapwat[i];
    }
    // cout<<endl;
    cout << "Trap Water = " << trapwater;
}

int main()
{
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(int);
    trappingwater(height, n);
    return 0;
}
