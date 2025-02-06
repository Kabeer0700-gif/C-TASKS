#include <iostream>
using namespace std;

int **allocateMemory(int r, int c)
{
      int **ptr;
      ptr = new int *[r];
      for (int i = 0; i < r; i++)
      {
            ptr[i] = new int[c];
      }
      return ptr;
}

void setMatrix(int **ptr, int r, int c)
{
      for (int i = 0; i < r; i++)
      {
            cout << "ROW " << i + 1 << endl;
            for (int j = 0; j < c; j++)
            {
                  cout << "ColumN " << j + 1 << "\t";
                  cin >> *(*(ptr + i) + j);
            }
      }
}
void showMatrix(int **ptr, int r, int c)
{
      for (int i = 0; i < r; i++)
      {
            for (int j = 0; j < c; j++)
            {
                  cout << *(*(ptr + i) + j) << " ";
            }
            cout << endl;
      }
}

void addMatrix(int **ptr, int **gtr, int r, int c)
{
      int sum[r][c] = {0};
      for (int i = 0; i < r; i++)
      {
            for (int j = 0; j < c; j++)
            {
                  sum[i][j] = ptr[i][j] + gtr[i][j];
            }
      }
      for (int i = 0; i < r; i++)
      {
            for (int j = 0; j < c; j++)
            {
                  cout << sum[i][j]<<" ";
            }
            cout << endl;
      }
}
void subtMatrix(int **ptr, int **gtr, int r, int c)
{
      int subt[r][c] = {0};
      for (int i = 0; i < r; i++)
      {
            for (int j = 0; j < c; j++)
            {
                  subt[i][j] = ptr[i][j] - gtr[i][j];
            }
      }
      for (int i = 0; i < r; i++)
      {
            for (int j = 0; j < c; j++)
            {
                  cout << subt[i][j]<<" ";
            }
            cout << endl;
      }
}

void freeMemory(int **p, int r)
{
      for (int i = 0; i < r; i++)
      {
            delete[] p[i];
      }
      delete p;
}
int main()
{
      int rows, cols;

      cout << "enter number of rows\n";
      cin >> rows;
      cout << "enter number of columns\n";
      cin >> cols;

      int **ptr = allocateMemory(rows, cols);
      setMatrix(ptr, rows, cols);
      int **gtr = allocateMemory(rows, cols);
      setMatrix(gtr, rows, cols);
      cout << "MATRIX: 1\n";
      showMatrix(ptr, rows, cols);
      cout << "\n";
      cout << "MATRIX: 2\n";
      showMatrix(gtr, rows, cols);
      addMatrix(ptr, gtr, rows, cols);
      cout<<"\n";
      subtMatrix(ptr, gtr, rows, cols);
      freeMemory(ptr, rows);
      freeMemory(gtr, rows);
}