
---

## 🧠 ¿El kernel devuelve siempre un *file descriptor*?

### 🐧 Linux / UNIX

✅ **SÍ**

En Linux, **el kernel siempre devuelve un file descriptor (fd)** para interactuar con recursos del kernel.

Ejemplos:

```c
int fd = open("file.txt", O_RDONLY);
int fd = socket(AF_INET, SOCK_STREAM, 0);
int fd = accept(sockfd, NULL, NULL);
```

Todos devuelven:

```
fd → índice a la tabla de descriptores del proceso
```

Ese `fd` apunta internamente a:

```
task_struct
  → files_struct
      → fdtable
          → struct file
              → inode / socket / pipe / device
```

👉 **Archivos, sockets, pipes, dispositivos = TODO es fd**

Por eso funciona:

```c
read(fd, ...)
write(fd, ...)
close(fd)
```

en absolutamente todo.

---

### 🪟 Windows

❌ **NO**

Windows **NO devuelve file descriptors**.

Devuelve **HANDLEs**.

Ejemplo WinSock:

```c
SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
```

Ese `SOCKET`:

❌ No es un fd
❌ No funciona con `ReadFile()`
❌ No entra en el modelo POSIX

Internamente es:

```
SOCKET == typedef UINT_PTR
```

y apunta a un **objeto del Object Manager** del kernel.

---

## 🔩 ¿Qué devuelve realmente Windows?

Windows devuelve **HANDLEs a objetos kernel**:

| Recurso | Devuelve                 |
| ------- | ------------------------ |
| Archivo | `HANDLE`                 |
| Proceso | `HANDLE`                 |
| Thread  | `HANDLE`                 |
| Socket  | `SOCKET` (especializado) |

Internamente:

```
HANDLE
  → Object Manager
      → Kernel Object
```

Los sockets son **objetos distintos** a los archivos.

---

## ⚠️ Punto CLAVE (muy importante)

En Windows:

* `SOCKET` ≠ `HANDLE`
* `HANDLE` ≠ `fd`
* `read()` ≠ `recv()`
* `close()` ≠ `closesocket()`

Por eso esto **NO funciona**:

```c
ReadFile(socket, ...);   // ❌
CloseHandle(socket);    // ❌
```

Debes usar:

```c
recv(s, ...);
closesocket(s);
```

---

## 🧬 Comparación directa

### Linux

```
Aplicación
  ↓
syscall
  ↓
kernel
  ↓
fd (int)
```

### Windows

```
Aplicación
  ↓
Win32 / WinSock
  ↓
kernel
  ↓
HANDLE / SOCKET
```

---

##  Resume

| Sistema | ¿fd? | ¿Handle? | ¿Todo es lo mismo? |
| ------- | ---- | -------- | ------------------ |
| Linux   | ✅    | ❌        | ✅                  |
| Windows | ❌    | ✅        | ❌                  |

---

## chuleta

> En Linux, el file descriptor es la abstracción universal de acceso al kernel.
> En Windows, el acceso se realiza mediante handles a objetos kernel especializados, rompiendo la unificación clásica de UNIX.
