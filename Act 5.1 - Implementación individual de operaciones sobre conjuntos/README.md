# Análisis de complejidad 📈

### Put

Para poder hacer el algoritmo de inserción a la tabla hash, se tienen que tomar en cuenta varias cosas. Primeramente,
hay que considerar la función *indexOf()*, la cual es de gran utilidad para saber el índice o posición de la llave. Una
vez se agregue la llave y el valor pasados como parámetros a la función ignorando si el espacio ya está ocupado, ya que
este se moverá cuadráticamente a la siguiente posición en caso de colisión. Una vez dicho esto, se puede decir que su
complejidad temporal es de
**O(1)** para el peor de los casos, ya que solo se agregan valores y llaves a los índices de la tabla, sin embargo
algunas fuentes mencionan que, en caso de que la tabla esté saturada, su complejidad temporal será de **O(n)** para el
peor de los casos.

### Get

Para poder hacer el algoritmo de *get()* en una tabla hash, se depende de varios factores, ya que normalmente su
complejidad temporal es de **O(1)**, sin embargo, este tiempo no siempre puede ser posible debido a las posibles
colisiones dentro de la tabla, lo cual aumentaría complejidad temporal en tiempo.

---

Ian García 2021.