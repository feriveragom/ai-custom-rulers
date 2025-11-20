#-- Setup listening SSL port...
#=====================================
listen 443 ssl http2;
listen [::]:443 ssl http2;

#-- Certificados for .albertcs.com domain...
#===========================================
ssl_certificate cert/albertcs.com.crt;
ssl_certificate_key cert/albertcs.com.key;

ssl_protocols TLSv1.2 TLSv1.1 TLSv1;