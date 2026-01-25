# Primeros Pasos en Reverse Engineering

Cuando solo disponemos de un ejecutable, es común pensar que resulta imposible obtener el código fuente original. Sin embargo, existen diversas herramientas que nos permiten analizar y comprender el funcionamiento del programa mediante ingeniería inversa.

## Herramientas Fundamentales

### 1. objdump - Análisis Estático

`objdump` es una utilidad que permite desensamblar binarios y obtener el código ensamblador.

```bash
# Desensamblar todo el ejecutable
objdump -D ejecutable

# Desensamblar solo las secciones de código
objdump -d ejecutable

# Mostrar también el código fuente si hay símbolos de debug
objdump -S ejecutable
```

**Características:**
- **Análisis estático**: Examina el código sin ejecutarlo
- Funciona tanto con archivos objeto (`.o`) como con ejecutables completos
- Muestra el desensamblado puro, sin capacidad de análisis dinámico
- Útil para obtener una visión general rápida del código

**Limitaciones:**
- No permite seguir el flujo de ejecución en tiempo real
- Dificulta el análisis de código ofuscado o empaquetado
- Requiere conocimientos sólidos de ensamblador para interpretarlo

### 2. GDB - Depuración Dinámica

GDB (GNU Debugger) permite analizar el programa durante su ejecución, ofreciendo capacidades mucho más avanzadas.

```bash
# Iniciar GDB con un ejecutable
gdb ./ejecutable

# Comandos básicos útiles
# disassemble main          - Desensamblar la función main
# break *0x400500          - Establecer breakpoint en dirección
# run                      - Ejecutar el programa
# step / stepi             - Avanzar paso a paso
# info registers           - Ver el estado de los registros
# x/20x $rsp              - Examinar memoria
```

**Ventajas:**
- **Análisis dinámico**: Observa el comportamiento real del programa
- Permite establecer breakpoints y examinar el estado en cualquier momento
- Inspección de memoria, registros y stack en tiempo real
- Modificación de valores durante la ejecución para testing

### 3. GDB con Plugins - Mejora Visual

Existen varios plugins que mejoran significativamente la experiencia con GDB:

#### GEF (GDB Enhanced Features)
```bash
# Instalación
bash -c "$(curl -fsSL https://gef.blah.cat/sh)"
```

#### PEDA (Python Exploit Development Assistance)
```bash
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit
```

#### pwndbg
```bash
git clone https://github.com/pwndbg/pwndbg
cd pwndbg
./setup.sh
```

**Mejoras que ofrecen:**
- Interfaz visual mejorada con colores y formato
- Visualización automática de registros, stack y código
- Comandos adicionales para exploiting y análisis
- Detección automática de vulnerabilidades comunes
- Mejor navegación por el código desensamblado

## Otras Herramientas Complementarias

### Ghidra
Decompilador open-source de la NSA que intenta reconstruir código similar a C desde el binario.

### radare2 / Cutter
Framework de reverse engineering con capacidades avanzadas de análisis estático y dinámico.

### IDA Pro / IDA Free
Desensamblador y debugger profesional (la versión Free es gratuita pero limitada).

## Flujo de Trabajo Recomendado

1. **Análisis inicial**: Usar `file` y `strings` para información básica
2. **Análisis estático**: Revisar con `objdump` o Ghidra la estructura general
3. **Análisis dinámico**: Depurar con GDB (con plugins) para entender el flujo de ejecución
4. **Documentación**: Anotar hallazgos y reconstruir la lógica del programa

## Recursos Adicionales

- [GDB Cheat Sheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
- [x86-64 Assembly Reference](https://www.felixcloutier.com/x86/)
- [Reverse Engineering for Beginners](https://beginners.re/)

---

**Nota**: Estas técnicas deben usarse únicamente en software que tengas derecho a analizar, respetando siempre las licencias y leyes aplicables.
