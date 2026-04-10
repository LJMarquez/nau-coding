#include "vending_lib.h"

static bool parseIntInputMain(const char* input, int* outValue) {
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

int main(void) {
	Product products[NUM_PRODUCTS];
	ShoppingCart cart = {0};
	bool keepRunning = true;
	bool paymentSuccess = false;

	stockMachine(products);

	printf("Welcome to the Vending Machine\n");
	printf("------------------------------\n\n");

	while(keepRunning) {
		char input[MAX_INPUT_LENGTH];
		ProductType selectedProduct;
		int selectedQuantity;
		CartItem selectedItem;
		int menuOption = CANCEL;
		bool processMenu = true;

		displayProducts(products);
		selectedProduct = getProduct();
		if(selectedProduct == (ProductType)CANCEL) {
			keepRunning = false;
			processMenu = false;
		}

		if(processMenu) {
			selectedQuantity = getQuantity(selectedProduct, products);
			if(selectedQuantity == CANCEL) {
				cancelPurchase(&cart, products);
				keepRunning = false;
				processMenu = false;
			}
		}

		if(processMenu) {
			selectedItem = selectItem(products[selectedProduct], products, selectedQuantity);
			if(!addToCart(selectedItem, &cart)) {
				products[selectedProduct].quantityInStock += selectedQuantity;
			}
		}

		if(processMenu && cart.totalItems >= MAX_NUM_PRODUCTS) {
			bool hasValidOption = false;
			while(!hasValidOption) {
				printf("\nCart is full, type 1 to Checkout or -1 to Cancel: ");
				if(fgets(input, sizeof(input), stdin) == NULL) {
					printf("Invalid option. Please try again!\n");
				} else if(!parseIntInputMain(input, &menuOption)) {
					printf("Invalid option. Please try again!\n");
				} else if(menuOption == CHECKOUT || menuOption == CANCEL) {
					hasValidOption = true;
				} else {
					printf("Invalid option. Please try again!\n");
				}
			}
		} else if(processMenu) {
			bool hasValidOption = false;
			while(!hasValidOption) {
				printf("\nType 0 to Continue shopping, 1 to Checkout or -1 to Cancel: ");
				if(fgets(input, sizeof(input), stdin) == NULL) {
					printf("Invalid option. Please try again!\n");
				} else if(!parseIntInputMain(input, &menuOption)) {
					printf("Invalid option. Please try again!\n");
				} else if(menuOption == CONTINUE || menuOption == CHECKOUT || menuOption == CANCEL) {
					hasValidOption = true;
				} else {
					printf("Invalid option. Please try again!\n");
				}
			}
		}

		if(processMenu && menuOption == CONTINUE) {
			printf("\n");
		}

		if(processMenu && menuOption == CANCEL) {
			cancelPurchase(&cart, products);
			keepRunning = false;
			processMenu = false;
		}

		if(processMenu && menuOption == CHECKOUT) {
			generateBill(&cart);
			printf("\nPlease review your order. Proceed with payment?\n");
			printf("Type 0 to confirm or any other key to cancel the order: ");

			if(fgets(input, sizeof(input), stdin) == NULL || input[0] != '0') {
				cancelPurchase(&cart, products);
				keepRunning = false;
			} else if(pay(&cart)) {
				paymentSuccess = true;
				keepRunning = false;
			} else {
				printf("Payment failed.\n");
				cancelPurchase(&cart, products);
				keepRunning = false;
			}
		}
	}

	printf("Thank you for shopping with us!\n");
	if(paymentSuccess) {
		printf("You are authorized to retrieve your products.\n");
	}

	return 0;
}
