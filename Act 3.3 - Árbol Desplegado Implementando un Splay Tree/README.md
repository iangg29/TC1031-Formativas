# Análisis de complejidad 📈

### Add

El algoritmo para poder insertar un nuevo valor a la fila priorizada debe de hacer uso de dos funciones, la primera
inserta el nodo de acuerdo a su valor y la siguiente función (***splay***) rota y ordena el árbol en caso de ser
necesario para que el nuevo valor ingresado sea la raíz del arbol. Por lo que su complejidad es de **O(log n)** para el
peor de los casos.

### Remove

El algoritmo para remover un nodo del árbol, así como para ordenar nuevamente el árbol (***splay***) y asignar su
sucesor como raíz tiene que recorrer **n** pasos. Por lo que su complejidad es de **O(log n)** para el peor de los
casos.

### Find

El algoritmo para encontrar un nodo con un valor en específico, tiene que recorrer **n** pasos, ya que hace uso de la
recursividad para completar dicha acción. En caso de que el valor sea encontrado, el algoritmo ejecutará la función ***splay*** para asignar el valor encontrado como la raíz del árbol. Por lo que su complejidad es de **O(log n)** para el
peor de los casos.

### Size

El algoritmo para obtener el tamaño del Splay Tree solo tiene que devolver el atributo de tamaño. Por lo que su
complejidad es de **O(1)** para el peor de los casos.

---

Ian García 2021.