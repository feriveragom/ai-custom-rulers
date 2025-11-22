# Instalación Manual de Erlang/OTP 25 y Elixir 1.14

## Instalar Scoop. Abre PowerShell como administrador.	(Power Shell)

### Establecer la seguridad SSL/TLS manualmente para permitir la descarga del script de instalación.
```cmd
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Set-ExecutionPolicy RemoteSigned -Scope Process; Invoke-WebRequest -Uri 'https://get.scoop.sh' -UseBasicParsing | iex
```
### ¿Desea cambiar la directiva de ejecución?
```cmd
S
```

## Instalar Erlang/OTP 25 y Elixir 1.14
```bash
scoop --version
scoop uninstall erlang && scoop uninstall elixir
scoop bucket add versions && scoop install erlang@25.0.4
scoop prefix erlang
    C:\Users\mypc\scoop\apps\erlang\current
```

```PATH ENV
C:\Users\mypc\scoop\apps\erlang\current\bin
```

## Compilar elixir con Erlang/OTP 25 desde el código fuente
```bash
scoop install make
cd /c/Users/mypc/scoop/apps/elixir && git clone https://github.com/elixir-lang/elixir.git current && cd current && git checkout v1.14.0-rc.0
cd /c/Users/mypc/scoop/apps/elixir/current && make clean
cd /c/Users/mypc/scoop/apps/elixir/current && make compile

Nota: No usar -> scoop install elixir@1.14.0-rc.0 porque instala Elixir 1.14 compilado con Erlang/OTP 23
Nota: No usar -> scoop install elixir@1.14 porque instala Elixir 1.14 compilado con Erlang/OTP 24
```

### Agregar a PATH del sistema
```bash
scoop prefix elixir
    C:\Users\mypc\scoop\apps\elixir\current
```

```PATH ENV
C:\Users\mypc\scoop\apps\elixir\current\bin
```

```bash
elixir --version && erl -version
    Erlang/OTP 25 [erts-13.0.4] [source] [64-bit] [smp:12:12] [ds:12:12:10] [async-threads:1] [jit:ns]
    Elixir 1.14.0-rc.0 (6449239) (compiled with Erlang/OTP 25)
    Erlang (SMP,ASYNC_THREADS) (BEAM) emulator version 13.0.4
```
