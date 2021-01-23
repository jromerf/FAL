
// Nombre y Apellidos

// Recorremos de iz a derecha y en el momento que no se cumpla que sea más pequeño que el siguiente entonces no son Dalton, 
// si llega hasta el final significa que si lo son

#include <iostream>
#include <fstream>
#include <vector>

// P { 0 <= n < vinieta.length() } 
// I { 1 <= i <= n and v[i-1] < v[i] }
// Q { x = (pt i: 1 <= i < vinieta.length : v[i-1] < v[i]  }
// Coste O(n) donde n = vinieta.length() 
bool resolver(std::vector<int> &vinieta,int n) {
    int i = 1; 

    while (i < n && vinieta[i - 1] < vinieta[i]) {
        i++;
    }
    return i == n;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, i = 0;
    std::cin >> N;
    std::vector<int> vinieta(N);

    if (N <= 0)
        return false;

    while (i < N)
    {
        std::cin >> vinieta[i];
        i++;
    }

    bool sol = resolver(vinieta,N);

    // escribir sol
    if (sol == true) std::cout << "DALTON\n";
    else std::cout << "DESCONOCIDOS\n";

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C03.1.in");
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
