
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> &fila , int c ,int f) {
    int r = 0;
    if (f <= c) {
        r = 0;
    }else if (c == f - 1 ) {
        if (fila[c] > fila[f]) {
            int aux = fila[c];
            fila[c] = fila[f];
            fila[f] = aux;
            r = 1;
        }
        else
            r = 0;
    }
    else {
        int m = (c + f) / 2;
        int acu = 0, i = f -1,j = f, aux=0;
        r += resolver(fila, c, m);
        r += resolver(fila, m + 1, f);

        /*Después de devolverme organizados donde cada par de elementos están ordenados decrecientemente, lo que intento es realizar
        el cambio entre cada par el elementos que falta hasta tener todo el subvector ordenado (simulando los intercambios de la especificacion
        del problema*/
        while (i >= 0 || j >= 1) {
            if (fila[i] > fila[j]) {
                acu++;
                aux = fila[i];
                fila[i] = fila[j];
                fila[j] = aux;
                if (j < f) {
                    /*Esta condicion la uso porque si bien siempre que haya un par este va a ser menor que el siguiente,puede que el elemento
                    * siga siendo menor que el que le sigue p.e, con i = 1 y j = 2: {1 7} {4 6} => {1 4 7 6} pero 6 sigue siendo menor que 7
                    * entonces comparo eso tambien
                    */
                    if (fila[j] > fila[j + 1]) {
                        i = j;
                        j = j + 1;
                    }
                }
            }
            else {
                i--;
                j--;
            }
        }
        r += acu;
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
