
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
# Navegar al directorio de la extensión
cd C:/Users/mypc/.vscode/extensions/jakebecker.elixir-ls-0.21.3/out

# Aplicar el parche con sed
sed -i 's/zp\.spawn(\([^,]*\),\([^,]*\),\([^)]*\))/zp.spawn(\1,\2,Object.assign({shell:true},\3))/g' extension.js
```

## Romper/Reparar la extension ElixirLS, renombrando el archivo `elixir.ps1`:
```bash
# ROMPER - Renombrar elixir.ps1
mv "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.ps1" "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.ps1.BROKEN"

# REPARAR - Restaurar elixir.ps1
mv "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.ps1.BROKEN" "C:/Users/mypc/scoop/apps/elixir/current/bin/elixir.ps1"
```