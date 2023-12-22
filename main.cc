#include "app.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Takes 2 inputs: filename for boolean expression, filename for values" << endl;
        exit(1);
    }
    string filenameExp{argv[1]};
    string filenameMap{argv[2]};
    App app{filenameExp, filenameMap};
    app.begin();
}
