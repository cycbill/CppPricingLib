#include <iostream>
#include <vector>
#include <string>

#include "MarketData/interest_curve.h"
#include "Models/equity/blackscholes.h"
#include <boost/math/distributions.hpp>

using namespace std;

int main()
{
    vector<string> msg {"Congrets", "on", "building", "C++ code", "using CMake!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "BlackScholes Price: " << BlackScholes() << endl;

    InterestCurve ircurve;
    cout << "Curve interpolate: " << ircurve.GetInterpolate(1.0) << endl;
}