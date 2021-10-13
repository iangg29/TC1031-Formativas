# Análisis de complejidad 📈

### Visit

El algoritmo para visitar cada nodo del BST tiene que recorrer ***n*** pasos, debido a que solo tiene que ir uniendo los
valores en un ***string***; Este recorrido lo hace para cada función (***preorder***, ***inorder***, ***postorder***
, ***levelorder***). Estos métodos hacen uso de la recursión con condiciones para recorrer al BST, por lo que su
complejidad sería de **O(n)**.

### Height

El algoritmo para obtener la altura del BST tiene que recorrer ***n*** pasos, ya que utiliza la recursión para poder ir
navegando entre las ramas de los nodos sumando 1 en cada nivel hasta llegar a las hojas. Por lo que su complejidad es **O(n)**.

### Ancestors

El algoritmo para imprimir los valores de los nodos que estén arriba tiene que recorrer ***n*** pasos, ya que utilizando
recursión, tiene que ir recorriendo el BST para encontrar los nodos arriba del deseado. Por lo que su complejidad es
de **O(n)**.

### What level am I

El algoritmo para conocer el nivel en el que está un nodo en específico tiene que recorrer ***n*** pasos, debido a que
tiene que recorrer el BST utilizando recursión para así poder ir calculando el nivel en el que está. Por lo que su
complejidad es de **O(n)**.

---

Ian García 2021.