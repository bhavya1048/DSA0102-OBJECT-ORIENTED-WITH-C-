#include <iostream>
#include <stdexcept>
using namespace std;

class ClaimError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

double approve(double billed, double cover) {

    // TODO 1
    if (billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover) {

    try {
        return approve(billed, cover);
    }
    catch (const ClaimError& e) {

        // TODO 2
        cout << "audit: " << e.what() << '\n';

        throw;
    }
}

int main() {

    double cases[][2] = {
        {40000, 50000},
        {60000, 50000},
        {-1, 50000}
    };

    for (auto& c : cases) {

        try {
            double paid = settle(c[0], c[1]);
            cout << "approved " << paid << '\n';
        }
        catch (const ClaimError& e) {
            cout << "claim rejected: "
                 << e.what() << '\n';
        }
        catch (const exception& e) {
            cout << "error: " << e.what() << '\n';
        }
    }

    return 0;
}