#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* Builder предпочтительнее конструктора, так как:
    1. Исключает "телескопические конструкторы с длинным списком параметров.
    2. Повышает читаемость кода через именованные методы.
    3. Позволяет гибко изменять состав объекта на этапе сборки.
*/
class Burger
{
private:
    //2
    string bun;
    int countBun = 0;
    string patty;
    int countPatty= 0;
    string cheese;
    int countCheese = 0;
    string veggies;
    int countVeggies = 0;
    string sauce;
    int countSauce = 0;
    string drink;
    int countDrink = 0;
public:
    void setBun(const string& bun)
    {
        countBun++;
        this->bun = bun;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }
    void setPatty(const string& patty)
    {
        countPatty++;
        this->patty = patty;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }
    void setCheese(const string& cheese)
    {
        countCheese++;
        this->cheese = cheese;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }
    void setVeggies(const string& veggies)
    {
        countVeggies++;
        this->veggies = veggies;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }
    void setSauce(const string& sauce)
    {
        countSauce++;
        this->sauce = sauce;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }
    //2
    void setDirnk(const string& drink)
    {
        countDrink++;
        this->drink = drink;
        //TODO: Надо будет делать проверку, что булка одна и та же
        //Ну или переписать(Короче учебная программа не для работы)
    }

    void showOrder() const {
        cout << "Состав бургера: " << endl;
        cout << "\t - Булочка: " << "х" << countBun << " " << bun << endl;
        cout << "\t - Котлета: " << "х" << countPatty << " " << patty << endl;
        cout << "\t - Сыр: " << "х" << countCheese << " " << cheese << endl;
        cout << "\t - Овощи: " << "х" << countVeggies << " " << veggies << endl;
        cout << "\t - Соус: " << "х" << countSauce << " " << sauce << endl;
        cout << "\t - Напиток: " << "x" << countDrink << " " << drink << endl;
    }
};

class BurgerBuilder {
protected:
    Burger* burger = nullptr;
public:
    virtual ~BurgerBuilder() {}
    void createBurger() { if (burger == nullptr) burger = new Burger(); }
    Burger* getBurger() { return burger; }
    virtual void buildBun() = 0;
    virtual void buildPatty() = 0;
    virtual void buildCheese() = 0;
    virtual void buildVeggies() = 0;
    virtual void buildSauce() = 0;
    virtual void buildDrink() = 0;
};

class ClassicBurger : public BurgerBuilder {
public:
    void buildBun() override { burger->setBun("Классическая с кунжутом"); }
    void buildPatty() override { burger->setPatty("Говяжья котлета"); };
    void buildCheese() override { burger->setCheese("Чедер"); }
    void buildVeggies() override { burger->setVeggies("Салат, помидор, огурец"); }
    void buildSauce() override { burger->setSauce("Кетчуп и майонез"); }
    void buildDrink() override { burger->setDirnk("Кола"); }
};
class VeganBurger : public BurgerBuilder {
public:
    void buildBun() override { burger->setBun("Цельнозерновая"); }
    void buildPatty() override { burger->setPatty("Котлета из сои"); };
    void buildCheese() override { burger->setCheese("Веганский сыр"); }
    void buildVeggies() override { burger->setVeggies("Авокада, шпинат, грибы"); }
    void buildSauce() override { burger->setSauce("Веганский Майонез и горчица"); }
    void buildDrink() override { burger->setDirnk("Зелёный чай"); }
};

//1
class SpicyBurgerBuilder : public BurgerBuilder
{
public:
    void buildBun() override { burger->setBun("Острая булка с перцем"); }
    void buildPatty() override { burger->setPatty("Куриная котлета с чили"); };
    void buildCheese() override { burger->setCheese("Пеппер джек"); }
    void buildVeggies() override { burger->setVeggies("Халапеньо, лук, салат"); }
    void buildSauce() override { burger->setSauce("Острый соус"); }
    void buildDrink() override { burger->setDirnk("Острый лимонад"); }
};
class Cashier {
private:
    BurgerBuilder* builder;
public:
    void setBurger(BurgerBuilder* builder) { this->builder = builder; }
    Burger* asemble()
    {
        builder->createBurger();
        builder->buildBun();
        builder->buildPatty();
        builder->buildCheese();
        builder->buildVeggies();
        builder->buildSauce();
        builder->buildDrink();
        return builder->getBurger();
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    Cashier cashier;
    ClassicBurger classicburger;
    cashier.setBurger(&classicburger);
    Burger* classicBuider = cashier.asemble();
    classicBuider->showOrder();

    VeganBurger veganburger;
    cashier.setBurger(&veganburger);
    Burger* veganBuider = cashier.asemble();
    veganBuider->showOrder();
    //2
    SpicyBurgerBuilder spicyburgerbuilder;
    cashier.setBurger(&spicyburgerbuilder);
    Burger* spicyBuider = cashier.asemble();
    spicyBuider->showOrder();

    delete classicBuider, veganBuider, spicyBuider;
}




