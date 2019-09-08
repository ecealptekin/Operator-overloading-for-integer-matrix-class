#ifndef ecealptekin_Alptekin_Ece_HW5_header_h
#define ecealptekin_Alptekin_Ece_HW5_header_h

#include<iostream>
#include<string>

using namespace std;

class Matrix
{

private:

    int rowNumber;
    int columnNumber;
    int ** data;

public:

    Matrix(); //default constructor
    Matrix(int rowNum,int columnNum,int init); //constructor
    Matrix(const Matrix & Matrix); //copy constructor
    ~Matrix(); //destructor

    int getRowNumber() const;
    int getColumnNumber() const;
    void setElementAt(int rowNumber,int columnNumber,int number);
    int getElementAt(int rowNumber,int columnNumber) const;
    void print();

    Matrix operator+(const Matrix & matrix);
    Matrix operator-(const Matrix & matrix);
    const Matrix & operator=(const Matrix & matrix);
    bool operator==(const Matrix & matrix);
    Matrix operator!();

};

#endif