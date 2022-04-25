#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;

public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    void printVolume()
    {
        cout << volume << endl;
    }
};
class Cuboid : public Shape
{
    private:
        float len,wid,hei;
        
    public:
        Cuboid(float a,float b,float c){
            len=a;
            wid=b;
            hei=c;
        }   
    virtual void computeVolume() override{
        volume=len*wid*hei;
    }
    // Add code here
};
class Pyramid : public Shape
{
    private:
        float btm,hei;
        
    public:
        Pyramid(float a,float b){
            btm=a;
            hei=b;
        }   
     virtual void computeVolume() override{
        volume=(btm*hei)/3;
     }
    // Add code here
};
class Sphere : public Shape
{
    private:
        float rad;
        
    public:
        Sphere(float a){
            rad=a;
        }   
     virtual void computeVolume() override{
        volume=4*rad*rad*rad*PI/3;
     }
    // Add code here
};

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}
