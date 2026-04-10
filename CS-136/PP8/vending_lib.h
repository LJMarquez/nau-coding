#ifndef VENDING_LIB_H
#define VENDING_LIB_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PRODUCTS 3
#define MAX_INPUT_LENGTH 10
#define MAX_PRODUCT_LABEL_LENGTH 64
#define CREDIT_FEE 0.02
#define CONTACTLESS_FEE 0.01

typedef enum ProductType {
	CHOCOLATE_BAR,
	CHIPS,
	CHEWING_GUM,
	PEPSI,
	NUM_PRODUCTS
} ProductType;

typedef enum Menu {
	CANCEL = -1,
	CONTINUE,
	CHECKOUT,
	INVALID_OPTION
} Menu;

typedef enum Payment {
	CASH,
	CREDIT,
	CONTACTLESS
} Payment;

typedef enum CreditCard {
	MASTERCARD,
	VISA,
	DISCOVER,
	AMERICAN_EXPRESS
} CreditCard;

typedef enum Contactless {
	GOOGLE_WALLET,
	APPLE_PAY
} Contactless;

typedef struct Product {
	ProductType productType;
	double price;
	int quantityInStock;
} Product;

typedef struct CartItem {
	Product item;
	int quantity;
} CartItem;

typedef struct ShoppingCart {
	CartItem shoppingCart[MAX_NUM_PRODUCTS];
	int totalItems;
	double totalCost;
} ShoppingCart;

extern const char* productLabels[NUM_PRODUCTS];

void stockMachine(Product products[NUM_PRODUCTS]);
void displayProducts(const Product products[NUM_PRODUCTS]);
ProductType getProduct(void);
int getQuantity(ProductType productType, const Product products[NUM_PRODUCTS]);
CartItem selectItem(Product item, Product products[NUM_PRODUCTS], int quantity);
bool addToCart(CartItem item, ShoppingCart* cart);
void cancelPurchase(ShoppingCart* cart, Product products[NUM_PRODUCTS]);
void generateBill(const ShoppingCart* cart);
bool pay(const ShoppingCart* cart);

#endif
