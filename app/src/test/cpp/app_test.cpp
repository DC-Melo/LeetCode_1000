/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include "app.h"
#include <cassert>

int main() {
    gradle::Greeter greeter;
    assert(greeter.greeting().compare("Hello, World!") == 0);
    return 0;
}
