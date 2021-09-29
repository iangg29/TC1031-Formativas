# Análisis de complejidad 📈

### Insertion

El algoritmo para insertar un nuevo nodo al final de la lista doblemente ligada tiene que recorrer solo 1 paso, ya que se puede acceder directamente al final de la lista. Por lo que su complejidad es **O(1)**. Por otro lado, en caso de que se quiera agregar un valor dentor de la lista, se necesita recorrer **_n_** pasos, por lo que tiene una complejidad de **O(n)** para el peor de los casos.

### Search

El algoritmo para buscar un valor dentro de la lista doblemente ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta encontrar el valor a buscar. Por lo que su complejidad es **O(n)**.

### Update

El algoritmo para actualizar el valor de un nodo en una lista doblemente ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utiliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta llegar al índice deseado para después actualizar el valor del nodo. Por lo que su complejidad es de **O(n)**.

### Delete At

El algoritmo para eleminar un nodo en específico dentro de una lista doblemente ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utiliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta llegar al índice deseado para después eliminar el nodo. Por lo que su complejidad es de **O(n)**. Por otro lado, para eliminar el primer o último nodo su complejidad es de **O(1)**, ya que no necesita recorrer la lista.

---

Ian García 2021.
