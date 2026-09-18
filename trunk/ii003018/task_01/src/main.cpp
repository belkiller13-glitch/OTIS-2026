#include <iostream>

class Model{
    public:
        virtual ~Model() = default;
        virtual double nextStep(double u) = 0;
        virtual void reset() = 0;

    };
// Модель 1.8 - линейная
// y(t+1) = a1*y(t) + a2*y(t-1) + b1*u(t) + b2*u(t-1)

class GeneralizedAutoregressiveLinearModel : public Model{
    private:
        double a1, a2, b1, b2;
        double y = 0;          // y(t)
        double y_previous = 0;   // y(t - 1)
        double u_previous = 0; // u(t - 1)
    public:
        GeneralizedAutoregressiveLinearModel(double a1, double a2, double b1, double b2)
        : a1(a1), a2(a2), b1(b1),b2(b2)
        {
        }

        double nextStep(double u) override{
            double y_next = (a1 * y) + (a2 * y_previous) + (b1 * u) + (b2 * u_previous);
            y_previous = y;
            y = y_next;
            u_previous = u;
            return y_next;
        }

        void reset() override{
            y = y_previous = u_previous = 0;
        };
};

// Модель 2.2 - нелинейная 
// y(t+1) = a*y(t) + b*sat(u(t))

class  ActuatorSaturationNonLinearityModel : public Model{
    private:
        double a, b;
        double uMin, uMax;
        double sat(double u){
            if (u > uMax) return uMax;
            else if (u < uMin) return uMin;
            else return u;
        }
        double y = 0;
    public:
    ActuatorSaturationNonLinearityModel(double a, double b, double uMin, double uMax)
    : a(a), b(b), uMin(uMin), uMax(uMax)
    {
    }
    double nextStep(double u) override{
        y = a * y + b * sat(u);
        return y;
    }
    void reset() override{
        y = 0;
    }
};

// Модель 3.6 - ДУ 
// dy / dt = a*y^3 + b*u
// y(t+1) = y(t) + h * (a*y(t)^3 + b*u(t))

class CubicGrowthAndControlModel : public Model{
    private:
        double a, b;
        double h;
        double y = 0;

    public:
    CubicGrowthAndControlModel(double a, double b, double h)
    : a(a), b(b), h(h)
    {
    }

    double nextStep(double u) override{
        double f = a * y * y * y + b * u;
        y = y + h * f;
        return y;
    }

    void reset() override{
        y = 0;
    }
};

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
    std::cout << "Input u (const): ";
    double u;
    std::cin >> u;
    std::cout << std::endl;
    for(int t = 0; t < n; t++){
        double y = model -> nextStep(u);
        std::cout << "t = " << t << " u = " << u << " y = " << y << std::endl;
    }
    delete model ;
    return 0;
}