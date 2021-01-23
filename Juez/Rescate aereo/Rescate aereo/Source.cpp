
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

struct rangoEdificios {
    int p;
    int q;
};

// P { 0 < n <= edificios.length() } 
// Q { max p,q : 0 <= p < q <= edificios.length() : ( p.t. i : p <= i < q : edificios[i] > t ) : q - p  }
// Coste O(n) donde n = edificios.length() 
rangoEdificios resolver(std::vector<int> edificios,int t) {
    
    rangoEdificios sol = { 0,0 };
    int cnt = 0, i = 0, mejorsol = 0; 

    while (i < edificios.size()) {
        if (edificios[i] > t) {
            cnt++;
            if (mejorsol < cnt){
                sol.p = i - cnt + 1;
                sol.q = i;
                mejorsol = cnt;
            }
        }
        else {
            cnt = 0;
        }
        i++;
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int n, t,i = 0;
    std::cin >> n >> t;
    std::vector<int> edificios(n);

    while (i < n) {
        std::cin >> edificios[i];
        i++;
    }

    rangoEdificios sol = resolver(edificios,t);

    // escribir solución
    std::cout << sol.p << " " << sol.q << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C04.1.in");
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
