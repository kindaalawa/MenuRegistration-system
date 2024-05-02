#include "authenticate.h"

/* Method to verify admin login
 Precondition: The Authenticate object is initialized and the admin password is set.
 Postcondition: Returns true if the provided password matches the admin password, otherwise returns false.*/
bool Authenticate::adminLogin(const string& password) {
    return verifyPassword(password);
}
