/*Classes and objects: ShopItemOrder
Let's say we're building an e-commerce site and you are 
tasked with implementing a single-item order in a shopping cart.

 * Your class should be named ShopItemOrder.
 * The item order shall store the following information:
    * item name;
    * item unit price;
    * number of items ordered.
 * There will be access methods allowing to:
    * get and set all of the above information;
    * get the total price for the order;
    * print the order in a user-friendly way.
You can take any approach to calculating the total price.
*/
#include <iostream>
#include <string>

using namespace std;
class ShopItemOrder {
    public:
        ShopItemOrder(string name, double unit_price, int number = 1):
        name(name), unit_price(unit_price), number_items(number) {}
        string get_name() { return name; }
        double get_unit_price() { return unit_price; }
        int get_number_items() { return number_items; }
        double get_total_price() {return number_items * unit_price; }

        void set_name(string new_name) {name = new_name;};
        void set_unit_price(double new_price) {
            if(new_price > 0) {unit_price = new_price;}
        }
        void set_number_items(int new_number_items) {
            if(new_number_items > 0) {number_items = new_number_items;}
        }

    private:
        string name;
        double unit_price;
        int number_items;
};
int main() {
    ShopItemOrder orderTShirts("T-shirt mens black size M", 23.4, 3);
    ShopItemOrder orderJeans("Jeans mens blue size M", 42.2, 2);

    std::cout << orderTShirts.get_number_items() << " x \""
            << orderTShirts.get_name() << "\" = "
            << orderTShirts.get_total_price() << std::endl;

    std::cout << orderJeans.get_number_items() << " x \""
            << orderJeans.get_name() << "\" = "
            << orderJeans.get_total_price() << std::endl;
}