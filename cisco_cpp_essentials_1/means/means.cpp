/* Evaluating different kinds of means
This program evaluates 4 types of mean(arithmetic, harmonic, geometric and rootmeansquare) from values inside the given vector.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean;
	double HarmonicMean;
	double GeometricMean;
	double RootMeanSquare;

    double sum = 0, sumreverse = 0, prod = 1, sumsq = 0;
	// Insert your code here
	for (int i = 0; i < n; i++) {
        sum += vector[i];
	    sumreverse += 1./vector[i];
	    prod *= vector[i];
	    sumsq += (vector[i] * vector[i]);
    }
	
    ArithmeticMean = sum/n;
    HarmonicMean = n/sumreverse;
    GeometricMean = pow(prod, 1./n);
    RootMeanSquare = sqrt(sumsq/n);
    
	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean   = " << HarmonicMean   << endl;
	cout << "Geometric Mean  = " << GeometricMean  << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;

	cout << endl;
	return 0;
}