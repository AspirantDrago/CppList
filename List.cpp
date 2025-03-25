#include "List.h"

List::List() : size(0), capacity(ZAPAS), array(new int[ZAPAS]) {}

List::~List() {
    delete[] array;
}
