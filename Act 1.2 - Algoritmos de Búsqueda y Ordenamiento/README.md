# Análisis de complejidad 📈

### Selection Sort

El algoritmo de ordenamiento de selección (Selection Sort) tiene que recorrer ***n*** pasos 2 veces. Debido a que en el
peor de los casos tiene que volver a acomodar todo el vector de nuevo comparando cada número. Por lo cual su complejidad
es **O(n^2)**.

### Bubble Sort

El algoritmo de ordenamiento de burbuja (Bubble Sort) tiene que recorrer ***n*** pasos 2 veces. Debido a que en el peor
de los casos tiene que comparar todos los números e intercambiar su posición. Por lo cual su complejidad es **O(n^2)**.

### Merge Sort

El algoritmo de ordenamiento de unión (Merge Sort) tiene que dividir la búsqueda en pasos más pequeños (mitades) por lo
que su complejidad al momento sería **O(log n)**, sin embargo, al momento de juntar los vectores ordenados, su
complejidad se aumentará un **O(n)**. Dando como resultado una complejidad final de **O(n log n)**.

### Búsqueda Secuencial

El algoritmo de búsqueda secuencial tiene que recorrer en el peor de los casos una cantidad de ***n*** pasos. Por lo
cual su complejidad es **O(n)**.

### Búsqueda Binaria

El algoritmo de búsqueda binaria (Binary Search) funciona de una manera parecida el Merge Sort, ya que este divide la
búsqueda en mitades de forma recursiva. Por lo cual su complejidad es **O(log n)**.

---

Ian García 2021.
