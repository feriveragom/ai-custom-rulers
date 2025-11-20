#-- Setup listening SSL port...
#=====================================
listen 443 ssl http2;
listen [::]:443 ssl http2;

#-- Certificados for .registronotarial.cl domain...
#===================================================
ssl_certificate cert/registronotarial.cl.crt;
ssl_certificate_key cert/registronotarial.cl.key;

ssl_protocols TLSv1.2 TLSv1.1 TLSv1;