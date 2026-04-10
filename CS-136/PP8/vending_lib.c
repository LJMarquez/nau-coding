#include "vending_lib.h"

const char* productLabels[NUM_PRODUCTS] = {
	"Hershey's Milk Chocolate Bar 1.55oz",
	"Lays Classic Chips 13oz",
	"Orbit Chewing Gum 15 sticks",
	"Pepsi Soda 20oz Bottle"
};

static bool parseIntInput(const char* input, int* outValue) {
	char* endPtr = NULL;
	long parsedValue;

	if(input[0] == '\n') {
		return false;
	}

	parsedValue = strtol(input, &endPtr, 10);
	if(endPtr == input) {
		return false;
	}

	while(*endPtr == ' ' || *endPtr == '\t') {
		endPtr++;
	}

	if(*endPtr != '\n' && *endPtr != '\0') {
		return false;
	}

	*outValue = (int)parsedValue;
	return true;
}

void stockMachine(Product products[NUM_PRODUCTS]) {
	int i;
	FILE* file = fopen("products.csv", "r");

	for(i = 0; i < NUM_PRODUCTS; i++) {
		products[i].productType = (ProductType)i;
		products[i].price = 0.0;
		products[i].quantityInStock = 0;
	}

	if(file != NULL) {
		char line[128];

		while(fgets(line, sizeof(line), file) != NULL) {
			int productId;
			double price;
			int stock;

			if(sscanf(line, "%d,%lf,%d", &productId, &price, &stock) == 3) {
				if(productId >= 0 && productId < NUM_PRODUCTS) {
					products[productId].productType = (ProductType)productId;
					products[productId].price = price;
					products[productId].quantityInStock = stock;
				}
			}
		}

		fclose(file);
	} else {
		products[CHOCOLATE_BAR].price = 1.99;
		products[CHOCOLATE_BAR].quantityInStock = 10;
		products[CHIPS].price = 2.99;
		products[CHIPS].quantityInStock = 6;
		products[CHEWING_GUM].price = 1.39;
		products[CHEWING_GUM].quantityInStock = 13;
		products[PEPSI].price = 2.50;
		products[PEPSI].quantityInStock = 10;
	}
}

void displayProducts(const Product products[NUM_PRODUCTS]) {
	int i;

	printf("Code | Product Description                 | Available Quantity | Unit Price\n");
	printf("_____|_____________________________________|____________________|____________\n");

	for(i = 0; i < NUM_PRODUCTS; i++) {
		printf("%-4d | %-35s | %-18d | %-10.2f\n",
			   i,
			   productLabels[products[i].productType],
			   products[i].quantityInStock,
			   products[i].price);
	}
}

ProductType getProduct(void) {
	char input[MAX_INPUT_LENGTH];
	int selectedProduct = 0;
	bool hasSelection = false;
	ProductType result = (ProductType)CANCEL;

	while(!hasSelection) {
		printf("\nInput the code of the product you want to purchase: ");
		if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
			result = (ProductType)CANCEL;
			hasSelection = true;
		} else if(parseIntInput(input, &selectedProduct) &&
				  selectedProduct >= 0 && selectedProduct < NUM_PRODUCTS) {
			result = (ProductType)selectedProduct;
			hasSelection = true;
		} else {
			printf("Invalid Input! Please try again.\n");
		}
	}

	return result;
}

int getQuantity(ProductType productType, const Product products[NUM_PRODUCTS]) {
	char input[MAX_INPUT_LENGTH];
	int quantity = CANCEL;
	bool hasQuantity = false;

	while(!hasQuantity) {
		printf("Input the quantity of the product: ");
		if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
			quantity = CANCEL;
			hasQuantity = true;
		} else if(!parseIntInput(input, &quantity) || quantity <= 0) {
			printf("Input valid quantity\n");
		} else if(quantity > products[productType].quantityInStock) {
			printf("We do not have enough stock. Please input smaller quantity.\n");
		} else {
			hasQuantity = true;
		}
	}

	return quantity;
}

CartItem selectItem(Product item, Product products[NUM_PRODUCTS], int quantity) {
	CartItem cartItem;

	cartItem.item = item;
	cartItem.quantity = quantity;
	products[item.productType].quantityInStock -= quantity;
	cartItem.item.quantityInStock = products[item.productType].quantityInStock;

	return cartItem;
}

bool addToCart(CartItem item, ShoppingCart* cart) {
	if(cart->totalItems >= MAX_NUM_PRODUCTS) {
		return false;
	}

	cart->shoppingCart[cart->totalItems] = item;
	cart->totalItems++;
	cart->totalCost += item.item.price * item.quantity;
	return true;
}

void cancelPurchase(ShoppingCart* cart, Product products[NUM_PRODUCTS]) {
	int i;

	for(i = 0; i < cart->totalItems; i++) {
		ProductType type = cart->shoppingCart[i].item.productType;
		products[type].quantityInStock += cart->shoppingCart[i].quantity;
	}

	cart->totalItems = 0;
	cart->totalCost = 0.0;
}

void generateBill(const ShoppingCart* cart) {
	int i;

	printf(" Product                                 | Unit Price | Product Total\n");
	printf("-----------------------------------------|------------|--------------\n");

	for(i = 0; i < cart->totalItems; i++) {
		const CartItem* current = &cart->shoppingCart[i];
		double lineTotal = current->item.price * current->quantity;

		printf(" %d x %-34s | %2d x %4.2f  | %.2f\n",
			   current->quantity,
			   productLabels[current->item.productType],
			   current->quantity,
			   current->item.price,
			   lineTotal);
	}

	printf("Order Total: %.2f\n", cart->totalCost);
}

bool pay(const ShoppingCart* cart) {
	char input[MAX_INPUT_LENGTH];
	int paymentOption = CASH;
	double serviceFee = 0.0;
	double paidAmount = 0.0;
	double change = 0.0;
	const char* paidBy = NULL;
	bool methodSelected = false;

	while(!methodSelected) {
		printf("Input 0 for Cash, 1 for Credit card, 2 for Contactless: ");
		if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
			return false;
		}

		if(parseIntInput(input, &paymentOption) &&
		   paymentOption >= CASH && paymentOption <= CONTACTLESS) {
			methodSelected = true;
		} else {
			printf("Invalid option. Please try again!\n\n");
		}
	}

	if(paymentOption == CASH) {
		bool paymentCaptured = false;
		while(!paymentCaptured) {
			printf("\nInput the payment amount: ");
			if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
				return false;
			}

			paidAmount = atof(input);
			if(paidAmount + 1e-9 < cart->totalCost) {
				printf("Insufficient amount. Please input enough payment.\n");
			} else {
				change = paidAmount - cart->totalCost;
				paidBy = "Cash";
				paymentCaptured = true;
			}
		}
	} else if(paymentOption == CREDIT) {
		int cardOption = MASTERCARD;
		bool cardSelected = false;

		while(!cardSelected) {
			printf("\nInput 0 for MasterCard, 1 for Visa, 2 for Discover, and 3 for American Express: ");
			if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
				return false;
			}

			if(parseIntInput(input, &cardOption) &&
			   cardOption >= MASTERCARD && cardOption <= AMERICAN_EXPRESS) {
				cardSelected = true;
			} else {
				printf("Invalid option. Please try again!\n");
			}
		}

		serviceFee = cart->totalCost * CREDIT_FEE;
		paidAmount = cart->totalCost + serviceFee;
		change = 0.0;

		if(cardOption == MASTERCARD) {
			paidBy = "Credit Card (MasterCard)";
		} else if(cardOption == VISA) {
			paidBy = "Credit Card (Visa)";
		} else if(cardOption == DISCOVER) {
			paidBy = "Credit Card (Discover)";
		} else {
			paidBy = "Credit Card (American Express)";
		}
	} else {
		int mobileOption = GOOGLE_WALLET;
		bool mobileSelected = false;

		while(!mobileSelected) {
			printf("\nInput 0 for Google Wallet and 1 for Apple Pay: ");
			if(fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n') {
				return false;
			}

			if(parseIntInput(input, &mobileOption) &&
			   mobileOption >= GOOGLE_WALLET && mobileOption <= APPLE_PAY) {
				mobileSelected = true;
			} else {
				printf("Invalid option. Please try again!\n");
			}
		}

		serviceFee = cart->totalCost * CONTACTLESS_FEE;
		paidAmount = cart->totalCost + serviceFee;
		change = 0.0;

		if(mobileOption == GOOGLE_WALLET) {
			paidBy = "Contactless Payment (Google Wallet)";
		} else {
			paidBy = "Contactless Payment (Apple Pay)";
		}
	}

	generateBill(cart);
	printf("___\n");
	printf("Paid by: %s\n", paidBy);
	printf("Service Fee: %.2f\n", serviceFee);
	printf("Paid Amount: %.2f\n", paidAmount);
	printf("Change:%.2f\n\n", change);

	return true;
}
