# so_long


- [Introducción]
- [Nuevos conceptos]
- [Librería Minilibx](#libería-minilibx)
	- [Qué es y cómo instalarla](#qué-es-y-cómo-instalarla)
	- [Funciones y usos](#funciones-y-usos)
		- [mlx_init](#mlx_init)
		- [mlx_new_window](#mlx_win)
		- [mlx_loop](#mlx_loop)
- [Libería Math]
- [Desarrollo](#desarrollo)
	- [Gestión del mapa .ber y parseo](#gestión-del-mapa-ber-y-parseo)
		- [Gestionar .ber](#gestionar-ber)
		- [Parseo de recangulo y caracteres](#open-read-parseo-de-caracteres-y-comprobar-rectangulo)
		- [Parseo de muros]
		- [Parseo de rutas con Flood Fill]
	- [Gestion de gráficos](#gestión-de-gráficos)
		- [Mostar imagen en ventana](#mostrar-imagen-en-ventana)
		- [Cierre con ESC y cruz roja](#cierre-con-esc-y-cruz)
		- [Resize de la ventana y minimizar]
		- [Uso de images de la miniLibx]
	- [Juego]
		- [Hacer loop de refresco de cada movimiento o 30 fps]
		- [Movimiento con WASD]
		- [Colosion con paredes]
		- [Mostrar movimientos]
		- [Recolección de objetos]
		- [Llegar a la meta]
- [Dudas y preguntas]
- [Bibliografía y recursos](#bibliografía-y-recursos)

## Nuevos conceptos

- **Event Loop**:

- **Handler Function**

- **KEYSYM vs KEYCODE**

- **Hooks**:

## Libería Minilibx

### Qué es y cómo instalarla

Una de los puntos clave de este círculo es aprender a usar librerías externas. En este ocasión vamos a manejarnos con la [MinilibX](https://github.com/42Paris/minilibx-linux), una versión minimalista del sistema de ventanas [X](https://en.wikipedia.org/wiki/X_Window_System) de Linux.

Esta librería es la que nos va a permitir crear nuevas2 ventanas en nuestro escritorio, dibujar en ellas nuestros pixeles y manejar el input del usuario. Pero para ello, primero debemos incluirla en nuestro proyecto. Aunque puede parecer lioso, en realidad es muy fácil.

1. Lo primero de todo, aunque nosotros vamos a usar la minilibx, esta depende a su vez del sistema de ventanas X original. En concreto depende de `xorg`, `x11` y `zlib`, por lo que tenemos que instalar `xorg`, `libxext-dev` y `zlib1g-dev`.

```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

2. Una vez que tenemos lo necesario, hay que meter la Minilibx dentro de la carpeta de nuestro proyecto (asumiendo de que ya hayas creado tu repo en Git). En lugar de un git clone dentro de nuestro proyecto (lo que nos va a dar conflicto con nuestro propio Git), lo mejor es hacer un [submodulo](https://git-scm.com/book/en/v2/Git-Tools-Submodules). Es decir, una referencia para que Git descargue los archivos del respositorio original en lugar de volver a subir nosotros los archivos a nuestro propio Github.

```
git submodule add https://github.com/42Paris/minilibx-linux
```
3. Se creará una nueva carpeta, minilibx-linux. Metete dentro y ejecuta *configure* desde la terminal. Este comando, aparte de ejecutar make, comprobará que X11 está instalado en nuestro sistema

```
cd minilibx-linux
./configure
```
4. Una vez que hemos hecho make, acuerdate de meter los .h de la Minilibx en el .h de tu proyecto.

```c
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
```

5. Por último, nos falta unir todas las librerías necesarias a la hora de compilar, tanto la Minilibx como X11 y Xexti.

Vamos a empezar con la Minilibx. Despues de hacer make en nuestra carpeta minilibx-linux, también se crearán dos archivos .a: libmlx.a y libmlx_Linux.a. Los vamos a necesitar para nuestro proyecto, así que a la hora de compilar tenemos que utilizar dos flags:

* **-L minilibx-linux/**: La flag -L le dice al compilador que busque dentro de la carpeta minilibx-linux.

* **-lmlx**: Una vez dentro de la carpeta minilibx-linux, le decimos que busque la libería libmlx.a (-lmlx).

Ahora que ya le hemos dicho al sistema donde tiene que buscar el .a de la Minilibx, nos queda señalarle que busque X11 y Xext. Al ser liberías instaladas en el propio sistema, basta con usar `-lXext` y `-lX11` para que las busque en nuestros binarios. El código se quedaría así.

```
cc main.c -L minilibx-linux/ -lmlx -lXext -lX11
```

Como vamos a tener que usar estas flags por cada objeto, lo mejor es incluir esta regla en el Makefile.

```
NAME = so_long
SRC = main.c
OBJ = $(SRC:%.c=%.o)
all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) -L minilibx-linux/ -lmlx -lXext -lX11
```

### Funciones y usos

#### mlx_init

Inicia la estructura que va a alojar el resto de información sobre nuestro sistema de ventanas. Es el puntero principal que dicta el resto de elementos de nuestro sistema, como las diferentes ventanas que vamos a usar.

```c
	void	*mlx;

	mlx = mlx_init();
```

#### mlx_win

Dentro de nuestra estructura mlx, crea una nueva ventana. Recibe como parametros el puntero de nuestra estructura mlx, el tamaño de la ventana y su nombre.

```c
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
```

### mlx_loop

Es el encargado de mantener nuestro proceso en abierto. Sin el, la ventana automáticamente se cerraría y se acabaría el proceso, como en un código normal.


```c
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
```


## Desarrollo

### Gestión del mapa .ber y parseo

Para que sea más fácil gestionar el mapa, debemos de convertir nuestro fichero .ber en un array de strings (parecido al primer rush de la piscina) para luego poder manejarlo mejor y poder hacer todas las comprobaciones necesarias, como el flood fill. Por ahora vamos a usar esta estructura.

```c
typedef struct s_map
{
	char	**map_array;
	int		fd;
	int		y_size;
	int		x_size;
}	t_map;
```

#### Gestionar ber

Lo primero de todo, tenemos que ver es que el argv[1] es un fichero .ber. 

```C
int	check_ber(char *arg, t_map *map)
{
	if (!arg)
		return (FILE_ERROR);
	if (end_ber(arg))
		return (FILE_ERROR);
}

int	end_ber(char *arg)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len < 4)
		return (FILE_ERROR);
	return (ft_strncmp (arg + arg_len - 4, ".ber", 4));
}
```
#### Open, read, parseo de caracteres y comprobar rectangulo

Una vez que tenemos un fichero .ber, tenemos que ver si lo podemos abrir.

```c
int	check_ber(char *arg, t_map *map)
{
	if (!arg)
		return (FILE_ERROR);
	if (end_ber(arg))
		return (FILE_ERROR);
	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
}
```

Ahora viene uno de los primeros parseos importantes: ver si se puede abrir el fichero, si estamos ante un rectangulo y si tenemos los caracteres adecuados.

Lo primero, vamos a ver si se puede abrir el fichero

```c
int	check_ber(char *arg, t_map *map)
{

	if (!arg)
		return (FILE_ERROR);
	if (end_ber(arg))
		return (FILE_ERROR);
	if (find_size(map, arg) != SUCCESS || map->y_size < 3 || map->x_size < 3) // Un rectangulo debe de ser como minimo de 3 para moverse entre los muros
		return (FILE_ERROR);
}
int	find_size(t_map *map, char *arg)
{
	char	*temp;
	int		flag;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	close(map->fd); // Acuerdate de cerrar el fd
	return (SUCCESS);
}
```

Para el rectangulo, tenemos que primero hayar las dimensiones de nuestro mapa. Empezemos con y, que es el número de filas que tiene el mapa. Para ello, basta con saber el número de llamadas que se hacen a GNL hasta acabar la lectura.

```c
int	find_size(t_map *map, char *arg)
{
	char	*temp;
	int		ddflag;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	flag = SUCCESS;
	temp = get_next_line(map->fd);
	if (temp == NULL) 
		flag = FILE_ERROR;
	map->y_size = 1;
	while (temp)
	{
		if (temp)
			free (temp);
		temp = get_next_line(map->fd);
		map->y_size++;
	}
	close(map->fd);
	map->y_size--; // Restamos uno por que la ultima lectura de GNL nos va a dar NULL
	return (flag);
}
```

Aprovechando que estamos averiguando el tamaño en y línea a línea, podemos aprovechar para leer cada una de estas líneas, ver su tamaño y si contiene algún caracter que sea inadecuado.

```c
int	find_size(t_map *map, char *arg)
{
	char	*temp;
	int		flag;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	flag = SUCCESS;
	temp = get_next_line(map->fd);
	if (temp == NULL) 
		flag = FILE_ERROR;
	map->y_size = 1;
	map->x_size = len_set_char(temp);
	while (temp)
	{
		if (temp)
			free (temp);
		temp = get_next_line(map->fd);
		if (temp != NULL && (len_set_char(temp) != map->x_size))
			flag = FILE_ERROR;
		map->y_size++;
	}
	close(map->fd);
	map->y_size--;
	return (flag);
}

int	len_set_char(char	*line)
{
	ssize_t	string_size;
	char	*set;

	if (!line)
		return (0);
	string_size = 0;
	set = "10PCE";
	while (*line && *line != '\n')
	{
		if (!ft_strchr(set, *line))
			return (FILE_ERROR);
		string_size++;
		line++;
	}
	return (string_size);
}
```

#### Parseo de muros

Ahora toca comprobar que nuestro mapa está rodeado de muros. Para ello, podemos hacer un parseo parecido al del primero rush de la piscina y manejar un array.

Así que antes vamos a alojar todo el mapa dentro de un array char**

```C
int	allocate_map(t_map *map, char *arg)
{
	int		i;
	char	*temp; // Temporal para alojar el gnl

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc ((map->y_size + 1) * sizeof(char *)); // Alojamos el numero total de filas (acuerdate del +1 para el NULL)
	if (!map->map_array)
		return (MALLOC_ERROR);
	i = -1;
	while (i++ < map->y_size) // Inicializamos la estructura por si la tenemos que liberar el algun momento, ya que no podemos usar calloc
		map->map_array[i] = NULL;
	i = -1;
	while (i++ < map->y_size - 1)
	{
		temp = get_next_line(map->fd);
		map->map_array[i] = ft_substr(temp, 0, map->x_size); // Substring para quitar el \n del final y tener nuestro array limpio
		free (temp);
		temp = NULL;
		if (!map->map_array[i]) // Si en algun momento falla el alojo de memoria, estate preparado para limpiar y cerrar todo
			return (free_map_array(map, MALLOC_ERROR));
	}
	close(map->fd);
	return (SUCCESS);
}

int	free_map_array(t_map *map, int flag)
{
	int	i;

	if (!map || !map->map_array)
		return (flag);
	i = 0;
	while (map->map_array[i]) // Como el resto del array esta inicializado en NULL, no nos debemos preocupar
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
	map->map_array = NULL;
	if (map->fd) // Acuerdate de cerrar el fd incluso si falla algo
		close(map->fd);
	return (flag);
}
```

Ahora que ya tenemos nuestro mapa alojado en un array, podemos navegarlo con facilidad para comprobrar las paredes

```c
int	bad_walls(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_array[0][++i]) // Navegamos la primera fila hasta llegar a NULL
		if (map->map_array[0][i] != '1')
			return (FILE_ERROR);
	i = -1;
	while (map->map_array[map->y_size - 1][++i]) // Navegamos la ultima fila hasta llegar a NULL
		if (map->map_array[map->y_size - 1][i] != '1')
			return (FILE_ERROR);
	i = -1;
	while (++i < map->y_size) // En cuanto columnas, no podemos recorrerlas en base a NULL, por lo que dependemos de y_size
		if (map->map_array[i][0] != '1')
			return (FILE_ERROR);

	i = -1;
	while (++i < map->y_size) // zlo mismo por aqui
		if (map->map_array[i][map->x_size - 1] != '1')
			return (FILE_ERROR);
	return (SUCCESS);
}
```

#### Parseo de rutas con Flood Fill

### Gestión de gráficos

Antes que nada, por el amor de dios, créate una estructura que contenga todos los punteros de tu entorno mlx. Es decir, el puntero principal del init y tu ventana.

```c
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;
```

#### Mostrar imagen en ventana

1. Primero, inicia la estructura con mlx_init

```c
	mlx.mlx_ptr = mlx_init();
```

2. Abre una ventana con mlx_new_window

```c
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Hello world!");
```

3. Mantenla viva con mlx_loop

```c
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Hello world!");
	mlx_loop(mlx.mlx_ptr);
```

#### Cierre con ESC y cruz

Necesitamos cerrar la ventana de dos maneras, con nuestro teclado y con nuestro ratón.

* Teclado: necesitamos crear un hook de teclado con mlx_key_hook. Este hook va a coger todos nuestros inputs, por lo que solo necesitamos una función que libere toda la memoria si se pulsa la tecla escape (recuerda, usa keysym en lugar de keycodes, los primeros son universales y el segundo depende del OS del usuario).

```c
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx);


	int	handle_input(int keysym, t_mlx_data *mlx)
	{
		static int	i;

		if (keysym == XK_Escape)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
			exit(1);
		}
		return (0);
	}
```

* Ratón: Necesitamos un hook que esté atento a cuando se pulsa la x. Para ello usamos el evento DestroyNotify (si no tienes macro, es la flag 17).

```c
	mlx_hook(mlx.win_ptr, DestroyNotify, 0, close_window, &mlx);

	int	close_window(t_mlx_data *mlx)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(1);
	}
```
## Dudas y preguntas

- ¿Hay que crear un buffer que muestre toda la imagen de una vez, en lugar de generarla línea a línea?

- ¿Cuentan los mapas cuadrados?

Si es así, hay que cambiar esta funcion

```c
int	check_ber(char *arg, t_map *map)
{

	if (!arg)
		return (FILE_ERROR);
	if (bad_ber(arg))
		return (FILE_ERROR);
	if (bad_size(map, arg)|| map->y < 4 || map->x < 4 || map->y == map->x)
		return (FILE_ERROR);
	ft_printf("X is %d\nY is %d\n", map->x_size, map->y_size);
	//if (allocate_map(map) != SUCCESS)
		//return (FILE_ERROR);
	return (SUCCESS);
}

- Al alojar el mapa, ¿debe de incorporar los saltos de línea o evitarlos?

Evitando saltos 

```c
int	allocate_map(t_map *map, char *arg)
{
	int		i;
	char	*temp;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc ((map->y_size + 1) * sizeof(char *));
	if (!map->map_array)
		return (MALLOC_ERROR);
	i = -1;
	while (i++ < map->y_size)
	{
		temp = get_next_line(map->fd);
		map->map_array[i] = ft_substr(temp, 0, map->x_size);
		free (temp);
		if (!map->map_array)
			return (free_map_array(map, MALLOC_ERROR));
	}
	close(map->fd);
	return (SUCCESS);
}
```

Con saltos

```C
int	allocate_map(t_map *map, char *arg)
{
	int		i;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc ((map->y_size + 1) * sizeof(char *));
	if (!map->map_array)
		return (MALLOC_ERROR);
	i = -1;
	while (i++ < map->y_size)
	{
		map->map_array[i] = get_next_line(map->fd);
		if (!map->map_array)
			return (free_map_array(map, MALLOC_ERROR));
	}
	close(map->fd);
	return (SUCCESS);
}
## Bibliografía y recursos

### Páginas web

- [MiniLibx | 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)

### Vídeos

- [Beginner's Guide To The Desktop](https://www.youtube.com/playlist?list=PLTXMX1FE5Hj7JmR73CQDXkNq8OVn9_Z6F)
- [Draw a Pollock painting with the minilibX](https://www.youtube.com/watch?v=9eAPbNUQD1Y)
- [Introduction to the minilibX : a simple X-Window programming API in C](https://www.youtube.com/watch?v=bYS93r6U0zg)
