(https://github.com/Surfi89/get_next_line/tree/main)

// MANDATORY //  PREGUNTAR A EVALUDOR SOBRE TIMEOUT //

# Entrega get_next_line
	|--> get_next_line.c
	 |--> get_next_line_utils.c
	  |--> get_next_line.h

# get_next_line --> char	*get_next_line(int fd);
	
  * fd --> File descriptor (de donde se leera la info)

# Valor devuelto
	\--> Linea leida (si todo va bien)
	 \\--> NULL si falla o si la lectura termina
	 
# Funciones permitidas // MIRAR (ex27 RELOADED) Y ABAJO EN FUNCIONES*//
	 |--> read()*
	  |--> malloc()
	   |--> free()

# Funciones necesarias // MIARAR (libft) //
	|--> ft_strlen (cuenta chars de un string)
	 |--> ft_strchr (busaca primera aparicion de char especifico)
	  |--> ft_strjoin (concatena dos strings)

# A tener en cuenta

  * La funcion tiene que leer linea a linea el documento
	\--> Hacer un bucle linea por linea (cada vez que encuentre '\n')
	 \\--> Si no hay mas para leer o un error debe devolver NULL

  * Comprobar que funciona leyendo archivos y del standar input (stdin)
	|--> (stdin) proviene del teclado, el usuario lo introduce directamente
	 \--> Son funciones como scanf(), getchar() o fgets()
	
	|--> Al ejetcutar el programa se puede redireccionar a un archivo
	 \--> ./mi_programa < archivo_de_entrada.txt
	 
  * La linea devuelta debe llevar '\n' al final de la linea
	\--> Excepto si llega al final del archivo y no termina con '\n'
	
  * En el archivo (.h) como minimo debe haber el prototipo de la funcion
  
  * Se pueden incluir todas la funciones necesarias en get_next_line.c
  
  * Entender que es una (variable estatica)
  
  * Se debe poder compilar el proyecto con y sin el flag (-D BUFFER_SIZE=xx)
  	|--> El flag determina el buffer usado en cada lectura de get_next_line
  	 \--> cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c
  	  \\--> Comprobar y entender porque funciona o no con:
  	  	|--> BUFFER_SIZE=9999
  	  	 |--> BUFFER_SIZE=1
  	  	  |--> BUFFER_SIZE=10000000

  * Implementar alguna manera lógica de sortear comportamiento indeterminado con:
  	|--> Si archivo que apunta fd ha cambiado desde la última vez que se llamó
  	 \--> (siempre que read() no haya llegado al final del archivo)
  	
  	|--> Si lo que se lee es un archivo binario *(??)
  	 \--> Archivos no legibles por personas, solo maquinas
  	  \\--> Solo contienen 1s y 0s

// IMPORTANTE //

# Intenta leer lo menos posible cada vez que se llame a la funcion
# Si se encuentra un salto de línea, deberá devolver la línea actual

# No leer archivos enteros y luego procesar cada línea 
# No usar (libft)
# No usar (lseek)
# No usar (variables globales) **(??)
  
// FUNCIONES //

# read(int fd, void *buff, size_t BUFFER_SIZE)

  * Lee datos de un archivo o del stdin (stardard input)
  * Los almacena en un buffer (espacio de memoria)
  
  * El fd (valor entero) puede ser cualquier cosa que haya abierto open()*
  	\--> (0) stdin (standard input) ~ Teclado o dispositivo
  	 \\--> (1) stdout (stadard output) ~ Pantalla
    	  \\\--> (2) stderr (standard error) ~ Error
  
  * El puntero buff apunta al bloque de memoria donde estan los datos leídos
  	\--> Si el buffer es demasiado pequeno se perderan datos
  	 \\--> Hay que asegurarse de que esta bin inicializado
  	  
  * BUFFER_SIZE es el numero de bytes ques se van a leer
  	\--> Retorna un valor positivo si aun hay datos por leer
  	 \\--> Retorna (0) si llega al (EOF), End of File
  	  \\\--> Retorna (-1) si ha habido un error

  * open() --> Mas info en cosas_importantes
  
  
