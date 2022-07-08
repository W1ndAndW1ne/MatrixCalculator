#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix
{
    int m;
    int n;
    int **a;
};



void CreateMatrix (Matrix &Mt)
{
    Mt.a = new int*[Mt.m];
    for (int i = 0; i < Mt.m; i++)
    {
        Mt.a[i] = new int[Mt.n];
    }
}

istream& operator >> (istream& is, Matrix &Mt)
{
    cout << "Number of line: ";
    is >> Mt.m;
    cout << "Number of collum: ";
    is >> Mt.n;
    CreateMatrix(Mt);
    cout << "Enter elements of Matrix: ";
    for (int i = 0; i < Mt.m; i++)
    {
        for (int j = 0; j < Mt.n; j++)
        {
            is >> Mt.a[i][j];
        }
    }
    return is;
}

ostream& operator << (ostream& os, Matrix Mt)
{
	if (Mt.m == 0 || Mt.n == 0)
	{
		throw "ERROR! There is no data.";
	}
    for (int i = 0; i < Mt.m; i++)
    {
        for (int j = 0; j < Mt.n; j++)
        {
            os << setw(5) << Mt.a[i][j] << " ";
        }
        os << endl;
    }
    return os;
}


Matrix operator + (Matrix t, Matrix b)
{
    if (t.m != b.m || t.n != b.n)
    {
        throw "Math ERROR!";
    }
    else
    {
        Matrix c;
        c.m = t.m;
        c.n = t.n;
        CreateMatrix(c);
        for (int i = 0; i < t.m; i++)
    {
            for (int j = 0; j < t.n; j++)
        {
        	c.a[i][j] = 0;
            c.a[i][j] = t.a[i][j] + b.a[i][j];
        }
    }
    return c;
    }
}

Matrix operator * (Matrix &t, Matrix &b)
{
    if (t.n != b.m)
    {
        throw "Math ERROR!";
    }
    else 
    {
        Matrix c;
        c.m = t.m;
        c.n = b.n;
        CreateMatrix(c);
        for (int i = 0; i < c.m; i++)
        {
            for (int j = 0; j < c.n; j++)
            {
                c.a[i][j] = 0;
                for (int k = 0; k < t.n; k++)
                {
                    c.a[i][j] += t.a[i][k] * b.a[k][j];
                }
            }
        }
        return c;
    }
}

int main()
{
	int choice;
	Matrix A;
	Matrix B;
	do
	{
		cout << "1: Dim             2: Data" << endl;
		cout << "3: MatA + MatB     4: MatA x MatB" << endl << "0: End" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0:
				break;
			case 1:
				cout << "1. MatA      2. MatB\n";
				int n;
				cin >> n;
				if (n == 1)
				{
					cin >> A;
					cout << A;
				}
				else
				{
					cin >> B;
					cout << B;
				}
				break;
			case 2:
				cout << "1. MatA      2. MatB\n";
				int k;
				cin >> k;
				if (k == 1)
			    {
					try
					{
						cout << A;
					} catch (const char* msg)
					{
						cerr << msg << endl;
					}
				}
				else
				{
					try
					{
						cout << B;
					} catch (const char* msg)
					{
						cerr << msg << endl;
					}
				}
				break;
			case 3:
				try
				{
					cout << A + B;
				} 
				catch (const char* msg)
				{
					cerr << msg << endl;
				}
				break;
			case 4:
				try
				{
					cout << A*B;
				}
				catch (const char* msg)
				{
					cerr << msg << endl;
				}
				break;
			default:
				cout << "Syntax ERROR!\n";
				choice = 9;
				break;				
		}
		if (choice != 9 && choice != 0)
		{
			cout << "Do you want to continue? [Y/N]\n";
			char a;
			cin >> a;
			if (a == 'N' || a == 'n') choice = 0;
		}
	}
	while (choice != 0);
    return 0;
}

