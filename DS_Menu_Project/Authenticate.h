/* =========================================================================================*
 * The Authenticate class handles the authentication of administrative users.
 * It stores the administrator password and provides methods to verify user input against the stored password.
  =========================================================================================*/

#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H
#include <string>

using namespace std;

class Authenticate {
private:
    string adminPassword; // Stores the administrative password.
public:
    /**
     * Default constructor that initializes the admin password to a default value.
     * Pre-condition: None.
     * Post-condition: The adminPassword is set to "admin1234".
     */    
    Authenticate() : adminPassword("admin1234") {} // Default constructor
    /**
     * Parameterized constructor that sets the admin password to a specified value.
     * Pre-condition: None.
     * Post-condition: The adminPassword is set to the provided password.
     */    
    Authenticate(const string& password) : adminPassword(password) {}
    /**
     * Attempts to log in as an administrator by verifying the provided password.
     * Pre-condition: The adminPassword has been initialized.
     * Post-condition: Returns true if the input password matches the stored adminPassword, otherwise false.
     */    
    bool adminLogin(const string& password);
    /**
     * Verifies if the provided input matches the stored admin password.
     * Pre-condition: The adminPassword has been initialized.
     * Post-condition: Returns true if the input matches the stored adminPassword, otherwise false.
     */    
    bool verifyPassword(const string& input) const {
        return input == adminPassword;
    }
};
#endif /* AUTHENTICATE_H */
