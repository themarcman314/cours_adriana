## Premier programme
```c
#include <stdio.h>
int main(void) {
    printf("Hello World!\n");
}
```

[Table ascii](https://www.ascii-code.com/)

## Fonctions type printf
[Documentation formatage type printf](https://cplusplus.com/reference/cstdio/printf/)

Imprimer l'espace aloué en mémoire d'une variable ***en octets/bytes (8 bits)***:
```c
	int foo = 2;
	printf("Quantité de mémoire alouée par la variable 'foo': %zu\n",
	       sizeof foo);
```

```c
	unsigned a = 2;
	printf("Quantité de mémoire alouée par la variable 'a': %zu\n",
	       sizeof a);
```

```c
    short b = 2;
	printf("Quantité de mémoire alouée par la variable 'b': %zu\n",
	       sizeof b);
```

```c
    char c = 2;
	printf("Quantité de mémoire alouée par la variable 'c': %zu\n",
	       sizeof c);
```

> [!IMPORTANT]
> **Piège**
> ```c
>     char d[] = "Une chaine de characteres\n";
> 	printf("Quantité de mémoire alouée par la variable 'd': %zu\n",
> 	       sizeof d);
> ```


[types de donées en c](https://en.wikipedia.org/wiki/C_data_types)


https://github.com/user-attachments/assets/799efb96-a163-4189-9078-9c9514c68330
