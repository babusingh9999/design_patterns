#include <iostream>
#include<memory>
class Shape{
    public:
        virtual ~Shape() = default;
        virtual std::unique_ptr<Shape> clone() const= 0;
        virtual void draw() const=0;
};

class Circle : public Shape{
    int radius;
        public:
            Circle(int r) : radius(r) {}

            std::unique_ptr<Shape> clone() const{
                return std::make_unique<Circle>(*this);
            }
            void draw() const{
                std::cout<<"drawing circle with radious : "<<radius<<std::endl; 
            }

};

class Triangle : public Shape{
    int width,height;
        public:
            Triangle(int w,int h) : width(w),height(h) {}

            std::unique_ptr<Shape> clone() const{
                return std::make_unique<Triangle>(*this);
            }
            void draw() const{
                std::cout<<"drawing Triangle with width and height : "<<width<<" "<<height<<std::endl; 
            }

};

int main(){
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(5);
    std::unique_ptr<Shape> triangle = std::make_unique<Triangle>(2,7);

    // cloned objects
    std::unique_ptr<Shape> clonedCircle = circle->clone();
    std::unique_ptr<Shape> clonedTriangle = triangle->clone();

    circle->draw();
    clonedCircle->draw();

    triangle->draw();
    clonedTriangle->draw();



    return 0;
}