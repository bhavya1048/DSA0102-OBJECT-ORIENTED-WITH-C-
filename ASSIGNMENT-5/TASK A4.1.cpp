#include <iostream>
#include <stdexcept>
using namespace std;

class BillingError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class ClaimError : public BillingError {
public:
    using BillingError::BillingError;
};

class PackageError : public BillingError {
public:
    using BillingError::BillingError;
};

class InvalidChargeError : public BillingError {
public:
    using BillingError::BillingError;
};

class PatientNotFoundError : public BillingError {
public:
    using BillingError::BillingError;
};

int main() {
    try {
        throw ClaimError("Claim rejected");
    }
    catch (const ClaimError& e) {
        cout << "Claim Error: " << e.what() << endl;
    }

    try {
        throw InvalidChargeError("Invalid charge");
    }
    catch (const BillingError& e) {
        cout << "Billing Error: " << e.what() << endl;
    }

    return 0;
}