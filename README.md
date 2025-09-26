# Simulación de Carrera de Fórmula 1 🏎️
**Autor:** Darío A. Uribe  

El proyecto consiste en la simulación de un Gran Premio de Fórmula 1 (F1), utilizando la parrilla de la temporada 2025 (sin la participación de Checo Pérez 😢).
Durante la simulación, cada piloto compite con su respectivo monoplaza, cuyos atributos de rendimiento y fiabilidad permiten diferenciar a cada escudería y piloto, añadiendo realismo.

Al finalizar la carrera, los resultados se ordenan automáticamente en función del desempeño simulado, mostrando la clasificación final de manera similar a un GP real. 


## Compilación y ejecución

Para compilar el proyecto necesitas tener instalado **g++** (parte de [MinGW](http://mingw.org/) en Windows o [GCC](https://gcc.gnu.org/) en Linux/macOS).

### Windows
g++ -Iincludes sources/*.cpp -o carrera.exe
.\carrera.exe

### Linux
g++ -Iincludes sources/*.cpp -o carrera
./carrera

### MacOS
g++ -Iincludes sources/*.cpp -o carrera
./carrera


### Primer avance

Se modelan **monoplazas** y **pilotos**, y se aplica un algoritmo de ordenamiento (**MergeSort**) para determinar la clasificación final de la carrera en función del **tiempo de carrera** de cada auto.


## Estructura del proyecto

- **`piloto.h`**  
  Contiene la clase `Piloto`, con atributos que representan las características de un conductor (nombre, número, nivel de habilidad, probabilidad de error, etc.).  
  Incluye getters para acceder a estos valores.

- **`monoplaza.h`**  
  Define la clase base `Monoplaza`, que representa a un auto de F1.  
  Contiene atributos como escudería, piloto asignado, velocidad, fiabilidad y tiempo de carrera.  
  A partir de esta clase se heredan las clases hijas para cada escudería de la parrilla actual.  
  Incluye métodos virtuales como `correr()` para simular el desempeño del auto.

- **`monoplaza.cpp`**  
  Implementa la lógica del cálculo del **tiempo de carrera** a partir de una fórmula basada en atributos del piloto y del monoplaza.  
  El tiempo base de referencia proviene del registro real de Max Verstappen en un Gran Premio.

- **`main.cpp`**  
  Contiene la simulación completa:
  1. Se crean los pilotos.  
  2. Se construyen los monoplazas y se asignan los pilotos a cada escudería.  
  3. Se simula la carrera con el método `correr()`.  
  4. Se aplica **MergeSort** para ordenar los tiempos.  
  5. Se muestran los resultados finales en consola.  

---

## Algoritmo de Ordenamiento: MergeSort

Para organizar la parrilla en función del tiempo de carrera, se implementa el algoritmo **MergeSort**, uno de los más eficientes y ampliamente utilizados en informática.  

### ¿Cómo funciona?
1. **Divide y vencerás**  
   El arreglo de monoplazas se divide recursivamente en mitades hasta obtener subarreglos de un solo elemento.  

2. **Combinación ordenada (Merge)**  
   La función `merge()` compara dos subarreglos ya ordenados y los une en uno solo, eligiendo siempre el monoplaza con menor tiempo de carrera.  

3. **Resultado final**  
   Una vez que todas las divisiones se combinan, el vector queda completamente ordenado, mostrando la clasificación de la carrera desde el primer lugar hasta el último.  

### Complejidad del algoritmo
- **Tiempo:**  
  - Mejor caso: O(n log n)  
  - Peor caso: O(n log n)  
  - Caso promedio: O(n log n)  
  (n = número de monoplazas en la parrilla).  

- **Espacio:**  
  O(n), ya que se crean arreglos temporales (`L` y `R`) para realizar el proceso de merge.  

### Ventajas
- Estable: mantiene el orden relativo de elementos iguales.  
- Eficiente incluso en el peor caso.  

### ¿Qué sigue?  
Me gustaría hacer la simulación más realista incorporando nuevas características, como la inclusión de un Safety Car, la posibilidad de mostrar las posiciones vuelta por vuelta en lugar de solo al final, y mejorar el formato de salida para que los resultados sean más claros y atractivos visualmente.
