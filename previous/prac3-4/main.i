# 1 "main.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 382 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "main.cpp" 2
# 1 "./CoffeeMachine.h" 1



class CoffeeMachine {
 int coffee, water, sugar;
public:
 CoffeeMachine(int c, int w, int s);
 void drinkEspresso();
 void drinkAmericano();
 void drinkSugarCoffee();
 void fill();
 void show();
};
# 2 "main.cpp" 2

int main() {
 CoffeeMachine java(5, 10, 3);
 java.drinkEspresso();
 java.show();
 java.drinkAmericano();
 java.show();
 java.drinkSugarCoffee();
 java.show();
 java.fill();
 java.show();
}
