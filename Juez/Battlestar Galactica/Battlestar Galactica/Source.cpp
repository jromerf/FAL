
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//lleva el elemento f a la posicion i y desplaza todos a la derecha
//void intercambio(std::vector<int> &fila, int c, int f) {
//    int aux = fila[f];
//    for (int i = f; i > c ; i--) {
//        fila[i] = fila[i - 1];
//    }
//    fila[c] = aux;
//}

void mezcla(std::vector<int>& v, int a, int m, int b) {

    std::vector<int> auxiliar(b - a + 1);
    // k es el indice del vector original
    //i es el indice de la primera mitad
    //j es el indice de la segunda mitad 
    int i, j, k; 
    for (int i = a; i <= b; i++) 
        auxiliar[i-a] = v[i];

    i = 0, j = m - a + 1 , k = a; //es m-a+1 porque la posicion es relativa a "a", porque "a" puede ser un valor de la mitad en adelante tambien
    while ((j <= b - a) && (i <= m - a)) {
        if (auxiliar[i] <= auxiliar[j]) {
            v[k] = auxiliar[i];
            i++;
        }
        else {
            v[k] = auxiliar[j];
            j++;
        }
        k++;
    }

    //esto es cuando queda un trozo entre medias porque j = b pero i <= m 
    while (i <= m-a) {
        v[k] = auxiliar[i];
        k++;
        i++;
    }

    //esto es cuando queda un trozo al final porque i = j pero j <= b 
    while (j <= b-a) {
        v[k] = auxiliar[j];
        k++;
        j++;
    }
    
}


int resolver(std::vector<int> &fila,int c, int f) {
    int r = 0;
    if (f <= c) {
        r = 0;
    }
    else if (c == f - 1) {
        if (fila[c] > fila[f]) {
            int aux = fila[f];
            fila[f] = fila[c];
            fila[c] = aux;
            r = 1;
        }
        else
            r = 0;
    }
    else {
        int m = (c + f) / 2;
        int r1, r2, j, acu = 0,ini=c,fin = f;

        r1 = resolver(fila, c, m);
        r2 = resolver(fila, m + 1, f);

        j = m + 1;

        while (ini <= j && j <= fin) {
            if (fila[ini] > fila[j]) {
                acu += j - ini;
                //intercambio(fila, ini, j);
                j++;
            }
            else
                ini++;
        }
        mezcla(fila, c, m, f);
        r = r1 + r2 + acu;
    }
    return r;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, i = 0; 
    std::cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> fila(n);

    while (i < n) {
        std::cin >> fila[i];
        i++;
    }

    int sol = resolver(fila, 0, fila.size() - 1);

    // escribir sol
    std::cout << sol << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C18.1.in");
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
