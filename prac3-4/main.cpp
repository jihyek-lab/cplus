#include "CoffeeMachine.h"

int main() {
	CoffeeMachine java(5, 10, 3); // 커피량:5, 물량:10, 설탕:6으로 초기화
	java.drinkEspresso(); // 커피 1, 물 1 소비	
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkAmericano(); // 커피 1, 물 2 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.fill(); // 커피 10, 물 10, 설탕 10으로 채우기
	java.show(); // 현재 커피 머신의 상태 출력
}