#include "ecealptekin_Alptekin_Ece_HW5_header.h"

Matrix::Matrix()
{
    rowNumber = 0;
    columnNumber = 0;
    data = NULL;
}

Matrix::Matrix(int rowNum,int columnNum,int init)

{
    if(rowNum > 0 && columnNum > 0)
    {
    rowNumber = rowNum;
    columnNumber = columnNum;
    data = new int * [rowNum];

    for (int i = 0; i<rowNumber; i++)
    {
        data[i] = new int[columnNumber];
    }

    for(int j=0; j<rowNum; j++)
    {
        for(int k=0; k<columnNum; k++)
        {
            data[j][k] = init;
        }
    }
    }

    else
    {
        rowNumber = 0;
        columnNumber = 0;
        data = NULL;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i< rowNumber; i++) // Returning memory to free heap 
        delete [] data[i];
    delete [] data;
}

int Matrix::getRowNumber() const
{
    return rowNumber;
}

int Matrix::getColumnNumber() const
{
    return columnNumber;
}

void Matrix::setElementAt(int rowNumber,int columnNumber,int number)
{
    data[rowNumber][columnNumber] = number;
}

int Matrix::getElementAt(int rowNumber,int columnNumber) const
{
    return data[rowNumber][columnNumber];
}

void Matrix::print()
{
    for(int i=0; i<rowNumber; i++)
    {
        for(int j=0; j<columnNumber; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix::Matrix(const Matrix & Matrix)
{
    this->rowNumber = Matrix.rowNumber;
    this->columnNumber = Matrix.columnNumber;

    this->data = new int * [this->rowNumber];

    for (int i = 0; i <this->rowNumber; i++)
	{
        this->data[i] = new int[this->columnNumber];
        for (int j = 0; j <this->columnNumber; j++)
        {
            this->data[i][j] = Matrix.data[i][j];
        }
	}
}

Matrix Matrix::operator+(const Matrix & matrix)
{
    Matrix mat(matrix); //creates a copy of matrix

    for(int i=0; i<this->rowNumber; i++)
    {
        for(int j=0; j<this->columnNumber; j++)
        {
            mat.data[i][j] = this->data[i][j] + matrix.data[i][j];
        }
    }
    return mat;
}

Matrix Matrix::operator-(const Matrix & matrix)
{
    Matrix mat(matrix); //creates a copy of matrix

    for(int i=0; i<this->rowNumber; i++)
    {
        for(int j=0; j<this->columnNumber; j++)
        {
            mat.data[i][j] = this->data[i][j] - matrix.data[i][j];
        }
    }
    return mat;
}

const Matrix & Matrix::operator=(const Matrix & matrix)
{
	if(this != &matrix)	 //do not self assignment
	{
    this->rowNumber = matrix.rowNumber;
    this->columnNumber = matrix.columnNumber;
    this->data = new int * [this->rowNumber];

    for (int i = 0; i<this->rowNumber; i++)
    {
        this->data[i] = new int[this->columnNumber];

        for(int j = 0; j <matrix.columnNumber; j++)
        {
            this->data[i][j] = matrix.data[i][j];
        }
    }
	}
	return (*this);
}

bool Matrix::operator==(const Matrix & matrix)
{
   if(this->rowNumber != matrix.rowNumber || this->columnNumber != matrix.columnNumber)
   {
       return false;
   }

   else
   {
       for(int i=0; i<this->rowNumber; i++)
       {
           for(int j=0; j<this->columnNumber; j++)
           {
               if(this->data[i][j] != matrix.data[i][j])
               {
                   return false;
               }
           }
       }
       return true;
   }
}

Matrix Matrix::operator!()
{						  
	Matrix transpose(this->columnNumber,this->rowNumber,0); //change the row and column of the original matrix

      for(int j=0; j<rowNumber; j++)
      {
        for(int k=0; k<columnNumber; k++)
        {
            transpose.data[k][j] = this->data[j][k];
        }
      }
    return transpose;
}