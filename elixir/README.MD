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

## Instalar ElixirLS v0.21.3 (última versión de la serie 0.21)
Clic derecho sobre la extension >> Install Specific Version...>> 0.21.3

## Settings para ElixirLS
```json
Ctrl + Shift + P >> Preferences: Open User Settings (JSON)
{
    "elixirLS.fetchDeps": true
}
```

## Contexto
✅ Instalado Elixir 1.14.3-otp-25 vía Scoop
✅ Creado wrapper elixir.ps1 (PowerShell → Bash)
✅ Reemplazado elixir.bat defectuoso
✅ Instalado Hex (mix local.hex --force)
✅ Instalado ElixirLS v0.21.3
✅ Parcheado extension.js con {shell: true}

Después de instalar Elixir con Scoop (`scoop install elixir@1.14.3-otp-25`), ElixirLS crashea porque `elixir.bat` no funciona en PowerShell (aunque sí funciona en Bash).

### PASO 1 ELIXIR: Crear wrapper PowerShell
Archivo: C:\Users\mypc\scoop\apps\elixir\current\bin\elixir.ps1
```bash
cat > "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.ps1" << 'EOF'
#!/usr/bin/env pwsh
# Wrapper para ejecutar elixir usando bash

$bashPath = "C:\Program Files\Git\bin\bash.exe"
$elixirPath = "/c/Users/mypc/scoop/apps/elixir/current/bin/elixir"

# Convertir argumentos Windows a formato Unix y escapar correctamente
$unixArgs = @()
foreach ($arg in $args) {
    if ($arg -match '^[A-Za-z]:\\') {
        # Convertir ruta Windows a Unix
        $converted = $arg -replace '^([A-Za-z]):\\', '/$1/' -replace '\\', '/'
        $unixArgs += "'$converted'"
    } elseif ($arg -match '\s|[()]') {
        # Escapar argumentos con espacios o paréntesis
        $escaped = $arg -replace "'", "'\\''"
        $unixArgs += "'$escaped'"
    } else {
        $unixArgs += $arg
    }
}

# Ejecutar con bash
$cmdLine = "$elixirPath " + ($unixArgs -join ' ')
& $bashPath -c $cmdLine
exit $LASTEXITCODE
EOF
```

### PASO 2 ELIXIR: Reemplazar elixir.bat
Archivo: C:\Users\mypc\scoop\apps\elixir\current\bin\elixir.bat
```bash
mv "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.bat" "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.bat.broken"

cat > "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.bat" << 'EOF'
@echo off
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "C:\Users\mypc\scoop\apps\elixir\current\bin\elixir.ps1" %*
EOF
```

### PASO 3 ELIXIR: Verificar funcionamiento
```shell
powershell -c "elixir --version"
```

### PASO 4 ElixirLS: Modificar language_server.bat de ElixirLS
```bash
cat > "C:/Users/mypc/.vscode/extensions/jakebecker.elixir-ls-0.13.0/elixir-ls-release/language_server.bat" << 'EOF'
@echo off & setlocal enabledelayedexpansion

IF EXIST "%APPDATA%\elixir_ls\setup.bat" (
    CALL "%APPDATA%\elixir_ls\setup.bat" > nul
)

SET ERL_LIBS=%~dp0;%ERL_LIBS%
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "C:\Users\mypc\scoop\apps\elixir\current\bin\elixir.ps1" --erl "+sbwt none +sbwtdcpu none +sbwtdio none" -e "ElixirLS.LanguageServer.CLI.main()"
EOF
```

### PASO 5 ElixirLS: Modificar debugger.bat de ElixirLS
```bash
cat > "C:/Users/mypc/.vscode/extensions/jakebecker.elixir-ls-0.13.0/elixir-ls-release/debugger.bat" << 'EOF'
@echo off & setlocal enabledelayedexpansion

IF EXIST "%APPDATA%\elixir_ls\setup.bat" (
    CALL "%APPDATA%\elixir_ls\setup.bat" > nul
)

SET ERL_LIBS=%~dp0;%ERL_LIBS%
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "C:\Users\mypc\scoop\apps\elixir\current\bin\elixir.ps1" --erl "+sbwt none +sbwtdcpu none +sbwtdio none" -e "ElixirLS.Debugger.CLI.main()"
EOF
```

### PASO 6 ElixirLS: Probar language_server.bat manualmente
```shell
powershell -c "& 'C:\Users\mypc\.vscode\extensions\jakebecker.elixir-ls-0.13.0\elixir-ls-release\language_server.bat'"
```

### PASO 7 ElixirLS: Parchear extension.js para agregar shell: true
#### Archivo: C:\Users\mypc\.vscode\extensions\jakebecker.elixir-ls-0.21.3\out\extension.js
#### Modificación: Agregar {shell:true} al spawn para Windows
```bash
sed -i 's/zp\.spawn(\([^,]*\),\([^,]*\),\([^)]*\))/zp.spawn(\1,\2,Object.assign({shell:true},\3))/g' extension.js
```