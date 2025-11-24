## Instalar Scoop. Abre PowerShell como administrador. (Power Shell)

### Establecer la seguridad SSL/TLS manualmente para permitir la descarga del script de instalación.
```cmd
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Set-ExecutionPolicy RemoteSigned -Scope Process; Invoke-WebRequest -Uri 'https://get.scoop.sh' -UseBasicParsing | iex
```
### ¿Desea cambiar la directiva de ejecución?
```cmd
S
```