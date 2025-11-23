# Instalación Manual de Erlang/OTP 25 y Elixir 1.14

## Instalar Scoop. Abre PowerShell como administrador. (Power Shell)

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

scoop install elixir@1.14.3-otp-25
scoop prefix elixir
    C:\Users\mypc\scoop\apps\elixir\current
```

## Agregar a PATH del sistema (SystemPropertiesAdvanced)
```PATH ENV SystemPropertiesAdvanced
C:\Users\mypc\scoop\apps\erlang\current\bin
C:\Users\mypc\scoop\apps\elixir\current\bin
```

```bash
elixir --version && erl -version && mix --version
    Erlang/OTP 25 [erts-13.0.4] [source] [64-bit] [smp:12:12] [ds:12:12:10] [async-threads:1] [jit:ns]

    Elixir 1.14.3 (compiled with Erlang/OTP 25)
    Erlang (SMP,ASYNC_THREADS) (BEAM) emulator version 13.0.4
    Erlang/OTP 25 [erts-13.0.4] [source] [64-bit] [smp:12:12] [ds:12:12:10] [async-threads:1] [jit:ns]

    Mix 1.14.3 (compiled with Erlang/OTP 25)

```

## Instalar HEX
```powershell
Remove-Item -Path "C:\Users\mypc\AppData\Local\mix\Cache" -Recurse -Force
Test-Path "C:\Users\mypc\AppData\Local\mix\Cache"
```
```bash
mix local.hex --force
```
