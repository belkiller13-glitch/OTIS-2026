#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "Model.h"   
#include "Model 1.8.h"
#include "Model 2.2.h"
#include "Model 3.6.h"

double inputSignal(int t, int type, double ampl){
    switch (type){
    case 1: return ampl;
    case 2: return (t == 0) ? ampl : 0;
    case 3: return ampl * std::sin(t);
    }
    return 0;
}

int main(){
    std::cout << "Choose model:" << std::endl;
    std::cout << " 1 - Model 1.8 (Generalized Autoregressive Linear Model)" << std::endl;
    std::cout << " 2 - Model 2.2 (Actuator Saturation Non-linearity)" << std::endl;
    std::cout << " 3 - Model 3.6 (Cubic Growth and Control)" << std::endl;
    std::cout << " Your choice: ";
    int user_choice;
    std::cin >> user_choice;
    std::cout << "Input number of steps (n): ";
    int n;
    std::cin >> n;

    Model* model = nullptr;
    switch(user_choice){
        case 1:{
            std::cout << "Model 1.8: y(t+1) = a1*y(t) + a2*y(t-1) + b1*u(t) + b2*u(t-1)" << std::endl;
            double a1, a2, b1, b2;
            std::cout << "a1 = "; std::cin >> a1;
            std::cout << "a2 = "; std::cin >> a2;
            std::cout << "b1 = "; std::cin >> b1;
            std::cout << "b2 = "; std::cin >> b2;  
            model = new GeneralizedAutoregressiveLinearModel(a1, a2, b1, b2);
            break;
        }
        case 2:{
            std::cout << "Model 2.2: y(t+1) = a*y(t) + b*sat(u(t))" << std::endl;
            double a, b, uMin, uMax;
            std::cout << "a = "; std::cin >> a;
            std::cout << "b = "; std::cin >> b;
            std::cout << "uMin = "; std::cin >> uMin;
            std::cout << "uMax = "; std::cin >> uMax;
            model = new ActuatorSaturationNonLinearityModel(a, b, uMin, uMax);
            break;
        }
        case 3:{
            std::cout << "Model 3.6: dy/dt = a*y^3 + b*u (y = y + h*(a*y^3 + b*u))" << std::endl;
            double a, b, h;
            std::cout << "a = "; std::cin >> a;
            std::cout << "b = "; std::cin >> b;
            std::cout << "h (time step) = "; std::cin >> h;
            model = new CubicGrowthAndControlModel(a, b, h);
            break;
        }
        default:{
        std::cout << "Wrong choice!";
        return 1;
        }   
    }
    std::cout << "Choose input signal u(t):" << std::endl;
    std::cout << " 1 - step     (u = const)" << std::endl;
    std::cout << " 2 - impulse  (u(0) = A, u(t > 0) = 0)" << std::endl;
    std::cout << " 3 - harmonic (u = A * sin(t))" << std::endl;
    int signal_type;
    std::cin >> signal_type;
    if(signal_type < 1 || signal_type > 3){
        std::cout << "Wrong choiсe!";
        delete model;
        return 1;
    }

    std::cout << "Input amplitude A: ";
    double amplitude;
    std::cin >> amplitude;
    std::cout << std::endl;
    std::cout << std::setw(5)  << "t"
              << std::setw(15) << "u(t)"
              << std::setw(15) << "y(t)" << std::endl;
    std::cout << std::string(35, '-') << std::endl;

    std::ofstream file("result.csv");
    file << "t;u;y" << std::endl;
    file << std::fixed << std::setprecision(4);

    for(int t = 0; t < n; t++){
        double u = inputSignal(t, signal_type, amplitude);
        double y = model -> nextStep(u);
        std::cout << std::setw(5)  << t
                  << std::setw(15) << std::fixed << std::setprecision(4) << u
                  << std::setw(15) << y << std::endl;
        file << t << ";" << u << ";" << y << std::endl;
    }
    file.close();
    std::cout << std::endl << "Data saved to result.csv" << std::endl;
    delete model ;
    return 0;
} 