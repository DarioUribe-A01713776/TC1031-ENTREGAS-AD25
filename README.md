# Simulador de Carreras de Fórmula 1
Autor: Darío A. Uribe

![Logo F1](./files/F1-logo.png)

Este proyecto es un simulador de carreras de Fórmula 1 que permite gestionar y simular competencias completas de una temporada con los pilotos y escuderías de la temporada 2025. El sistema ofrece la posibilidad de cargar datos de pilotos desde archivos externos, simular múltiples carreras en secuencia y visualizar resultados ordenados de manera eficiente con actualizaciones automáticas de clasificación.

Para asegurar que los resultados de la carrera estén siempre ordenados correctamente, el sistema utiliza el algoritmo **Merge Sort**. Este algoritmo avanzado permite ordenar los monoplazas rápidamente según su tiempo de carrera, ofreciendo al usuario una visualización clara y precisa de las posiciones finales con garantía O(n log n) en todos los casos.

Además, el sistema incorpora una **Lista Doblemente Ligada**, una estructura de datos que optimiza las operaciones de gestión y recorrido de los monoplazas durante la simulación. Esto permite agregar, eliminar y recorrer elementos de manera eficiente en ambas direcciones, manteniendo la flexibilidad necesaria para futuras expansiones del proyecto y facilitando la simulación de eventos dinámicos durante las carreras.

Para mantener la clasificación del campeonato ordenada por puntos totales, el sistema utiliza un **MaxHeap (árbol binario heap)**. Esta estructura de datos permite acceso O(1) al líder actual del campeonato y actualización eficiente O(log n) de puntos tras cada carrera, garantizando que la clasificación general se mantenga siempre correcta sin necesidad de reordenamientos completos.

Para conservar los datos entre sesiones y facilitar la configuración, el sistema incluye un mecanismo robusto de **carga de datos desde archivos CSV**. La información de los pilotos, pistas y escuderías se almacena en archivos externos (`pilotos.csv`, `pistas.csv`, `escuderias.csv`), permitiendo mantener los datos organizados y modificarlos fácilmente sin necesidad de recompilar el programa.

Este simulador de Fórmula 1 combina la eficiencia de algoritmos avanzados como **Merge Sort** para ordenamiento de carreras y **MaxHeap** para gestión de campeonato, junto con estructuras dinámicas como la **Lista Doblemente Ligada**, con un sistema interactivo completo que permite simular temporadas enteras, proporcionando una herramienta robusta, realista y fácil de usar para simular la máxima categoría del automovilismo.

## Descripción del avance 1

En este primer avance, implementé lo siguiente:

- **Clases Piloto y Monoplaza**: La clase `Piloto` representa a cada corredor con atributos como nombre, dorsal, habilidad y probabilidad de error. La clase `Monoplaza` es una clase base abstracta que representa los autos de F1, con clases hijas para cada escudería (Red Bull, McLaren, Ferrari, Mercedes, etc.).
- **Simulación de carrera**: Cada monoplaza ejecuta el método `correr()` que calcula el tiempo de carrera basándose en la velocidad del auto, la fiabilidad, la habilidad del piloto y factores aleatorios que simulan errores.
- **Ordenamiento con Merge Sort**: Implementé el algoritmo Merge Sort para ordenar los resultados de la carrera de menor a mayor tiempo.
- **Diferenciación de monoplazas**: Cada escudería tiene características únicas de velocidad y fiabilidad que afectan el resultado final de la simulación.

## Descripción del avance 2

En este segundo avance, implementé lo siguiente:

- **Lista Doblemente Ligada**: Reemplacé el vector original por una estructura de Lista Doblemente Ligada para almacenar los monoplazas. Esta estructura permite recorrer la parrilla en ambas direcciones y facilita futuras operaciones de inserción y eliminación.
- **Carga de datos desde archivo CSV**: Implementé la funcionalidad de cargar los datos de los pilotos desde un archivo externo `pilotos.csv`. Esto permite modificar fácilmente los atributos de los pilotos sin recompilar el código.
- **Programa interactivo**: El sistema ahora permite al usuario:
  - Seleccionar su piloto favorito de una lista numerada
  - Definir el número de vueltas de la carrera (1-71)
  - Ver resultados ordenados automáticamente
- **Validación de entradas**: Implementé validación para asegurar que el usuario ingrese opciones válidas tanto para la selección de piloto como para el número de vueltas.
- **Interfaz mejorada**: Agregué banners y mensajes claros que mejoran la experiencia del usuario durante la simulación.

## Descripción del avance 3

En este tercer avance, implementé la simulación completa de una temporada de Fórmula 1 con las siguientes características:

- **Clase Temporada**: Gestiona el calendario completo de carreras, la parrilla de 20 pilotos distribuidos en 10 escuderías, y coordina la simulación de cada carrera individual con actualización automática de puntos.
- **MaxHeap para clasificación**: Implementé un árbol binario heap que mantiene la clasificación del campeonato ordenada por puntos totales. El heap permite acceso O(1) al líder del campeonato y actualización O(log n) de puntos tras cada carrera.
- **Sistema de eventos en carreras**: Agregué simulación de eventos aleatorios durante las carreras (pit stops, adelantamientos, errores) que afectan los tiempos finales de cada piloto, haciendo la simulación más realista y dinámica.
- **Carga de datos expandida**: El sistema ahora carga múltiples archivos CSV:
  - `data/pilotos.csv`: 20 pilotos F1 2025
  - `data/pistas.csv`: 21 circuitos del calendario con número de vueltas
  - `data/escuderias.csv`: Características de velocidad y fiabilidad de cada equipo
- **Guardado de resultados**: Al finalizar la simulación, el programa guarda la clasificación final en un archivo `resultados_temporada_2025.csv` con la posición, nombre del piloto, dorsal y puntos totales.
- **Sistema de puntuación F1**: Implementé el sistema de puntos real de Fórmula 1 (25, 18, 15, 12, 10, 8, 6, 4, 2, 1 para los primeros 10 clasificados en cada carrera).
- **Menú interactivo mejorado**: El usuario puede:
  - Ver el calendario de carreras
  - Simular la temporada completa con pausas entre carreras
  - Ver la clasificación actual del campeonato
  - Simular carreras individuales
  - Guardar resultados finales en CSV

## Cambios sobre el primer avance

- **Implementación de Lista Doblemente Ligada**: Reemplacé el uso de `vector<Monoplaza*>` por una estructura de Lista Doblemente Ligada. Esta estructura fue incluida para cumplir con los requerimientos del avance 2 y porque ofrece mayor flexibilidad para operaciones de inserción y eliminación en ambos extremos de la lista. Aunque para este proyecto el vector era suficiente, la lista ligada me prepara para futuras expansiones donde pueda necesitar modificar la parrilla dinámicamente durante la carrera.
- **Sistema de carga desde archivos**: Eliminé la inicialización hardcodeada de pilotos y la reemplacé por un sistema de carga desde archivo CSV. Esto mejora significativamente la mantenibilidad del código y permite actualizar datos sin recompilar.
- **Interactividad del usuario**: Transformé el programa de un simulador automático a uno interactivo donde el usuario puede personalizar aspectos de la carrera. Esto hace el proyecto más dinámico y permite al usuario experimentar con diferentes configuraciones.

## Cambios sobre el segundo avance

- **Arquitectura orientada a temporada**: Cambié el enfoque de carreras individuales a una gestión completa de temporada. La clase `Temporada` coordina múltiples carreras y mantiene la clasificación general.
- **Parrilla dinámica con escuderías**: El sistema ahora crea automáticamente 20 monoplazas (2 por escudería) asociando pilotos con equipos específicos, replicando la estructura real de F1.
- **Simulación de eventos realistas**: Las carreras ahora incluyen eventos aleatorios que afectan directamente los tiempos finales, no solo se muestran en pantalla sino que impactan en los resultados.
- **MaxHeap para gestión de puntos**: Reemplacé métodos simples de ordenamiento por un árbol heap que mantiene eficientemente la clasificación actualizada durante toda la temporada.
- **Persistencia de datos**: Los resultados finales se guardan automáticamente en archivo CSV, permitiendo que el usuario exporte y analice los datos después de la simulación.

## Instrucciones para compilar el avance de proyecto

### Para Windows (PowerShell):
```bash
g++ -o carrera sources/main.cpp sources/monoplaza.cpp sources/piloto.cpp sources/listaDoble.cpp sources/pista.cpp sources/carrera.cpp sources/temporada.cpp sources/maxheap.cpp -I includes
```

### Para Linux/macOS:
```bash
g++ -o carrera sources/main.cpp sources/monoplaza.cpp sources/piloto.cpp sources/listaDoble.cpp sources/pista.cpp sources/carrera.cpp sources/temporada.cpp sources/maxheap.cpp -I includes
```

## Instrucciones para ejecutar el avance de proyecto

### Para Windows (PowerShell):
```bash
.\carrera.exe
```

### Para Linux/macOS:
```bash
./carrera
```

## Descripción de las entradas del avance de proyecto

El programa requiere múltiples archivos de entrada ubicados en la carpeta `data/`:

### data/pilotos.csv
Contiene la lista de 20 pilotos en el siguiente formato:

```csv
nombre,dorsal,habilidad,probError
Max Verstappen,1,95,10
Lando Norris,4,90,7
Gabriel Bortoleto,5,82,15
```

Cada línea contiene los datos de un piloto separados por comas:
- **nombre**: Nombre completo del piloto.
- **dorsal**: Número del piloto (1-99).
- **habilidad**: Nivel de habilidad del piloto (0-100), afecta positivamente el tiempo de carrera.
- **probError**: Probabilidad de cometer un error durante la carrera (0-100), puede añadir penalización de tiempo.

### data/pistas.csv
Contiene el calendario de 21 carreras en el siguiente formato:

```csv
id,nombre,vueltas
1,Bahrain Grand Prix,57
2,Saudi Arabian Grand Prix,50
3,Australian Grand Prix,58
```

Cada línea contiene:
- **id**: Identificador único de la carrera.
- **nombre**: Nombre del Gran Premio.
- **vueltas**: Número de vueltas de la carrera (1-72).

### data/escuderias.csv
Contiene las características de las 10 escuderías:

```csv
id,nombre,velocidad,fiabilidad
1,Red Bull,92,90
2,McLaren,95,92
3,Ferrari,85,85
```

Durante la ejecución, el programa solicita al usuario:
1. **Selección de opción del menú**: Permite ver calendario, simular temporada, ver clasificación, etc.
2. **Confirmación para simular temporada**: Solicita confirmación antes de iniciar una simulación completa.
3. **Selección de carrera individual**: Para simular una carrera específica del calendario.

## Descripción de las salidas del avance de proyecto

El programa proporciona las siguientes salidas:

1. **Banner de bienvenida**: Muestra el título del simulador y confirma la carga exitosa de pilotos, calendario y parrilla desde los archivos CSV.

2. **Menú interactivo**: Presenta opciones para que el usuario controle la simulación:
   - Ver calendario de carreras
   - Simular temporada completa
   - Ver clasificación actual
   - Simular carrera individual
   - Guardar resultados en CSV
   - Salir del programa

3. **Resultados de carreras individuales**: Al finalizar cada carrera, se muestra la clasificación ordenada de menor a mayor tiempo:
   - Posición final (1-20)
   - Escudería
   - Nombre del piloto
   - Tiempo total de carrera en segundos
   - Puntos asignados

Ejemplo de salida:
```
========================================
  RESULTADOS: Bahrain Grand Prix
========================================

1. McLaren - Lando Norris | Tiempo: 5298s
    Puntos: 25
2. Red Bull - Max Verstappen | Tiempo: 5301s
    Puntos: 18
3. Ferrari - Charles Leclerc | Tiempo: 5305s
    Puntos: 15
...
```

4. **Eventos durante la carrera**: Se muestran en tiempo real durante la simulación:
```
  === VUELTA 1/57 ===
    [VUELTA 1] PIT STOP - Lewis Hamilton (Ferrari)
    [VUELTA 1] ADELANTAMIENTO - Lando Norris (McLaren)
    [VUELTA 1] ERROR - Charles Leclerc (Ferrari)
```

5. **Clasificación del campeonato**: Muestra la clasificación final ordenada por puntos:
```
========================================
  CLASIFICACION FINAL - TEMPORADA 2025
========================================

1. Max Verstappen - 450 puntos
2. Lando Norris - 425 puntos
3. Charles Leclerc - 398 puntos
...

CAMPEON DE LA TEMPORADA: Max Verstappen con 450 puntos!
```

6. **Archivo de resultados**: `resultados_temporada_2025.csv` contiene:
```csv
posicion,piloto,dorsal,puntos
1,Max Verstappen,1,450
2,Lando Norris,4,425
3,Charles Leclerc,16,398
```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

**Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.**

En mi proyecto, implementé el algoritmo de ordenamiento **Merge Sort** en las funciones `merge()` y `mergeSort()` para ordenar los resultados de cada carrera. El análisis de complejidad del algoritmo es el siguiente:

- **Complejidad temporal en el peor de los casos**: O(n log n), ya que Merge Sort siempre requiere dividir el conjunto de datos recursivamente (log n niveles) y luego combinar las sublistas en cada nivel (n comparaciones). Esto significa que, sin importar el estado inicial de la lista de monoplazas, el número de operaciones sigue siendo consistente.

- **Complejidad temporal en el caso medio**: O(n log n), el algoritmo mantiene la misma complejidad independientemente de cómo estén ordenados inicialmente los monoplazas. En promedio, realiza aproximadamente n log n comparaciones y movimientos.

- **Complejidad temporal en el mejor de los casos**: O(n log n), dado que el algoritmo sigue dividiendo y combinando incluso cuando la lista está parcialmente o completamente ordenada. A diferencia de algoritmos como QuickSort, Merge Sort no se beneficia de listas pre-ordenadas.

- **Complejidad espacial**: O(n), debido a que se crean arreglos temporales `L` y `R` durante el proceso de merge para almacenar las sublistas.

Comparado con otros algoritmos como Bubble Sort O(n²) o Selection Sort O(n²), Merge Sort es significativamente más eficiente para mi proyecto que maneja 20 monoplazas. Aunque para conjuntos pequeños la diferencia no es notable, elegí Merge Sort por su consistencia garantizada y porque es un algoritmo estable que preserva el orden relativo de elementos con tiempos iguales.

**Análisis de complejidad del MaxHeap**

En mi proyecto utilizo un **MaxHeap** implementado en la clase `MaxHeap` para mantener la clasificación del campeonato ordenada por puntos totales. El análisis de complejidad de las operaciones principales es:

- **Insertar (`insertar`)**: 
  - Peor caso: O(log n), cuando el elemento insertado es mayor que todos los ancestros y debe flotar hasta la raíz.
  - Caso medio: O(log n), en promedio flota algunos niveles pero no siempre hasta la raíz.
  - Mejor caso: O(1), cuando el elemento insertado es menor que su padre y no necesita flotar.

- **Actualizar puntos (`actualizarPuntos`)**: 
  - Peor caso: O(n) para búsqueda + O(log n) para ajuste = O(n), debo recorrer potencialmente toda la estructura.
  - Caso medio: O(n/2) + O(log n) ≈ O(n), en promedio encuentro el piloto en la mitad del heap.
  - Mejor caso: O(1) + O(log n) = O(log n), si el piloto está en la raíz.

- **Obtener campeón (`getCampeon`)**: O(1) en todos los casos, acceso directo a la raíz.

- **Extraer raíz (`extraerRaiz`)**: O(log n) en todos los casos, el proceso de hundir es determinístico.

- **Mostrar clasificación ordenada (`getClasificacionOrdenada`)**: O(n log n) en todos los casos, extraigo n elementos con costo O(log n) cada uno.

- **Complejidad espacial**: O(n), donde n es el número de pilotos (máximo 20).

El MaxHeap es ideal para mantener la clasificación del campeonato porque:
1. Permite acceso O(1) al líder actual sin necesidad de ordenamiento completo
2. Actualización O(log n) es eficiente cuando se añaden puntos tras cada carrera
3. La estructura automáticamente mantiene el invariante "padre ≥ hijo", garantizando que el máximo siempre está en la raíz
4. Para obtener la clasificación ordenada final, extraer n elementos en O(n log n) es más eficiente que reordenar un vector completo
5. En caso medio, las operaciones frecuentes (insertar y actualizar) son cercanas a O(log n), muy eficientes

**Análisis de complejidad de la Lista Doblemente Ligada**

En mi proyecto utilizo una **Lista Doblemente Ligada** implementada en las clases `Nodo` y `ListaDoble`. El análisis de complejidad de las operaciones principales es:

- **Agregar al final (`agregar`)**: O(1) en todos los casos, mantengo un puntero directo a la cola permitiendo inserción inmediata.

- **Agregar al inicio (`agregarInicio`)**: O(1) en todos los casos, mantengo un puntero a la cabeza que permite inserción directa.

- **Recorrido completo (`mostrarTodos`, `toVector`)**: O(n) en todos los casos, debo visitar cada nodo una vez.

- **Búsqueda (`buscar`)**: 
  - Peor caso: O(n), debo recorrer la lista completa si el elemento no existe o está al final.
  - Caso medio: O(n/2), en promedio encuentro el elemento en la mitad de la lista.
  - Mejor caso: O(1), si el elemento está en la cabeza de la lista.

- **Eliminación de nodo específico (`eliminar`)**: 
  - Peor caso: O(n), si debo buscar el nodo primero.
  - Caso medio: O(n/2), si debo buscar en promedio hasta la mitad.
  - Mejor caso: O(1), si ya tengo la referencia al nodo.

- **Conversión a vector (`toVector`)**: O(n) en todos los casos, útil para Merge Sort.

- **Actualización desde vector (`actualizarDesdeVector`)**: O(n) en todos los casos, recorro la lista una vez.

- **Complejidad espacial**: O(n), donde n es el número de monoplazas en la parrilla.

La Lista Doblemente Ligada me ofrece navegación bidireccional (adelante y atrás) con complejidad O(1) entre nodos adyacentes, lo cual es una ventaja sobre listas simples. Para este proyecto, la lista ligada es especialmente útil porque:
1. Permite simular eventos durante la carrera sin necesidad de crear estructuras intermedias
2. La capacidad de recorrer en ambas direcciones facilita futuras expansiones
3. O(1) para agregar/eliminar con referencia es eficiente para la parrilla dinámica
4. Aunque la búsqueda es O(n), las 20 posiciones garantizan búsquedas rápidas en la práctica
5. En caso medio, las operaciones están en O(n/2) ≈ O(n), aceptable para el tamaño del conjunto

### SICT0302: Toma decisiones

**Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.**

Para mi proyecto, seleccioné **Merge Sort** como algoritmo de ordenamiento por las siguientes razones:

1. **Estabilidad**: Merge Sort es un algoritmo estable, lo que significa que preserva el orden relativo de elementos con valores iguales. Esto es importante en mi simulación porque si dos pilotos terminan con el mismo tiempo (aunque poco probable por el factor aleatorio), quiero mantener su orden original.

2. **Complejidad garantizada**: A diferencia de QuickSort que en el peor caso puede degradarse a O(n²), Merge Sort garantiza O(n log n) en todos los casos. Para mi simulación de 20 monoplazas esto asegura un rendimiento consistente.

3. **Simplicidad de implementación**: Aunque requiere espacio adicional O(n), la implementación es directa y fácil de entender, lo cual facilita el mantenimiento del código.

4. **Adecuado para el tamaño del problema**: Con 20 elementos, cualquier algoritmo O(n log n) es suficientemente rápido. 

La implementación en mi código divide recursivamente el vector de monoplazas hasta obtener subarreglos de tamaño 1, luego los combina comparando el atributo `tiempoCarrera` de cada monoplaza, produciendo un resultado ordenado de menor a mayor tiempo.

**Selecciona estructuras de datos adecuadas al problema y las usa correctamente.**

Seleccioné una **Lista Doblemente Ligada** para almacenar los monoplazas durante la simulación de carreras por las siguientes razones:

1. **Flexibilidad para inserciones/eliminaciones**: Aunque en la versión actual no elimino monoplazas durante la carrera, la lista ligada me permite hacerlo en O(1) si tengo la referencia al nodo. Esto prepara el código para futuras expansiones donde pueda simular abandonos o descalificaciones.

2. **Navegación bidireccional**: La lista doble me permite recorrer la parrilla tanto hacia adelante como hacia atrás. Esto es especialmente útil para simular eventos donde necesito acceder a pilotos en diferentes posiciones.

3. **Eficiencia en eventos de carrera**: Al simular los eventos durante cada vuelta, debo recorrer todos los monoplazas múltiples veces. La lista ligada con punteros `siguiente` y `anterior` permite este recorrido sin acceso indexado ineficiente.

4. **Separación de conceptos**: Al usar una lista ligada para la gestión de monoplazas y convertir temporalmente a vector solo para el ordenamiento, separo las responsabilidades de cada estructura. La lista maneja la colección dinámica y el vector facilita el algoritmo de ordenamiento.

Uso correctamente la estructura implementando todos los métodos esenciales: agregar, eliminar, recorrer, buscar y conversión entre formatos. El manejo de memoria es correcto con un destructor que libera todos los nodos al finalizar el programa.

Seleccioné un **MaxHeap** para mantener la clasificación del campeonato por las siguientes razones:

1. **Acceso eficiente al líder**: Durante toda la temporada, necesito saber quién es el líder actual. El heap me proporciona esta información en O(1) accediendo a la raíz.

2. **Actualización de puntos eficiente**: Tras cada carrera, debo sumar puntos a 10 pilotos. La operación `actualizarPuntos()` es O(log n), muy eficiente comparada con reordenar un array completo O(n log n).

3. **Clasificación ordenada final**: Para mostrar la clasificación final, extraer n elementos del heap en O(n log n) es razonable y el resultado sale automáticamente ordenado.

4. **Estructura elegante**: El heap es conceptualmente perfecto para este problema: es un árbol que mantiene automáticamente "el mayor arriba", exactamente lo que necesito para F1.

5. **Mejor que vector ordenado**: Si usara un vector ordenado, cada inserción/actualización sería O(n) para mantener el orden. El heap es más eficiente.

6. **Mejor que lista ordenada**: Una lista ordenada también requeriría O(n) para mantener el orden durante inserciones.

El MaxHeap es especialmente ventajoso en la simulación de temporada porque tras cada carrera necesito:
- Acceso rápido al líder actual: O(1)
- Actualizar 10 pilotos con nuevos puntos: 10 × O(log n) = O(log n)
- Al final, extraer clasificación ordenada: O(n log n)

Total: O(carreras × 10 × log n + n log n) = O(21 × 10 × log 20 + 20 log 20) ≈ O(log n) amortizado

Si usara un vector simple y lo reordenara cada vez, sería O(carreras × n log n) = O(21 × 20 × log 20) ≈ O(4200 operaciones) versus O(log 20) ≈ O(4.3 operaciones) del heap.

### SICT0303: Implementa acciones científicas

**Implementa mecanismos para consultar información de las estructuras correctos.**

En mi proyecto implementé varios mecanismos de consulta para la Lista Doblemente Ligada:

1. **Recorrido secuencial (`mostrarTodos`)**: Permite recorrer toda la lista desde la cabeza hasta la cola, mostrando la información de cada monoplaza en orden. Complejidad O(n).

2. **Recorrido inverso (`mostrarInverso`)**: Aprovecha la característica de doble enlace para recorrer desde la cola hasta la cabeza. Útil para mostrar resultados en orden inverso. Complejidad O(n).

3. **Conversión a vector (`toVector`)**: Genera una representación en vector de toda la lista, útil para aplicar algoritmos que requieren acceso indexado como Merge Sort. Complejidad O(n).

4. **Obtención de extremos (`getCabeza`, `getCola`)**: Proporcionan acceso directo al primer y último nodo. Complejidad O(1).

5. **Consulta de tamaño (`getTamano`)**: Retorna el número de elementos en la lista sin necesidad de recorrerla. Complejidad O(1).

6. **Verificación de vacío (`estaVacia`)**: Comprueba si la lista no tiene elementos. Complejidad O(1).

Todos estos mecanismos están correctamente implementados, usan los punteros `siguiente` y `anterior` apropiadamente, y manejan casos especiales como listas vacías.

Para el MaxHeap, implementé los siguientes mecanismos de consulta:

1. **Obtener campeón (`getCampeon`)**: Retorna el nodo raíz con el piloto líder. Complejidad O(1).

2. **Obtener tamaño (`getTamano`)**: Retorna el número de pilotos en el heap. Complejidad O(1).

3. **Verificar vacío (`estaVacio`)**: Comprueba si el heap no tiene elementos. Complejidad O(1).

4. **Mostrar clasificación completa (`mostrarClasificacion`)**: Extrae todos los elementos en orden decreciente de puntos. Complejidad O(n log n).

5. **Obtener clasificación ordenada (`getClasificacionOrdenada`)**: Retorna un vector con todos los pilotos ordenados por puntos. Complejidad O(n log n).

Todos estos mecanismos permiten consultar la información del campeonato de manera eficiente y flexible.

**Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.**

Implementé funciones de carga de archivos CSV para tres estructuras diferentes:

**Cargar pilotos (`Temporada::cargarPilotos`)**:
1. Apertura segura del archivo: Verifico que el archivo se abra correctamente con `ifstream`. Si falla, muestro un mensaje de error.
2. Lectura del encabezado: Uso `getline()` para saltar la primera línea.
3. Procesamiento línea por línea: Utilizo `getline()` en un ciclo `while` para leer cada línea.
4. Parsing de datos: Uso `stringstream` y `getline()` con delimitador de coma para separar campos.
5. Conversión de tipos: Uso `stoi()` para convertir strings a enteros.
6. Creación de objetos: Instancio objetos `Piloto` e inserto en el heap con 0 puntos iniciales.
7. Cierre del archivo: Cierro explícitamente con `close()`.

**Cargar calendario (`Temporada::cargarCalendario`)**:
1. Proceso similar al anterior
2. Crea objetos `Pista` con id, nombre y número de vueltas
3. Almacena en el vector `calendario`

**Guardar resultados (`Temporada::guardarResultados`)**:
1. Apertura segura para escritura: Verifico que `ofstream` se abra correctamente.
2. Escritura del encabezado: CSV con columnas posicion, piloto, dorsal, puntos.
3. Extracción ordenada del heap: Llama `getClasificacionOrdenada()` para obtener clasificación final.
4. Escritura de datos: Escribe cada piloto en una línea del CSV.
5. Cierre del archivo: Cierra explícitamente.

Estos mecanismos son robustos, manejan errores apropiadamente y permiten modificar fácilmente los datos sin recompilar el código, lo cual es fundamental para la mantenibilidad del proyecto.