#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

int generateX(int, int);
double generateY(double, double, double);

int main()
{
    int xcount=25, xbegin=1, xend=100, bias=-1, i, slope=3;
    
    srand(time(NULL));
    
    int x[xcount], y[xcount];
    
    for(i=0; i<xcount; i++) {
             x[i] = generateX(xbegin, xend);
    }
    
    for(i=0; i<xcount; i++) {
             y[i] = (int)generateY((double)x[i], (double)bias, (double)slope);
    }
    
    for(i=0; i<xcount; i++) {
             cout << x[i] << " " << y[i] << endl;
    }
    
    ofstream out;
    out.open("linear.csv");
    out << "feature1,feature2\n";
    for(i=0; i<xcount; i++) {
             out << x[i] << ',' << y[i] << '\n';
    }
    out.close();
    
    system("PAUSE");
    return 0;
}

int generateX(int begin, int end) {
    return begin + ( rand() % ( end - begin + 1 ) );
}

double generateY(double x, double bias, double slope) {
    double f = (double)rand() / RAND_MAX;
    f = f * slope;
    return bias + ( (slope/2) + f )*x;
}
