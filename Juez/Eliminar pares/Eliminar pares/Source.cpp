
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*
void resolver(std::vector<int>& elems) {
    
    int i = 0, j = 0;

    //while (j < elems.size() && i < elems.size() ) {
    //    if (elems[i] % 2 != 0) {
    //        if (elems[j] % 2 == 0 && i < j) {
    //            elems[i] = elems[j];
    //            elems[j] = -1;
    //        }
    //        j++;
    //    }
    //    else
    //        i++;
    //}

    while (j < elems.size() && i < elems.size()) {
        if (elems[i] % 2 == 0)
            i++;
        else {
            if (i < j && elems[j] % 2 == 0) {
                elems[i] = elems[j];
                elems[j] = -1;
            }
            j++;
        }
    }

    elems.resize(i+1);
    /*if (j > i && elems[i] % 2 == 0)
        elems.resize(j - i);
    else
        elems.resize(i);
}*/


/* P { 0 <= n <= elems.size() }
*  Q { (forall i: 0 <= i <= n < elems.size() : v[i] % 2 == 0) and 
       (forall j: n < j < elems.size() : v[j] % 2 != 0) } //esto al hacer el resize a lo mejor no debería estar¿?
*/ 
void resolver(std::vector<int> &elems) {
    int p = 0, q = elems.size() - 1;

    while (p <= q) {
        if (elems[p] % 2 != 0 && elems[q] % 2 == 0) {
            elems[p] = elems[q];
            elems[q] = -1;
            p++;
            q--;
        }
        else {
            if (elems[p] % 2 == 0)
                p++;
            if (elems[q] % 2 != 0)
                q--;
        }
    }
    elems.resize(p);//Preguntar si este resize es válido
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N , i = 0;
    std::cin >> N;
    if (N == -1)
        return false;

    std::vector<int> elems(N);
    while (i < N) {
        std::cin >> elems[i];
        i++;
    }

    resolver(elems);
    std::sort(elems.begin(), elems.end());
    // escribir sol
    i = 0;
    while (i < elems.size()) {
        std::cout << elems[i] <<" ";
        i++;
    }
    std::cout << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C07.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
