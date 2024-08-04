#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

enum class Color : char {red, green, blue, yellow, black};
enum class Size : char {small, medium, large};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product*> by_color(vector<Product*> items, Color color)
    {
        vector<Product*> result;
        for (auto& i : items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }

    vector<Product*> by_size(vector<Product*> items, Size size)
    {
        vector<Product*> result;
        for (auto& i : items)
            if(i->size == size)
                result.push_back(i);
        return result;
    }

    vector<Product*> by_size_and_color(vector<Product*> items, Size size, Color color)
    {
        vector<Product*> result;
        for (auto& i : items)
            if(i->size == size and i->color == color)
                result.push_back(i);
        return result;
    }
};

template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
    virtual vector<T*> filter(vector<T*> items,
                                Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product*> items, 
                                Specification<Product> &spec) override 
    {
        vector<Product*> result;
        for (auto & item : items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    ColorSpecification(Color color) : color(color) {}
    bool is_satisfied(Product *item) override 
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size size) : size(size) {}
    bool is_satisfied(Product *item) override 
    {
        return item->size == size;
    }
};

template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}

    bool is_satisfied(T *item) override 
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


int main(int, char**)
{
    cout << "Open Closed Principle" << endl;

    Product apple{"Apple", Color::green, Size::medium};
    Product tree{"Tree", Color::blue, Size::large};
    Product house{"House", Color::blue, Size::large};
    Product car{"Car", Color::black, Size::large};
    Product table{"Table", Color::red, Size::medium};
    Product phonne{"Phonne", Color::yellow, Size::small};

    vector<Product*> items {&apple, &tree, &house, &car, &table, &phonne};

    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);
    for(auto& item : green_things)
        cout << item->name << " is green" << endl;
    
    BetterFilter bf;
    ColorSpecification blue (Color::blue);
    for(auto& item : bf.filter(items, blue))
        cout << item->name << " is blue" << endl;
    
    SizeSpecification large(Size::large);
    for(auto& item : bf.filter(items, large))
        cout << item->name << " is large" << endl;


    AndSpecification<Product> blue_and_large(blue, large);
    for(auto& item : bf.filter(items, blue_and_large))
        cout << item->name << " is blue and large" << endl;

    return 0;
}
