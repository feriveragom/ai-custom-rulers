## Instalar Scoop. Abre PowerShell como administrador. (Power Shell)

### Establecer la seguridad SSL/TLS manualmente para permitir la descarga del script de instalación.
```cmd
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Set-ExecutionPolicy RemoteSigned -Scope Process; Invoke-WebRequest -Uri 'https://get.scoop.sh' -UseBasicParsing | iex
```
### ¿Desea cambiar la directiva de ejecución?
```cmd
S
```

Instalando okteto via scoop: (Esto instalara la ultima version)
```shell
scoop install okteto
okteto version
```

Desinstalar okteto via scoop
```shell
Set-ExecutionPolicy RemoteSigned -Scope Process
scoop uninstall okteto
```

Instalando una version especifica de okteto via scoop:
```shell
scoop install okteto@2.27.4
okteto version
```