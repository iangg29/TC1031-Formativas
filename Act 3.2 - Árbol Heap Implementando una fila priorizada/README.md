# Análisis de complejidad 📈

### Push

El algoritmo para poder insertar un nuevo valor a la fila priorizada debe de hacer uso de un ciclo ***while***, para
poder insertar de izquierda a derecha así como por nivel del árbol. Por lo que su complejidad sería de **O(log n)** para
el peor de los casos.

### Pop

El algoritmo para remover la raiz del árbol (***data[0]***), así como para ordenar nuevamente el árbol (***heapify***)
tiene una complejidad de **O(log n)** para el peor de los casos. Ya que para remover el elemento su complejidad sería **O(1)**, y para ordenarlo **O(log n)**.

### Top

El algoritmo para obtener el primer valor de la fila priorizada solo tiene que recorrer 1 paso, por lo que su
complejidad es de **O(1)** para el peor de los casos.

### Empty

El algoritmo para poder saber si la fila priorizada se encuentra vacía solo tiene que revisar si el atributo de tamaño
es igual a cero. Por lo que su complejidad es de **O(1)** para el peor de los casos.

### Size

El algoritmo para obtener el tamaño de la fila priorizada solo tiene que devolver el atributo de tamaño. Por lo que su
complejidad es de **O(1)** para el peor de los casos.

---

Ian García 2021.