# Análisis de complejidad 📈

### Insertion

El algoritmo para insertar un nuevo nodo al final de la lista ligada tiene que recorrer **_n_** pasos, debido a que utiliza un ciclo **_while_** que recorerrerá todos los elementos hasta llegar al final de la lista para poder añadir el nuevo nodo. Por lo que su complejidad es **O(n)**. Por otro lado, en caso de que la lista esté vac´ía, se necesita utilizar el método **_addFirst_** el cual solo tiene una complejidad de **O(1)** ya que no necesita recorrer la lista.

### Search

El algoritmo para buscar un valor dentro de la lista ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta encontrar el valor a buscar. Por lo que su complejidad es **O(n)**.

### Update

El algoritmo para actualizar el valor de un nodo en una lista ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utiliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta llegar al índice deseado para después actualizar el valor del nodo. Por lo que su complejidad es de **O(n)**.

### Delete At

El algoritmo para eleminar un nodo en específico dentro de una lista ligada tiene que recorrer **_n_** pasos para el peor de los casos, esto es, debido a que utiliza un ciclo **_while_** que recorrerá todos los elementos de la lista hasta llegar al índice deseado para después eliminar el nodo. Por lo que su complejidad es de **O(n)**. Por otro lado, para eliminar el primer nodo su complejidad es de **O(1)**, ya que no necesita recorrer la lista.

---

Ian García 2021.
