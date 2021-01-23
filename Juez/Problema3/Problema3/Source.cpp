
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#define INF 999999

// recorremos hasta p buscando el maximo valor entre ellos y lo comparamos con el minimo valor de los de la derecha de p, 
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(std::vector<int> a, int p,int n) {
    
    int i = 0, max_u = 0,min_w = INF;
    while (i < n) {

        if (i <= p) {
            if (a[i] > max_u)
                max_u = a[i];
        }
        else {
            if (a[i] < min_w)
                min_w = a[i];
        }
        i++;
    }
    return max_u < min_w; 
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int N,p,val;
    std::cin >> N >> p;
    // leer los datos de la entrada

    std::vector<int> a; 

    while (N > 0) {
        std::cin >> val;
        a.push_back(val);
        N--;
    }

    bool sol = resolver(a,p,a.size());

    // escribir solución
    if (sol == true)
        std::cout << "SI\n";
    else 
        std::cout << "NO\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C02.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
