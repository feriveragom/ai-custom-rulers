#-- Setup listening SSL port...
#=====================================
listen 443 ssl http2;
listen [::]:443 ssl http2;

#-- Certificados for .totalcheck.cl domain...
#============================================
ssl_certificate cert/totalcheck.cl.crt;
ssl_certificate_key cert/totalcheck.cl.key;

ssl_protocols TLSv1.2 TLSv1.1 TLSv1;