#include <iostream>
#include <string>
#include <vector>
#include <limits> // included for error handling

using namespace std;

void ChangeCustomerChoice(vector<int>& clientChoices);
int CheckUserPermissionAccess();
void DisplayInfo(vector<int>& clientChoices);


int main() {
	
	// previously uninitialized ints initialized to 0
	int i = 0;
	int j = 0;
	int choice = 0;
	int permission = 0;
	
	// initialize vector for the client choices - moved from global to main
	vector<int> clientChoices{1, 2, 1, 1, 2};
	
	cout << "(Created by Ryan J. Miller)" << endl;
	
	cout << "Hello! Welcome to our Investment Company" << endl;
	
	// swapped while loop to for loop to limit login attempts
	for (j = 0; j < 3; ++j) {
		
		// run user through log in process
		permission = CheckUserPermissionAccess();
		
		if (permission == 1) { // if authorized, allow access
			break;
			
		} else { // if unauthorized, reprompt user for credentials or close program
			
			cout << "Invalid Password. Please try again" << endl;
		}
	}
	
	// end program if login attempts exceeded
	if (j == 3) {
		
		cout << endl << "Allotted login attempts exceeded." << endl;
		return 0;
	}
	
	// menu loop
	while (i != 1) {
		
		// menu options
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "Exit the program.. (enter 3)" << endl;
		
		// added to validate input
		if (!(cin >> choice) || (choice < 1 || choice > 3)) {
			
			// error handling
			cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Error, invalid selection, please select a number from the menu." << endl;	
		}
		
		else {
			
			if (choice == 1) {
				DisplayInfo(clientChoices);
			
			} else if (choice == 2) {
				ChangeCustomerChoice(clientChoices);
			
			} else if (choice == 3) {
				i = 1;
			}
		}
					
	}
	
	return 0;
}

void ChangeCustomerChoice(vector<int>& clientChoices) {
	
	int clientNumber, choice;
	
	// Prompt user for client number and validate input - added input validation
    cout << "Enter the number of the client that you wish to change" << endl;
    
    while (!(cin >> clientNumber) || (clientNumber < 1 || clientNumber > 5)) {
    	
    	// error handling
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a valid client number: ";
	}
	
	// Prompt user for new service choice and validate input  - added input validation
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
    
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
    	
    	// error handling
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter 1 for Brokerage or 2 for Retirement: ";
    }
	
	// updates client choice based on user input - changed to single statement for efficiency
	clientChoices[clientNumber - 1] = choice;
	
	return;
}


// TODO: aquire valid username, implement encryption or replace with external method
int CheckUserPermissionAccess() {
	
	// initialize correct password as constant to avoid hardcoding in conditional statement
	const string CORRECT_PASSWORD = "123";
	
	string username;
	string password;
	
	cout << "Enter your username: " << endl;
	cin >> username;
	
	cout << "Enter your password: " << endl;
	cin >> password;
	
	// testing revealed that only the value of the password is checked
	if (password == CORRECT_PASSWORD) {
		return 1; // returns if password is correct
		
	} else {
		return 2; // returns if password is incorrect
	}
}

void DisplayInfo(vector<int>& clientChoices) {
	
	// prints info for each client with current service choice values
    cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    cout << "1. Bob Jones selected option " << clientChoices[0] << endl;
    cout << "2. Sarah Davis selected option " << clientChoices[1] << endl;
    cout << "3. Amy Friendly selected option " << clientChoices[2] << endl;
    cout << "4. Johnny Smith selected option " << clientChoices[3] << endl;
    cout << "5. Carol Spears selected option " << clientChoices[4] << endl;
    
    return;
}      