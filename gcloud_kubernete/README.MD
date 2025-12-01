Instala gcloud CLI
	https://cloud.google.com/kubernetes-engine/docs/how-to/cluster-access-for-kubectl?hl=es-419

	Download the Google Cloud CLI installer.
		https://dl.google.com/dl/cloudsdk/channels/rapid/GoogleCloudSDKInstaller.exe?hl=es-419
		GoogleCloudSDKInstaller.exe

```bash
	Instale kubectl
		Google Cloud SDK Shell (Ejecutar como administrador)
			gcloud components install kubectl
			
	gcloud container clusters get-credentials cluster-alberto-qa --zone us-east1 --project alberto-qa

	Manejo de Perfiles (Switching)
		
		Opción A: Perfil Profesional (fernando.rivera@dox.cl)
			# 1. Cambiar usuario activo
			gcloud config set account fernando.rivera@dox.cl
			
			# 2. Cambiar proyecto activo (alberto-qa)
			gcloud config set project alberto-qa
			
			# 3. Actualizar credenciales de kubectl
			# Esto conecta kubectl al cluster 'cluster-alberto-qa' usando el usuario profesional
			gcloud container clusters get-credentials cluster-alberto-qa --zone us-east1 --project alberto-qa

		Opción B: Perfil Personal (feriveragom@gmail.com)
			# 1. Cambiar usuario activo
			gcloud config set account feriveragom@gmail.com
			
			# 2. Cambiar proyecto activo (billmate-ecosystem)
			gcloud config set project billmate-ecosystem

		Comandos de verificación
			gcloud auth list                  # Ver cuentas logueadas
			gcloud config list                # Ver configuración activa
			kubectl config current-context    # Ver a qué cluster apunta kubectl

		Actualizar componentes
			gcloud components update
			# Actualiza todos los componentes instalados del SDK de Google Cloud a la última versión disponible.
```