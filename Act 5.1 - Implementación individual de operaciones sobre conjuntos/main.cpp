/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Agosto 2021
*  programa: act 5.1 Implementacion Heap
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*/

#include <iostream>
#include "quadratic.h"
#include "chain.h"

using namespace std;

unsigned int myHash(const string s) {
    unsigned int acum = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        acum += (int) s[i];
    }
    return acum;
}

int main(int argc, char *argv[]) {

    Quadratic<string, int> quad_hash(10, string("empty"), myHash);

    int ans;
    string q_ans;

    quad_hash.put(string("tecnica"), 11);
    quad_hash.put(string("casa"), 12);
    quad_hash.put(string("caza"), 13);
    quad_hash.put(string("amos"), 15);
    quad_hash.put(string("magneto"), 17);
    quad_hash.put(string("operador"), 18);
    quad_hash.put(string("taza"), 18);

    q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (7 tecnica : 11) (8 casa : 12) ";

<<<<<<< HEAD
    cout << "\n" << "1.- esperada " << q_ans << "\n programa " << quad_hash.toString().c_str() << "\n";
    cout << ((!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");

    quad_hash.put(string("max"), 99);
    quad_hash.put(string("cocacola"), 188);
=======
			cout << " 1 " <<	( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");
			cout << endl <<  q_ans << endl ;
			cout << quad_hash.toString().c_str() << endl ;

			quad_hash.put(string("max"), 99);
>>>>>>> a4cb0ff55cf0c5cea8bc362373569286cccb970d

    q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (6 max : 99) (7 tecnica : 11) (8 casa : 12) ";

<<<<<<< HEAD
    cout << "\n" << "2.- esperada " << q_ans << "\n programa " << quad_hash.toString().c_str() << "\n";
    cout << ((!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");
=======
			cout << " 2 " <<	( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");

			cout << endl <<  q_ans << endl ;
			cout << quad_hash.toString().c_str() << endl ;
>>>>>>> a4cb0ff55cf0c5cea8bc362373569286cccb970d

    ans = 12;

<<<<<<< HEAD
    cout << "\n" << "3.- esperada " << ans << " programa " << quad_hash.get("casa") << "\n";
    cout << (ans == quad_hash.get("casa") ? "success\n" : "fail\n");
=======
			cout << " 3 " <<	( ans == quad_hash.get("casa") ? "success\n" : "fail\n");

			cout << endl <<  ans << endl ;
			cout << quad_hash.get("casa") << endl ;
>>>>>>> a4cb0ff55cf0c5cea8bc362373569286cccb970d

    quad_hash.put(string("concha"), 16);

    ans = 17;

<<<<<<< HEAD
    cout << "\n" << "4.- esperada " << ans << " programa " << quad_hash.get("magneto") << "\n";
    cout << " 4 " << (ans == quad_hash.get("magneto") ? "success\n" : "fail\n");

    return 0;
=======
			cout << " 4 " <<	( ans == quad_hash.get("magneto") ? "success\n" : "fail\n");

			cout << endl <<  ans << endl ;
			cout << quad_hash.get("magneto") << endl ;

			return 0;
>>>>>>> a4cb0ff55cf0c5cea8bc362373569286cccb970d
}
