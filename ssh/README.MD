Generación de una nueva clave SSH y adición al agente SSH

https://docs.github.com/es/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent

Acceder a .../.ssh y borrar su contenido

	1- Install OpenSSH on your device.
		Install OpenSSH on Microsoft Windows
			Download and run the Git for Windows installer.
				https://git-scm.com/download/win
					Git-2.45.1-64-bit
					ssh -V

	2- Start the SSH service.
		ps -a | grep ssh-agent
		eval $(ssh-agent)

	3- Create an SSH key pair.
		#ssh-keygen -t ed25519 -b 4096 -C "fernando.rivera@dox.cl" -f ~/.ssh/ssh_dell_pc
		ssh-keygen -t ed25519 -b 4096 -C "fernando.rivera@dox.cl" -f ~/.ssh/ssh_lenovo_black_pc

	4- Add your key to the SSH agent.
		#ssh-add ~/.ssh/ssh_dell_pc
		ssh-add ~/.ssh/ssh_lenovo_black_pc
		To ensure the correct SSH key is used when connecting to Bitbucket, update or create your SSH configuration file (~/.ssh/config) with the following settings:
			echo "Host bitbucket.org" >> ~/.ssh/config
			echo " AddKeysToAgent yes" >> ~/.ssh/config
			#echo " IdentityFile ~/.ssh/ssh_dell_pc" >> ~/.ssh/config
			echo " IdentityFile ~/.ssh/ssh_lenovo_black_pc" >> ~/.ssh/config

	5- Provide Bitbucket Cloud with your public key.
		https://bitbucket.org/account/settings/ssh-keys/
			Add key
				#Label: dellpc-dark
				Label: lenovo_dark-dark
				Key: Copy the contents of the public key file and paste the key				

	6- Check that your SSH authentication works.
		ssh -T git@bitbucket.org
			The authenticity of host 'bitbucket.org (104.192.141.1)' can't be established.
			ECDSA key fingerprint is SHA256:FC73VB6C4OQLSCrjEayhMp9UMxS97caD/Yyi2bhW/J0.
			Are you sure you want to continue connecting (yes/no)?
				yes
					Warning: Permanently added 'bitbucket.org,104.192.141.1' (ECDSA) to the list of known hosts.
					authenticated via ssh key.
					You can use git to connect to Bitbucket. Shell access is disabled

	7- Open Git Bash here
		git clone git@bitbucket.org:teamdox/<<bbprojectname>>.git