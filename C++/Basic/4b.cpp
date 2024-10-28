#include <iostream>
using namespace std;
int array[10];
int main()
{
    while (cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4] >> array[5] >> array[6] >> array[7] >> array[8] >> array[9])
    {
        // for(int i=0;i<10;i++){
        //     cin>>array[i];
        // }
        int sorted[10] = {};
        int sortedIndex[10];
        for (int init = 0; init < 10; init++)
        {
            sortedIndex[init] = -1;
        }
        for (int counter = 0; counter < 10; counter++)
        {
            int max, max_index = 0, max_allocated = 0;
            for (int indexForMax = 0; indexForMax < 10; indexForMax++)
            {
                int skip = 0;
                for (int indexForUsed = 0; indexForUsed < 10; indexForUsed++)
                {
                    if (sortedIndex[indexForUsed] == indexForMax)
                    {
                        skip = 1;
                    }
                }
                if (skip)
                {
                    continue;
                }
                if (max_allocated == 0)
                {
                    max = array[indexForMax];
                    max_index = indexForMax;
                    max_allocated = 1;
                }
                if (array[indexForMax] > max)
                {
                    max = array[indexForMax];
                    max_index = indexForMax;
                }
            }
            sorted[counter] = max;
            sortedIndex[counter] = max_index;
        }
        for (int i = 0; i < 10; i++)
        {
            cout << sorted[i] << " " << sortedIndex[i] << endl;
        }
    }

    return 0;
}
// int main(){
//     for(int i=0;i<10;i++){
//         cout<<">>array["<<i<<"]";
//     }
//     return 0;
// }