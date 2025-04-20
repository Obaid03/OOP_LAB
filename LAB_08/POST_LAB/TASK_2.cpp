/*Task Requirements:
1. Create a base class Product with attributes like productID, price, and a virtual function
calculatePrice().
2. Implement two derived classes:
    o Electronics (Applies 15% tax)
    o Clothing (Applies 5% tax)
3. Overload the applyDiscount method to handle different discount types:
    o Percentage discount (e.g., 10% off)
    o Fixed discount (e.g., $20 off)
    o Buy One Get One Free
4. Override the calculatePrice method to apply category-specific tax rates.
5. Implement operator overloading for the ShoppingCart class:
    o + to merge two shopping carts
    o - to remove an item from the cart
    o * to apply bulk discounts
    o / to split cart total among multiple users
6. Create objects for Electronics and Clothing categories, demonstrate method overloading,
overriding, and operator overloading by simulating an online shopping experience.*/
#include<iostream>
using namespace std;
int i=0,j=0;
class ShoppingCart;
class Product{
    protected:
        string productId;
        double Price;
    public:
        Product(string PI="",double p=0):productId(PI),Price(p){}
        virtual void CalculatePrice()=0;
        string getID(){return productId;}
        double getPrice(){return Price;}
        void Discount(){
            cout<<"Applyin Discount of 20%"<<endl;
            Price-=(Price*(20/100));
        }
        double Discount(double d){
            if(d<=0){
                cout<<"Discount Must be Greater than Zero"<<endl;
                return 0;
            }
            else{
                cout<<"Applyin Discount of  "<<d<<" %"<<endl;
                return Price-=(Price*(d/100));
        }}
        void Discount(string d){
            cout<<"Buy One  "<<productId<<"  Get One Free"<<endl;
        }
        void Display(){
            cout<<"Product -->  "<<productId<<" Price:  "<<Price<<endl;
        }
};
class Electronics:public Product{
    private:
        // const double tax=15;
    public:
        Electronics(string PI="",double p=0):Product(PI,p){}
        void CalculatePrice()override{
            cout<<"APPLYING TAX RATE OF 15\% On   "<<productId<<endl;
            Price+=(Price*(15/100));
        }
};
class Clothing:public Product{
    private:
        // const double tax=5;
    public:
        Clothing(string PI="",double p=0):Product(PI,p){}
        void CalculatePrice()override{
            cout<<"APPLYING TAX RATE OF 5\% On    "<<productId<<endl;
            Price+=(Price*(15/100));
        }
};
class ShoppingCart{
    private:
        Product *products[10];//Making an ARRAY of pointers since Product Array cannot be made due to Abstract Class.
        int productsCount;
        double price;
    public:
        ShoppingCart(int pc=0,double p=0){
            for(i=0;i,10;i++){
                products[i]=nullptr;
            }
        }
        void DisplayCart(){
            for(i=0;i<productsCount;i++){
                cout<<"Products in the Cart are: "<<endl;
                cout<<products[i]->getID()<<endl;
            }
        }
        void addproduct(Product *product){
            if(productsCount>=10){
                cout <<"CART ALREADY FULL, Check out first"<<endl;
            }
            else{
                products[productsCount]=product;
                price+=products[productsCount]->getPrice();
                productsCount++;
            }
        }
        ShoppingCart operator+(ShoppingCart &S){
            
            ShoppingCart newCart;
            for(i=0;i<productsCount;i++){
                newCart.products[i]=products[i];
                j++;
                newCart.productsCount++;
            }
            for(i=0;i<S.productsCount;i++){
                newCart.products[j]=S.products[i];
                j++;
                newCart.productsCount++;
            }
            return newCart;
        }
        void operator-(string &S){
            for(i=0;i<productsCount;i++){
                if(products[i]->getID()==S){
                    delete products[i];
                    cout<<"Product with ID: "<<S<<" Removed!"<<endl;
                    for(j=i;j<productsCount;j++){
                        if(j==(productsCount-1)){
                            products[j]=products[productsCount-1];
                            break;}
                        else products[j]=products[j+1];
                    }
                }if(j==productsCount){
                    break;
                }
            }
        }
        double operator*(double n){
            double totalPrice;
            for(i=0;i<productsCount;i++){
                totalPrice+=products[i]->Discount(n);
            }
            price=totalPrice;
            return price;
        }
        double operator/(double n){
            return price=price/n;
        }
};
int main(){
    cout<<"================================================================="<<endl;
    cout<<"********************Website Management System********************\n"<<endl;
    Electronics e1("mobile101",1000);
    Electronics e2("Laptop101",1000);
    Electronics e3("car101",1000);
    Clothing c1("polo101",1000);
    Clothing c2("Check101",1000);
    Clothing c3("towel101",1000);
    e1.Display();
    e2.Display();
    e3.Display();
    c1.Display();
    c2.Display();
    c3.Display();

    cout<<"\n================================================================="<<endl;

    //Function Overloading
    e1.Discount();
    e2.Discount(50);
    e3.Discount("discount");
    c1.Discount();
    c2.Discount(50);
    c3.Discount("discount");
    cout<<"\n================================================================="<<endl;
    e1.Display();
    e2.Display();
    e3.Display();
    c1.Display();
    c2.Display();
    c3.Display();

    cout<<"\n================================================================="<<endl;
    e1.CalculatePrice();
    c1.CalculatePrice();
    e1.Display();
    c1.Display();
    cout<<"\n================================================================="<<endl;
    ShoppingCart S1,S2,S3;
    Product *p1=&e1;
    Product *p2=&e2;
    Product *p3=&c1;
    Product *p4=&c2;
    S1.addproduct(p1);
    S1.addproduct(p2);
    S2.addproduct(p3);
    S2.addproduct(p4);
    cout<<"\n================================================================="<<endl;
    S3=S1+S2;
    S3.DisplayCart();
    // S1-"laptop101";
    double amount=S1*50;
    cout<<"The Total Price After 50\% Discount via operator Overloading is   "<<amount<<endl;
    amount=S2/2;
    cout<<"The Total Price After Dividing it into 2 User via operator Overloading is   "<<amount<<endl;

}