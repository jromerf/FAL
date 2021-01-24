
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

/* P { num >= 0 }
*  Q { r = (inver(num) donde 
*      inver(num) = ( forall i: 0 <= i < num.length : r[i] = num[num.length - i - 1] ) } estaría bien?¿
*/
int resolver(int num,int &multiplicador) {
    int r;
    if (num / 10 == 0) {
        r = num;
        multiplicador = 1;
    }
    else {
        r = resolver(num / 10, multiplicador);
        multiplicador *= 10;
        r = (num % 10 * multiplicador) + r;
    }
    return r;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num,multiplicador;
    std::cin >> num;
    if (num == 0)
        return false;

    int sol = resolver(num,multiplicador);

    // escribir sol
    std::cout << sol << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C10.1.in");
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
