#include <iostream>

using namespace std;

class Complex{
public:
    Complex(){}
    Complex(float real, float image){
       this->real=real;
       this->image=image;

        //TO DO
    }
    const Complex operator+(const Complex& k){
        float realsum = this->real + k.getReal();
        float imagesum = this->image + k.getImage();
        Complex ret(realsum,imagesum);

        return ret;

        // TO DO
    }
    const Complex operator-(const Complex& k){
        float realdiff = this->real - k.getReal();
        float imagediff = this->image - k.getImage();
        Complex ret(realdiff,imagediff);

        return ret;
        // TO DO
    }
    float getReal() const{
        return real;
        // TO DO
    }
    float getImage() const{
        return image;
        // TO DO
    }
private:
    float real,image;
};

ostream& operator<<(ostream& out,const Complex& k){
    float real, image;
    real = k.getReal();
    image = k.getImage();
    if(image >= 0)out<<real<<" + "<<image<<"i";
      else out<<real<<" - "<<-image<<"i";
    return out;
}

int main(){
    float real1, image1;
    float real2, image2;
    while(cin >> real1 >> image1 >> real2 >> image2){
        Complex myComplex1(real1, image1);
        Complex myComplex2(real2, image2);
        cout<< myComplex1 + myComplex2 << endl;
        cout<< myComplex1 - myComplex2 << endl;
    }
    return 0;
}