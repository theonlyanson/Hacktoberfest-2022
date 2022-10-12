#include <iostream>

using namespace std;

int main()

{

    int m[] = {1, 2, 3, 4, 5, 6, 7};

    int n[] = {8, 9, 10, 11, 12, 13, 14};

    int i = 0;

    int j = 0;

    int k = 0;

    int merge[100];

    while (i < 7 && j < 7)

    {

        if (m[i] < n[j])

        {

            merge[k++] = m[i++];

        }

        else

        {

            merge[k++] = n[j++];

        }

    }

    for (; i < 7; i++)

    {

        merge[k++] = m[i++];

    }

    for (; j < 7; j++)

    {

        merge[k++] = n[j++];

    }

    for (int i = 0; i < 15; i++)

    {

        cout << merge[i] << "\t";

    }

    return 0;

}
