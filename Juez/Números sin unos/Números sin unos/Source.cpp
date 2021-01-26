
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

bool recursiva2(long long int n) {

    while ((n != 0) && (n % 10 != 1)) {
        n /= 10;
    }
    if (n % 10 == 1)return true;
    else return false;
}


int despejaUnos(int num) {
    int aux = num,hasta = 1;
    while (aux != 0 && aux != 1) {
        if (aux % 10 == 1) {
            hasta *= 10;
        }
        aux = aux / 10;
    }
    num = num - hasta;
    return num;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(int num) {
    long long int r = 0, parte = num / 10;
    int ultimo = num % 10;

    if (num == 0)
        r = 1;

    for(int i = 0;i<=ultimo;i++){
        if (!recursiva2(10 * parte - 1))
            r++;
    }

    if (parte) {
        r = r + resolver(parte - 1) * 9;
    }

    return r;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num; 
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    
    int sol = resolver(num);

    // escribir sol
    std::cout << sol << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C16.1.in");
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
