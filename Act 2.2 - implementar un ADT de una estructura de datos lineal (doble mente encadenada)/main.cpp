/*
 * main.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "dlist.h"

using namespace std;

int main(int argc, char* argv[]) {
    DList<int> b1;
    string front, back;

    b1.insertion(2);
    front = "[2]";
    back = "[2]";
    cout << "\n"
         << "1.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "1.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.insertion(3);
    b1.insertion(6);
    b1.insertion(10);
    front = "[2, 3, 6, 10]";
    back = "[10, 6, 3, 2]";
    cout << "\n"
         << "2.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "2.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    cout << "\n"
         << "3.- esperada " << 3 << "\n programa " << b1.search(10) << "\n";
    cout << (3 == b1.search(10) ? "success\n" : "fail\n");

    cout << "\n"
         << "4.- esperada " << -1 << "\n programa " << b1.search(1) << "\n";
    cout << (-1 == b1.search(1) ? "success\n" : "fail\n");

    b1.update(1, 13);
    front = "[2, 13, 6, 10]";
    back = "[10, 6, 13, 2]";

    cout << "\n"
         << "5.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "5.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.update(3, 32);
    front = "[2, 13, 6, 32]";
    back = "[32, 6, 13, 2]";

    cout << "\n"
         << "6.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "6.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.deleteAt(0);
    front = "[13, 6, 32]";
    back = "[32, 6, 13]";

    cout << "\n"
         << "7.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "7.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.deleteAt(1);
    front = "[13, 32]";
    back = "[32, 13]";

    cout << "\n"
         << "8.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
    cout << (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << "\n"
         << "8.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
    cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");
}
