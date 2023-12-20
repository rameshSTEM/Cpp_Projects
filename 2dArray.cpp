#include <iostream>
#include <cstdlib>
using namespace std;

int main();
class Sum
{
public:
    int *rowSum;
    int *colSum;
    int rows;
    int cols;

    // constructor to dynamically allocate mmemory
    Sum(int r, int c) : rows(r), cols(c)
    {
        rowSum = new int[rows];
        colSum = new int[cols];
    }

    // destructor
    ~Sum()
    {
        delete[] rowSum;
        delete[] colSum;
    }
};

// building a 2d array with dynamic memory allocation
void fillArray(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //arr[i][j] = rand() % 100;
            int enter;
            cout<<"Enter a number at "<<i<<"th row and "<<j<<"th col : ";
            cin>>enter;
            arr[i][j] = enter;
        }
        cout<<endl;
    }
}

// calculate sum of rows and cols
void calculateSums(int **arr, int rows, int cols, Sum &sum)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum.rowSum[i] += arr[i][j];
            sum.colSum[j] += arr[i][j];
        }
    }
}

// print 2d array
void printArray(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

// printing sums of rows and cols
void printSums(const Sum &sum)
{
    cout << "Row sums: ";
    for (int i = 0; i < sum.rows; i++)
    {
        cout << sum.rowSum[i] << " ";
    }
    cout << endl;

    cout << "Column sums: ";
    for (int j = 0; j < sum.cols; j++)
    {
        cout << sum.colSum[j] << " ";
    }
    cout << endl;
}

//to find the max no in the 2d array
void findMAx(int** arr, int rows, int cols, int max, int& maxRow, int& maxCol){
    max = arr[0][0];
    maxRow = 0;
    maxCol = 0;
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(max<arr[i][j]){
        max = arr[i][j];
        maxRow = i;
        maxCol = j;

      }
    }
  }
  cout<<"Max number in the 2d array is : "<<max<<" at "<<maxRow<<"th row and "<<maxCol<<"th col."<<endl;
}


int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of cols: ";
    cin >> cols;

    // allocate mem for 2d array
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // filling the array
    fillArray(arr, rows, cols);

    //sum object
    Sum sum(rows, cols);

    //calculate sums
    calculateSums(arr, rows, cols, sum);

    //print the 2d array
    cout<<"2D Array: "<<endl;
    printArray(arr, rows, cols);

    //sum
    printSums(sum);

    //max num
    int max, maxRow, maxCol;

    findMAx(arr, rows, cols, max, maxRow, maxCol);

    for(int i=0; i<rows; i++){
        delete arr[i];
    }

    delete[] arr;


    return 0;
}

