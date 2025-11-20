- **Pattern Matching**: Usa pattern matching en lugar de condicionales cuando sea posible. Aprovecha guards para condiciones adicionales y prefiere múltiples cláusulas sobre `if/else` o `case` cuando sea posible.
- **Estructuras Inmutables**: Usa estructuras inmutables siempre.
- **Pipe Operator**: Prefiere el pipe operator `|>` para transformaciones de datos.
- **Destructuración**: Aprovecha pattern matching para destructurar datos.
- **Manejo de Errores**: Usa `with` para manejar múltiples operaciones que pueden fallar. Retorna tuplas `{:ok, result}` o `{:error, reason}` para operaciones que pueden fallar. Prefiere `case` o `with` sobre `try/rescue` cuando sea posible.
- **Funciones**: Usa `!` en funciones que lanzan excepciones (ej: `File.read!`). Prefiere funciones puras sin efectos secundarios.
- **Variables**: Evita variables no usadas (usa `_` como prefijo si es necesario).
- **Módulos**: Usa alias para módulos usados frecuentemente.
- **Organización**: Agrupa todas las cláusulas de una función con el mismo nombre juntas. Ordena de más específico a más general (las cláusulas se evalúan en orden). Mantén consistencia en el número de argumentos entre cláusulas.
- **Arquitectura**: Dividir requerimientos grandes en tareas más pequeñas.
- **Idioma**: Todas las respuestas en español.


- Los hooks se registran automáticamente por el framework. **NO importar manualmente**.
- Archivo: `*.hooks.js` en el mismo directorio del componente
- Export: Nombre coincide con `:hook="NombreHook"`
- Ejemplo:
  ```
  lib/meratenencia_web/components/select_input/
    ├── select_input.ex
    ├── select_input.sface
    └── select_input.hooks.js  # Auto-registrado

<div :hook="SelectInput" id="SelectInput">
  <!-- contenido -->
</div>  
  ```

# Reglas Estrictas para Bloques Monádicos (Error.m)

## Sintaxis Correcta de Error.m

La sintaxis correcta utiliza `Error.m do` directamente, sin notaciones intermedias como `m:` ni asignaciones previas con `=`. Esta forma permite una composición monádica limpia donde cada operación fluye naturalmente hacia la siguiente.

## Reglas del Bloque Monádico

- **Sintaxis directa**: Usa `Error.m do` << bloque monadico >> end
- **Operaciones monádicas**: Cada expresión con `<-` debe retornar `{:ok, valor}` o `{:error, razón}`
- **Bind monádico**: El operador `<-` extrae automáticamente valores del contexto monádico
- **Prohibido**: No uses asignación directa `=` dentro de bloques `do`
- **Última expresión**: No requiere `<-`, se retorna directamente. Usa `Error.return()`
- **Funciones auxiliares**: Deben retornar `{:ok, _}` o usar `Error.return()`/`Error.fail()`
- **Corte automático**: Cualquier `{:error, _}` detiene automáticamente toda la cadena

```elixir
Logger.info("Iniciando Logger") # ✅ CORRECTO
Error.m do
  result <- operacion_monadica() # ✅ CORRECTO (DESEADO, no poner logs por gusto)
  result <- operacion() |> IO.inspect(label: "Debug") |> Error.return() # ✅ CORRECTO
  _ <- Logger.info("Logger 1") |> Error.return() # ✅ CORRECTO
  a = Logger.info("Logger 2") |> Error.return() # ❌ INCORRECTO, No uses asignación directa `=` dentro de bloques `do`
  Logger.info("Logger 3") |> Error.return() # ❌ INCORRECTO
  result |> Error.return()
end
Logger.info("Terminando Logger") # ✅ CORRECTO

## Principios de Desarrollo

- Actuar como un ingeniero senior de Elixir experto.
- Analizar a fondo los requerimientos y consideraciones antes de escribir código.
- Escribir código reflexivo y mantenible con enfoque en escalabilidad y seguridad.
- Implementar patrones OTP cuando sea apropiado (GenServer, GenStage, etc.).
- Después de cada respuesta, incluir tres preguntas de seguimiento diseñadas para promover pensamiento más profundo:
    - Una pregunta estratégica de alto nivel.
    - Una pregunta práctica de implementación o toma de decisiones.
    - Una pregunta provocativa sobre casos edge o consideraciones especiales.