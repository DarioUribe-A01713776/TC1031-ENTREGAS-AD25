# Simulador de Carreras de Fórmula 1
Autor: Darío A. Uribe

![Logo F1](./files/F1-logo.png)

Este proyecto es un simulador de carreras de Fórmula 1 que permite gestionar y simular competencias con los pilotos y escuderías de la temporada 2025. El sistema ofrece la posibilidad de cargar datos de pilotos desde archivos externos, seleccionar configuraciones personalizadas de carrera y visualizar resultados ordenados de manera eficiente.

Para asegurar que los resultados de la carrera estén siempre ordenados correctamente, el sistema utiliza el algoritmo **Merge Sort**. Este algoritmo avanzado permite ordenar los monoplazas rápidamente según su tiempo de carrera, ofreciendo al usuario una visualización clara y precisa de las posiciones finales.

Además, el sistema incorpora una **Lista Doblemente Ligada**, una estructura de datos que optimiza las operaciones de gestión y recorrido de los monoplazas durante la simulación. Esto permite agregar, eliminar y recorrer elementos de manera eficiente en ambas direcciones, manteniendo la flexibilidad necesaria para futuras expansiones del proyecto.

Para conservar los datos entre sesiones y facilitar la configuración, el sistema incluye un mecanismo de **carga de datos desde archivos CSV**. Toda la información de los pilotos se almacena en un archivo llamado `pilotos.csv`, que contiene atributos como nombre, dorsal, habilidad y probabilidad de error. De esta forma, puedo mantener los datos organizados y modificarlos fácilmente sin necesidad de recompilar el programa.

Este simulador de Fórmula 1 combina la eficiencia de algoritmos avanzados como Merge Sort y estructuras dinámicas como la Lista Doblemente Ligada con un sistema interactivo de configuración, proporcionando una herramienta robusta, realista y fácil de usar para simular carreras de la máxima categoría del automovilismo.

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

## Cambios sobre el primer avance

- **Implementación de Lista Doblemente Ligada**: Reemplacé el uso de `vector<Monoplaza*>` por una estructura de Lista Doblemente Ligada. Esta estructura fue incluida para cumplir con los requerimientos del avance 2 y porque ofrece mayor flexibilidad para operaciones de inserción y eliminación en ambos extremos de la lista. Aunque para este proyecto el vector era suficiente, la lista ligada me prepara para futuras expansiones donde pueda necesitar modificar la parrilla dinámicamente durante la carrera.
- **Sistema de carga desde archivos**: Eliminé la inicialización hardcodeada de pilotos y la reemplacé por un sistema de carga desde archivo CSV. Esto mejora significativamente la mantenibilidad del código y permite actualizar datos sin recompilar.
- **Interactividad del usuario**: Transformé el programa de un simulador automático a uno interactivo donde el usuario puede personalizar aspectos de la carrera. Esto hace el proyecto más dinámico y permite al usuario experimentar con diferentes configuraciones.

## Instrucciones para compilar el avance de proyecto

### Para Windows (PowerShell):
```bash
g++ -o carrera sources/main.cpp sources/monoplaza.cpp sources/piloto.cpp sources/listaDoble.cpp -I includes
```

### Para Linux/macOS:
```bash
g++ -o carrera sources/main.cpp sources/monoplaza.cpp sources/piloto.cpp sources/listaDoble.cpp -I includes
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

El programa requiere un archivo de entrada llamado `pilotos.csv`, ubicado en la carpeta `sources/`, que contiene la lista de pilotos en el siguiente formato:

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

Además del archivo de entrada, el programa solicita al usuario durante la ejecución:
1. **Selección de piloto favorito**: El usuario elige un piloto de la lista cargada (entrada numérica 1-20).
2. **Número de vueltas**: El usuario define cuántas vueltas tendrá la carrera (entrada numérica 1-71).

El programa valida todas las entradas para asegurar que estén dentro de los rangos permitidos.

## Descripción de las salidas del avance de proyecto

El programa proporciona las siguientes salidas:

1. **Banner de bienvenida**: Muestra el título del simulador y confirma la carga exitosa de pilotos desde el archivo CSV.

2. **Lista de pilotos disponibles**: Despliega todos los pilotos cargados con su información:
   - Número de índice
   - Nombre completo
   - Número de dorsal
   - Nivel de habilidad

3. **Confirmación de configuración**: Muestra la configuración seleccionada por el usuario:
   - Piloto favorito elegido
   - Número de vueltas de la carrera

4. **Resultados de la carrera**: Al finalizar la simulación, se muestra la clasificación final ordenada de menor a mayor tiempo:
   - Posición final (1-20)
   - Escudería
   - Nombre del piloto
   - Tiempo total de carrera en segundos

Ejemplo de salida:
```
========================================
       RESULTADOS DE LA CARRERA
========================================

1. McLaren - Lando Norris | Tiempo: 5298s
2. Red Bull - Max Verstappen | Tiempo: 5301s
3. Ferrari - Charles Leclerc | Tiempo: 5305s
...
```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

**Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.**

En mi proyecto, implementé el algoritmo de ordenamiento **Merge Sort** en las funciones `merge()` y `mergeSort()` para ordenar los resultados de la carrera. El análisis de complejidad del algoritmo es el siguiente:

- **Complejidad temporal en el peor de los casos**: O(n log n), ya que Merge Sort siempre requiere dividir el conjunto de datos recursivamente (log n niveles) y luego combinar las sublistas en cada nivel (n comparaciones). Esto significa que, sin importar el estado inicial de la lista de monoplazas, el número de operaciones sigue siendo consistente.

- **Complejidad temporal en el mejor de los casos**: O(n log n), dado que el algoritmo sigue dividiendo y combinando incluso cuando la lista está parcialmente o completamente ordenada. A diferencia de algoritmos como QuickSort, Merge Sort no se beneficia de listas pre-ordenadas.

- **Complejidad espacial**: O(n), debido a que se crean arreglos temporales `L` y `R` durante el proceso de merge para almacenar las sublistas.

Comparado con otros algoritmos como Bubble Sort O(n²) o Selection Sort O(n²), Merge Sort es significativamente más eficiente para mi proyecto que maneja 20 monoplazas. Aunque para conjuntos pequeños la diferencia no es notable, elegí Merge Sort por su consistencia y porque es un algoritmo estable que preserva el orden relativo de elementos con tiempos iguales.

**Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.**

En mi proyecto utilizo una **Lista Doblemente Ligada** implementada en las clases `Nodo` y `ListaDoble`. El análisis de complejidad de las operaciones principales es:

- **Agregar al final (`agregar`)**: O(1), ya que mantengo un puntero directo a la cola de la lista, permitiendo inserción inmediata sin recorrer la estructura.

- **Agregar al inicio (`agregarInicio`)**: O(1), similar al caso anterior, mantengo un puntero a la cabeza que permite inserción directa.

- **Recorrido completo (`mostrarTodos`, `toVector`)**: O(n), donde n es el número de monoplazas. Debo visitar cada nodo una vez para mostrar o convertir la lista.

- **Búsqueda (`buscar`)**: O(n) en el peor caso, ya que debo recorrer la lista completa si el elemento no existe o está al final.

- **Eliminación de nodo específico (`eliminar`)**: O(1), asumiendo que ya tengo la referencia al nodo. Si necesito buscar primero, sería O(n).

- **Conversión a vector (`toVector`)**: O(n), útil para mantener compatibilidad con mi implementación de Merge Sort que trabaja sobre vectores.

- **Actualización desde vector (`actualizarDesdeVector`)**: O(n), recorro la lista una vez para actualizar las referencias después del ordenamiento.

La Lista Doblemente Ligada me ofrece navegación bidireccional (adelante y atrás) con complejidad O(1) entre nodos adyacentes, lo cual es una ventaja sobre listas simples. Aunque para este proyecto específico no exploto completamente esta capacidad, la estructura está preparada para futuras expansiones donde pueda necesitar recorrer la parrilla en orden inverso o eliminar elementos durante la carrera.

### SICT0302: Toma decisiones

**Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.**

Para mi proyecto, seleccioné **Merge Sort** como algoritmo de ordenamiento por las siguientes razones:

1. **Estabilidad**: Merge Sort es un algoritmo estable, lo que significa que preserva el orden relativo de elementos con valores iguales. Esto es importante en mi simulación porque si dos pilotos terminan con el mismo tiempo (aunque poco probable por el factor aleatorio), quiero mantener su orden original.

2. **Complejidad garantizada**: A diferencia de QuickSort que en el peor caso puede degradarse a O(n²), Merge Sort garantiza O(n log n) en todos los casos. Para mi simulación de 20 monoplazas esto asegura un rendimiento consistente.

3. **Simplicidad de implementación**: Aunque requiere espacio adicional O(n), la implementación es directa y fácil de entender, lo cual facilita el mantenimiento del código.

4. **Adecuado para el tamaño del problema**: Con 20 elementos, cualquier algoritmo O(n log n) es suficientemente rápido. 
La implementación en mi código divide recursivamente el vector de monoplazas hasta obtener subarreglos de tamaño 1, luego los combina comparando el atributo `tiempoCarrera` de cada monoplaza, produciendo un resultado ordenado de menor a mayor tiempo.

**Selecciona una estructura de datos adecuada al problema y la usa correctamente.**

Seleccioné una **Lista Doblemente Ligada** para almacenar los monoplazas durante la simulación por las siguientes razones:

1. **Flexibilidad para inserciones/eliminaciones**: Aunque en la versión actual no elimino monoplazas durante la carrera, la lista ligada me permite hacerlo en O(1) si tengo la referencia al nodo. Esto prepara el código para futuras expansiones donde pueda simular abandonos o descalificaciones.

2. **Navegación bidireccional**: La lista doble me permite recorrer la parrilla tanto hacia adelante como hacia atrás. Esto podría ser útil para mostrar clasificaciones inversas o implementar funcionalidades donde necesite retroceder en la lista.

3. **Cumplimiento de requisitos académicos**: El avance 2 requería implementar una estructura de datos más compleja que un vector. La lista doblemente ligada cumple este requisito mientras mantiene funcionalidad práctica.

4. **Separación de conceptos**: Al usar una lista ligada para la gestión de monoplazas y convertir temporalmente a vector solo para el ordenamiento, separo las responsabilidades de cada estructura. La lista maneja la colección dinámica y el vector facilita el algoritmo de ordenamiento.

Uso correctamente la estructura implementando todos los métodos esenciales: agregar, eliminar, recorrer, buscar y conversión entre formatos. El manejo de memoria es correcto con un destructor que libera todos los nodos al finalizar el programa.

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

**Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.**

Implementé la función `cargarPilotos()` que lee el archivo CSV `pilotos.csv` y carga los datos en un vector de objetos `Piloto`. El proceso es el siguiente:

1. **Apertura segura del archivo**: Verifico que el archivo se abra correctamente con `ifstream`. Si falla, muestro un mensaje de error y retorno un vector vacío.

2. **Lectura del encabezado**: Uso `getline()` para saltar la primera línea que contiene los nombres de las columnas.

3. **Procesamiento línea por línea**: Utilizo `getline()` en un ciclo `while` para leer cada línea del archivo hasta llegar al final.

4. **Parsing de datos**: Para cada línea, uso `stringstream` y `getline()` con delimitador de coma para separar los campos: nombre, dorsal, habilidad y probError.

5. **Conversión de tipos**: Uso `stoi()` para convertir las cadenas de habilidad y probError a enteros.

6. **Creación de objetos**: Instancio objetos `Piloto` con los datos parseados y los agrego al vector.

7. **Cierre del archivo**: Cierro explícitamente el archivo con `close()` después de la lectura.

8. **Validación**: El programa verifica que se hayan cargado pilotos exitosamente antes de continuar con la simulación.

Este mecanismo es robusto, maneja errores apropiadamente y permite modificar fácilmente los datos de los pilotos sin recompilar el código, lo cual es fundamental para la mantenibilidad del proyecto.