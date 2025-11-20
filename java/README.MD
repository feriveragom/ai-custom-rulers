# JDK

## JDK 8 (versión LTS, e.g., 8u402):
Descarga directa aproximada: https://github.com/adoptium/temurin8-binaries/releases/download/jdk8u402-b06/OpenJDK8U-jdk_x64_windows_hotspot_8u402b06.zip
```bash
"D:\java_tools\jdk8\bin\java" -version
```

## JDK 21 (versión LTS, e.g., 21.0.4):
Descarga directa aproximada: https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.4%2B7/OpenJDK21U-jdk_x64_windows_hotspot_21.0.4_7.zip
```bash
"D:\java_tools\jdk21\bin\java" -version
```

# Maven
URL directa: https://downloads.apache.org/maven/maven-3/3.9.11/binaries/apache-maven-3.9.11-bin.zip
```bash
"D:\java_tools\maven-3.9.11\bin\mvn" -version
```

# Agrega PATH del sistema (JAVA ENV PATH === JAVA VSCode PATH)
```
D:\java_tools\maven-3.9.11\bin\
D:\java_tools\jdk8\bin\ <-- ENV PATH Para proyectos que usan JDK 8>
// D:\java_tools\jdk21\bin\ <-- ENV PATH Para proyectos que usan JDK 21>
```

# VSCode (JAVA ENV PATH === JAVA VSCode Settings)
Ctrl + Shift + P > "Preferences: Open User Settings (JSON)"

VSCode PATH Para proyectos que usan JDK 8>
```json
{
  "java.home": "D:\\java_tools\\jdk8"
}
```

VSCode PATH Para proyectos que usan JDK 21>
```json
{
  "java.home": "D:\\java_tools\\jdk21"
}
```

## Para debuguear este proyecto Spring Boot en local, necesitas extensiones:
```
1- Extension Pack for Java: Te da todo: Java Language Support, Debugger, Maven
    vscjava.vscode-java-pack
2- Spring Boot Extension Pack: - Para reconocer y ejecutar Spring Boot
    vmware.vscode-boot-dev-pack
3- Lombok Annotations Support for VS Code: Reconoce las anotaciones de Lombok (@Data, @Getter, @Setter, etc.)
    vscjava.vscode-lombok
```

# comprador_boleta_informativa: 
    Java 8 + Maven 3.9.11 + Spring Boot 2.7.14

## Servicios requeridos:
```
    RabbitMQ - localhost:5672 (usuario: guest, contraseña: guest)
    Alberto Service - localhost:8085 (autenticación)
    IdAuto Core Service - localhost:9001 (servicio core)
    IdAuto Captcha - localhost:8081 (validación de captcha)
```

## Comandos útiles:
- Para compilar y empaquetar el proyecto
```bash
mvn clean install
```

- Para compilar y empaquetar el proyecto sin ejecutar tests
```bash
mvn clean install -DskipTests
```

- Para compilar y empaquetar el proyecto sin ejecutar tests y sin construir la imagen Docker
```bash
mvn clean install -DskipTests -Ddockerfile.skip=true
```

- Para ejecutar la aplicación directamente desde Maven
```bash
mvn spring-boot:run
```

- Salidas
```
  - Acceder a la app en el navegador: http://localhost:8080
  - Ver logs en tiempo real en la terminal
  - Hacer cambios en el código y se recargan automáticamente
```

- Para consultar el estado del servicio por consola una vez levantado
```bash
curl http://localhost:8080/cl/idabi/info
```

- Respuesta esperada:
```json
{"service":"comprador_boleta_informativa","active_profile":"Local","status":"Started OK"}
```
