/*
 * main.cpp
 *
 *  Created on: 30/10/2020
 *      Author: clase
 */

#include <iostream>
#include "splay.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in_ans = "", pre_ans = "";
    SplayTree<int> my_splay;
    bool found = 0;

    my_splay.add(15);
    in_ans = "[15]";

    cout << "\n" << "1.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");

    my_splay.add(10);
    my_splay.add(17);
    my_splay.add(7);
    my_splay.add(13);
    my_splay.add(16);
    in_ans = "[7 10 13 15 16 17]";
    pre_ans = "[16 13 7 10 15 17]";

    cout << "\n" << "2.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
    cout << "\n" << "2.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
    cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");

    found = my_splay.find(15);
    in_ans = "[7 10 13 15 16 17]";
    pre_ans = "[15 13 7 10 16 17]";

    cout << "\n" << "3.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
    cout << "\n" << "3.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
    cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
    cout << "\n" << "3.- esperada " << 1 << " programa " << found << "\n";
    cout << (found == 1 ? "success\n" : "fail\n");

    found = my_splay.find(17);
    in_ans = "[7 10 13 15 16 17]";
    pre_ans = "[17 16 15 13 7 10]";
    cout << "\n" << "4.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
    cout << "\n" << "4.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
    cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
    cout << "\n" << "4.- esperada " << 1 << " programa " << found << "\n";
    cout << (found == 1 ? "success\n" : "fail\n");

    my_splay.remove(13);  //bottum up
    in_ans = "[7 10 15 16 17]";
    pre_ans = "[15 7 10 16 17]";
    cout << "\n" << "5.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
    cout << "\n" << "5.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
    cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");

    my_splay.remove(16);  //bottum up
    in_ans = "[7 10 15 17]";
    pre_ans = "[15 7 10 17]";
    cout << "\n" << "6.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
    cout << (!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
    cout << "\n" << "6.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
    cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
}
