#include <iostream>
#include "xlsxwriter.h"
using namespace std;


//////////////////////////////////////////////
/*
double interpolation(double x0, double x1, double x2, double x3, double x_number)
{
    double l_itoe;
    double l_temp[2];
    double x_massiv[3] = [x0, x1,x2,x3];


    l_itoe = ( (x_number*x1)*(x_number*x2 )*(x_number*x3 ) ) / ( ()*()*() )
     ���� ��� �� �������� ��� �� ��
    for  (int i=1; i < 3; i++)
    {
        l_temp[i]= (x_number - x_massiv[i-1] )/();
    } ������� ���� ������, �� �������
    */
//////////////////////////////////////////////

double interpolation(double X[3], double Y[3], double x_inter)
{
    double sum,prod;
    sum=0;
    for (int j=0; j<3; j++){
        prod=1;
        for (int i=0; i<3; i++)
            {
                if (i!=j){
                    prod=prod*(x_inter-X[i])/(X[j]-X[i]);
                }
            }
        sum=sum+Y[j]*prod;
    }
    return sum;
}

/*
����� ����� ������� y = 4x^2+7x-5

*/

int main()
{
//��� ���������� � ����� ������ 3����������� � �������

double x_graf = 0; //x ������� ������� � ������
double y_graf; //y ������� ������� � ������

//���� ����� �� x1 - x4 � y1 - y4
double x1, x2, x3, x4,   y1, y2, y3, y4;
cout << " VVedite x1, x2, x3, x4, y1, y2, y3, y4  "<<endl;
cin>> x1, x2, x3, x4,   y1, y2, y3, y4;

//��������� 3������� � ������� ��� ����� ������� ������
double x_arr[4]{x1,x2,x3,x4} ;
double y_arr[4]{y1,y2,y3,y4};

//��� �����3����� 3����� � ������

    /* ������ ���� � �������� � ��� */
    lxw_workbook  *workbook  = workbook_new("test.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    /* �������� �� ������� ������ � ������� ������� */
    int row = 1;
    int col = 0;

for (col=0; col<500; col++) {
    x_graf= x_graf+0.001;
    y_graf = interpolation(x_arr,y_arr,x_graf);

    /* 3��������� �������� � ������ */
    worksheet_write_number(worksheet, row, col + 1, x_graf, NULL);
    worksheet_write_number(worksheet, row+1, col + 1, y_graf, NULL);

}
    /* 3�������� � ��x������ ���� */
    return workbook_close(workbook);

}
