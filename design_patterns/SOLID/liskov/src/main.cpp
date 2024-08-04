#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Rectangle
{
    protected:
        int width, height;
    public:
        Rectangle(int width, int height) : width(width), height(height) {}
        int getWidth() const 
        {
            return width;
        }

        virtual void setWidth(int width)  
        {
            Rectangle::width = width;
        }
        
        int getHeight() const 
        {
            return height;
        }

        virtual void setHeight(int heigth)
        {
            Rectangle::height = height;
        }

        int area() const {return width * height;}

};

class Square : public Rectangle
{
private:
    /* data */
public:
    Square(int size) : Rectangle(size, size) {};
    ~Square();

    void setWidth(int width)  override
    {
        this->width = this->height = width;
    }

    void setHeight(int height)  override
    {
        this->width = this->height = height;
    }
};

void process(Rectangle& r)
{
    int w = r.getWidth();
    cout << w << endl;
    r.setHeight(10);

    cout << r.getHeight() << endl;
    cout << "Expected area is = " << (w*10)
    << ", got " << r.area() << endl;
}

class RectangleFactory
{
    static Rectangle create_rectangle(int w, int h);
    static Rectangle create_square(int size);
};


int main(int, char**)
{
    cout << "Liskov susbstitution Principle" << endl;

    Rectangle r{3,4};
    process(r);
}