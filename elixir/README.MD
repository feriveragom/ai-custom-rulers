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
scoop bucket add versions && scoop install erlang@24.3.4.17 && scoop install elixir@1.14.5
```

### Verificar en consola recargada
```bash
elixir --version && erl -version
```

### Agregar a PATH del sistema
```bash
scoop prefix elixir
    C:\Users\mypc\scoop\apps\elixir\current

scoop prefix erlang
    C:\Users\mypc\scoop\apps\erlang\current
```

```PATH
C:\Users\mypc\scoop\apps\elixir\current\bin
C:\Users\mypc\scoop\apps\erlang\current\bin
```

```bash
elixir --version && erl -version
```
