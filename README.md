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
- [Desarrollo]
	- [Gestión del mapa .ber y parseo]
		- [Gestionar .ber]
		- [Parseo de caracteres]
		- [Parseo de rectangulo y muros]
		- [Parseo de rutas con Flood Fill]
	- [Gestion de gráficos]
		- [Mostar imagen en ventana]
		- [Cierre con ESC y cruz roja]
		- [Resize de la ventana]
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

## Bibliografía y recursos

### Páginas web

- [MiniLibx | 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)

### Vídeos

- [Beginner's Guide To The Desktop](https://www.youtube.com/playlist?list=PLTXMX1FE5Hj7JmR73CQDXkNq8OVn9_Z6F)
- [Draw a Pollock painting with the minilibX](https://www.youtube.com/watch?v=9eAPbNUQD1Y)
- [Introduction to the minilibX : a simple X-Window programming API in C](https://www.youtube.com/watch?v=bYS93r6U0zg)
