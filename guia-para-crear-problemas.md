# Guia para armar problemas

Copie y pegue esta carpeta, cambiando el nombre por el nombre del problema. Luego edite los archivos indicados a continuacion

## Datos basicos

Edite el archivo `problem.yaml`. Los datos que debe cambiar son:

- `name`: el nombre del problema, sin comillas ni nada (Router, 25 de Mayo, etc).
- `authors`: autores del problema separados por coma (Juan de los Palotes, Guido Perez)

## Enunciado

En el archivo `statement/problem.es.tex` escriba el nombre del problema en `problemname{<nombre>}`. Deje el resto del enunciado como esta

## Submissions

En el archivo `submissions/accepted/solution.cpp` deje una solucion al problema (debe pasar todos los test cases, obviamente).

## Casos de prueba

En la carpeta `data/secret` agregue los casos de prueba contra los que se van a probar las submissions.

Cada caso de prueba consta de:
- `<x>.in`: entrada del caso de prueba, reemplace `<x>` por la numeracion del caso.
- `<x>.ans`: salida esperada contra la que se va a probar la solucion
